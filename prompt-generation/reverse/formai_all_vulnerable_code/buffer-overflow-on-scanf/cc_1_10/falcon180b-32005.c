//Falcon-180B DATASET v1.0 Category: File handling ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

typedef struct Node{
    char data[MAX_SIZE];
    struct Node* next;
}Node;

Node* createNode(char data[]){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, char data[]){
    Node* newNode = createNode(data);
    Node* temp = *head;
    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
    }
    else{
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

int main(){
    FILE* fp;
    char filename[20];
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if(fp == NULL){
        printf("File not found\n");
        exit(0);
    }
    char ch;
    Node* head = NULL;
    while((ch = fgetc(fp))!= EOF){
        if(isalpha(ch)){
            char word[MAX_SIZE];
            int i = 0;
            while(isalpha(ch)){
                word[i++] = ch;
                ch = fgetc(fp);
            }
            word[i] = '\0';
            addNode(&head, word);
        }
    }
    fclose(fp);
    printList(head);
    return 0;
}