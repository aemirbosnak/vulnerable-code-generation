//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void createNode(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node* temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addNode(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node* temp = *head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    struct Node* prev = temp->next;
    free(temp);
    temp = prev;
}

void display(struct Node* head){
    struct Node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    createNode(&head, 10);
    createNode(&head, 20);
    createNode(&head, 30);
    createNode(&head, 40);
    createNode(&head, 50);
    display(head);
    addNode(&head, 60);
    display(head);
    deleteNode(&head, 30);
    display(head);
    deleteNode(&head, 60);
    display(head);
    deleteNode(&head, 50);
    display(head);
    deleteNode(&head, 20);
    display(head);
    deleteNode(&head, 10);
    display(head);
    return 0;
}