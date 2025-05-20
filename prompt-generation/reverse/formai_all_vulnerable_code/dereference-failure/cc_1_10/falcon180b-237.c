//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNodeAtBeginning(node** head, int data){
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertNodeAtEnd(node** head, int data){
    node* newNode = createNode(data);
    node* temp = *head;
    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
    }
    else{
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertNodeAtPosition(node** head, int data, int position){
    node* newNode = createNode(data);
    node* temp = *head;
    if(position == 1){
        newNode->next = *head;
        *head = newNode;
    }
    else{
        for(int i=1; i<position-1 && temp!= NULL; i++){
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Position out of range\n");
        }
        else{
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteNode(node** head, int data){
    node* temp = *head;
    node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
        free(temp);
    }
    else{
        while(temp!= NULL && temp->data!= data){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Element not found\n");
        }
        else{
            prev->next = temp->next;
            free(temp);
        }
    }
}

void displayNode(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    node* head = NULL;
    insertNodeAtBeginning(&head, 10);
    insertNodeAtEnd(&head, 20);
    insertNodeAtEnd(&head, 30);
    insertNodeAtPosition(&head, 15, 2);
    displayNode(head);
    deleteNode(&head, 20);
    displayNode(head);
    return 0;
}