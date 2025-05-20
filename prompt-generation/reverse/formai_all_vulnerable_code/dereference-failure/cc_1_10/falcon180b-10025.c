//Falcon-180B DATASET v1.0 Category: Memory management ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insertNode(Node *head, int data){
    Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return head;
    }
    Node *temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(Node *head){
    Node *temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void deleteList(Node *head){
    Node *temp = head;
    while(temp!= NULL){
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}

int main(){
    Node *head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);
    printList(head);
    deleteList(head);
    return 0;
}