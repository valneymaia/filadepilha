#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"
#include "fila.h"


struct fila {
    Pilha *p1;
    Pilha *p2;
};


Fila * criarFila()
{
    Fila *fila = malloc(sizeof(Fila));

    if(fila != NULL) {
        Pilha *p1 = criarPilha();
        Pilha *p2 = criarPilha();

        fila->p1 = p1;
        fila->p2 = p2;
    }

    return fila;
}

struct aluno teste(struct aluno *dados)
{
    struct aluno novo;
    strcpy(novo.nome, dados->nome);
    novo.matricula = dados->matricula;
    return novo;
}


void inserirFila(Fila *fila, struct aluno dados)
{
  struct aluno aux;
    if(fila == NULL)
        return;

    if(topo(fila) == NULL) {
        inserirPilha(fila->p1, dados);
        return;
    }

    while(!vazia(fila->p1)) {
        inserirPilha(fila->p2, *(remover(fila->p1)));
    }

    inserirPilha(fila->p1, dados);

    while(!vazia(fila->p2)) {
        aux = teste(acessar(fila->p2));
        inserirPilha(fila->p1, aux);
        remover(fila->p2);
    }
}


void imprimeFila(Fila *fila)
{
    if(vazia(fila->p1)) {
        printf("Pilha 1 vazia\n");
    }
    else
        imprimePilha(fila->p1);
   /*if(vazia(fila->p2))
        printf("Pilha 2 vazia\n");
    else
        printf("pilha dois \n");
        imprimePilha(fila->p2);
    printf("\n");*/
}


struct aluno *  topo(Fila *fila)
{
    if(vazia(fila->p1))
        return NULL;

    return acessar(fila->p1);
}


struct aluno * pop(Fila *fila)
{
    if(vazia(fila->p1))
        return NULL;

    return remover(fila->p1);
}


void destruirFila(Fila *fila)
{
    if(!vazia(fila->p1))
        destruir(fila->p1);
    if(!vazia(fila->p2))
        destruir(fila->p2);
}
