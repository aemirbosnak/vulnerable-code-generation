//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000
#define ELEMENT_SIZE 50

typedef struct node{
    char data[ELEMENT_SIZE];
    struct node *next;
}Node;

Node *head=NULL;

void addElement(Node **head,char *data){
    Node *newnode=(Node*)malloc(sizeof(Node));
    strcpy(newnode->data,data);
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    Node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void removeElement(Node **head,char *data){
    Node *temp=*head;
    if(temp!=NULL && strcmp(temp->data,data)==0){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && strcmp(temp->data,data)!=0){
        temp=temp->next;
    }
    if(temp==NULL){
        return;
    }
    Node *newnode=temp->next;
    temp->next=newnode->next;
    free(newnode);
}

void displayList(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        printf("%s\n",temp->data);
        temp=temp->next;
    }
}

int main(){
    head=NULL;
    addElement(&head,"Hello");
    addElement(&head,"World");
    displayList(head);
    removeElement(&head,"Hello");
    displayList(head);
    return 0;
}