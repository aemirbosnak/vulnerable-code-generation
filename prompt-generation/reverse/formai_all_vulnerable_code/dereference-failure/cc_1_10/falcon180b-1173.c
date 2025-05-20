//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void addNodeAtBeginning(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void addNodeAtEnd(struct Node** head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        (*head) = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void addNodeAtPosition(struct Node** head, int data, int position){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        (*head) = newNode;
        return;
    }
    if(position == 1){
        newNode->next = (*head);
        (*head) = newNode;
        return;
    }
    struct Node* temp = *head;
    for(int i=1;i<position-1;i++){
        if(temp->next!= NULL){
            temp = temp->next;
        }
        else{
            printf("Invalid position\n");
            exit(0);
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(struct Node** head, int data){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        (*head) = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void displayList(struct Node* head){
    while(head!= NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    struct Node* head = NULL;
    addNodeAtBeginning(&head, 5);
    addNodeAtEnd(&head, 10);
    addNodeAtPosition(&head, 3, 2);
    displayList(head);
    deleteNode(&head, 5);
    displayList(head);
    deleteNode(&head, 10);
    displayList(head);
    return 0;
}