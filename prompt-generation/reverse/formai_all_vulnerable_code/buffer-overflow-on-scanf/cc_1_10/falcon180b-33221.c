//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100000

typedef struct node{
    char data[MAX_SIZE];
    int freq;
    struct node *next;
}Node;

Node *table[256];

void createTable(){
    int i;
    for(i=0;i<256;i++){
        table[i] = NULL;
    }
}

void insert(char *str){
    int i,j;
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->freq = 1;
    strcpy(newnode->data,str);
    newnode->next = NULL;

    if(table[str[0]] == NULL){
        table[str[0]] = newnode;
    }
    else{
        Node *temp = table[str[0]];
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void encode(FILE *fp){
    char ch;
    int i,j;
    Node *temp;

    createTable();

    while((ch=getc(fp))!=EOF){
        if(ch == '\n'){
            insert("\n");
        }
        else{
            insert(&ch);
        }
    }

    rewind(fp);

    while((ch=fgetc(fp))!=EOF){
        if(ch == '\n'){
            printf("\\n");
        }
        else{
            temp = table[(int)ch];
            while(temp!= NULL){
                printf("%c",temp->data[0]);
                temp = temp->next;
            }
        }
    }
}

void decode(FILE *fp){
    char ch;
    int i,j;
    Node *temp;

    createTable();

    while((ch=getc(fp))!=EOF){
        if(ch == '\\'){
            ch = getc(fp);

            if(ch == 'n'){
                printf("\n");
            }
            else{
                temp = table[(int)ch];
                while(temp!= NULL){
                    printf("%c",temp->data[0]);
                    temp = temp->next;
                }
            }
        }
        else{
            temp = table[(int)ch];
            while(temp!= NULL){
                printf("%c",temp->data[0]);
                temp = temp->next;
            }
        }
    }
}

int main(){
    FILE *fp;
    char choice;

    fp = fopen("file.txt","r");
    if(fp == NULL){
        printf("File not found\n");
        exit(0);
    }

    printf("Enter 'e' to encode and 'd' to decode: ");
    scanf("%c",&choice);

    switch(choice){
        case 'e':
            encode(fp);
            break;
        case 'd':
            decode(fp);
            break;
        default:
            printf("Invalid choice\n");
            exit(0);
    }

    fclose(fp);
    return 0;
}