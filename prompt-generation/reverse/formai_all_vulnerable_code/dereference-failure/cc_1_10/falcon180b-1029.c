//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* addNodeAtEnd(Node* head, int data){
    Node* newNode = createNode(data);
    Node* temp = head;
    if(head == NULL){
        head = newNode;
        return head;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* addNodeAtBeginning(Node* head, int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* addNodeAtPosition(Node* head, int data, int position){
    Node* newNode = createNode(data);
    Node* temp = head;
    if(position == 1){
        newNode->next = head;
        return newNode;
    }
    for(int i=0;i<position-2;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void deleteNode(Node* head, int data){
    Node* temp = head;
    Node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void displayList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    head = addNodeAtEnd(head,1);
    head = addNodeAtBeginning(head,0);
    head = addNodeAtPosition(head,2,3);
    displayList(head);
    deleteNode(head,0);
    displayList(head);
    deleteNode(head,2);
    displayList(head);
    return 0;
}