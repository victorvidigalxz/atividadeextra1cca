#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[100];
    int codigo;
    char status[20]; // "disponivel" ou "emprestado"
} Livro;

void emprestarLivro(Livro *l) {
    if (strcmp(l->status, "disponivel") == 0) {
        strcpy(l->status, "emprestado");
        printf("Livro \"%s\" emprestado com sucesso!\n", l->titulo);
    } else {
        printf("Livro \"%s\" ja esta emprestado.\n", l->titulo);
    }
}

// Função extra: devolve o livro, alterando o status de volta para "disponivel"
void devolverLivro(Livro *l) {
    if (strcmp(l->status, "emprestado") == 0) {
        strcpy(l->status, "disponivel");
        printf("Livro \"%s\" devolvido com sucesso!\n", l->titulo);
    } else {
        printf("Livro \"%s\" ja esta disponivel.\n", l->titulo);
    }
}

// Função auxiliar para exibir os dados do livro
void exibirLivro(Livro l) {
    printf("Codigo: %d | Titulo: %s | Autor: %s | Status: %s\n",
           l.codigo, l.titulo, l.autor, l.status);
}

int main() {
    // Criação de um livro para o mini-sistema
    Livro livro1 = {"O Senhor dos Aneis", "J.R.R. Tolkien", 101, "disponivel"};

    printf("=== Estado antes do emprestimo ===\n");
    exibirLivro(livro1);

    emprestarLivro(&livro1);

    printf("\n=== Estado depois do emprestimo ===\n");
    exibirLivro(livro1);

    printf("\n=== Devolvendo o livro ===\n");
    devolverLivro(&livro1);
    exibirLivro(livro1);

    return 0;
}
