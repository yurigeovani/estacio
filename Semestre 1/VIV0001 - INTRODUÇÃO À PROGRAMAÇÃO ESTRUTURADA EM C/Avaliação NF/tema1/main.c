#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    int matricula;
    char nome[100];
    int idade;
    char genero; // m or f or o
    float media;
    struct Aluno *next;
} Aluno;

// void adicionarAluno (){
//     char temp; // variavel temporaria pra limpar o buffer apos int e ENTER
//     Aluno aluno;
//     printf("MATRICULA: ");
//     scanf(" %i", &aluno.matricula);
// 	   scanf("%c", &temp); // instrucao temporaria pra limpar o buffer apos int e ENTER
//     printf("NOME: ");
//     scanf("%[^\n]", aluno.nome); // le todos os caracteres, exceto o \n
//     //fgets(aluno.nome, sizeof(aluno.nome), stdin);  // EVITAR! adiciona um \n apos string
//     printf("IDADE: ");
//     scanf(" %i", &aluno.idade);
//     printf("GENERO: ");
//     scanf(" %c", &aluno.genero);
//     printf("MEDIA: ");
//     scanf(" %f", &aluno.media);
    
//     printf("\nALUNO CADASTRADO COM SUCESSO!\n");
//     printf("\tMATRICULA: %i\n", aluno.matricula);
//     printf("\tNOME: %s\n", aluno.nome);
//     printf("\tIDADE: %i\n", aluno.idade);
//     printf("\tGENERO: %c\n", aluno.genero);
//     printf("\tMEDIA: %f\n", aluno.media);
// }

Aluno *criarAluno (int matricula, char nome[100], int idade, char genero, float media){
    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
    aluno -> matricula = matricula;
    aluno -> nome[100] = nome[100];
    aluno -> idade = idade;
    aluno -> genero = genero;
    aluno -> media = media;
    aluno -> next = NULL;
    return aluno;
}

Aluno *insertAluno (Aluno *head) {;
    char temp, nome[100], genero; // variavel temporaria pra limpar o buffer apos int e ENTER
    int matricula, idade;
    float media;
    printf("MATRICULA: ");
    scanf(" %i", &matricula);
    scanf("%c", &temp); // instrucao temporaria pra limpar o buffer apos int e ENTER
    printf("NOME: ");
    scanf("%[^\n]", nome); // le todos os caracteres, exceto o \n
    // fgets(aluno.nome, sizeof(aluno.nome), stdin);  // EVITAR! adiciona um \n apos string
    printf("IDADE: ");
    scanf(" %i", &idade);
    printf("GENERO: ");
    scanf(" %c", &genero);
    printf("MEDIA: ");
    scanf(" %f", &media);

    Aluno *novoAluno = criarAluno(matricula, nome, idade, genero, media);
    if(head == NULL) {
        head = novoAluno;
    } else {
        novoAluno -> next = head;
        head = novoAluno;
    }

    printf("Aluno adicionado\n");
    return head;
}

void listAluno (Aluno *head){
    if(head == NULL){
        printf("\nlista vazia");
        return;
    }
    Aluno *temp = head;
    printf("\nlinked list: ");
    while (temp != NULL)
    {
        printf("%d ", temp -> matricula);
        temp = temp-> next;
    }
    printf("\n");
}

void freeList(Aluno* head) {
    Aluno* temp = head;
    while (temp != NULL) {
        Aluno* nextAluno = temp->next;
        free(temp);
        temp = nextAluno;
    }
}


void listarOpcoes()
{
    printf("\n############## ESTACIO ACADEMY ##############");
    printf("\nInforme a opcao desejada:");
    printf("\n1) Cadastro de alunos");
    printf("\n2) Listagem de alunos");
    printf("\n3) Calculo de media");
    printf("\n4) Pesquisa de alunos");
    printf("\n5) Atualizacao de dados");
    printf("\n6) Remocao de alunos");
    printf("\n0) Sair");
}

char digitarOpcao (char opcao){
    printf("\nOpcao: ");
    scanf(" %c", &opcao);
    return opcao;
}

Aluno *selecionarOpcao(Aluno *head, char opcao) {
    switch (opcao) {
    case 49:
        head = insertAluno(head);
        break;
    case 50:
        listAluno(head);
        break;
    case 51:
        printf("\nop3");
        break;
    case 48:
        break;
    default:
        printf("\nSelecione uma opcao correta!!!");
        break;
    }
    return head;
}

int main()
{
    Aluno *head = NULL;
    char opcao;

    while (opcao!=48)
    {
        listarOpcoes();
        opcao = digitarOpcao(opcao);
        head = selecionarOpcao(head, opcao);
    }
    freeList(head);
    return 0;
}
