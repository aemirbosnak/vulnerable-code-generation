//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** headRef, int newData){
    Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

void deleteNode(Node** headRef, int key){
    Node* temp = *headRef, *prev;
    if(temp!= NULL && temp->data == key){
        *headRef = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void searchNode(Node* head, int key){
    Node* current = head;
    while(current!= NULL){
        if(current->data == key)
            printf("%d found\n",key);
        current = current->next;
    }
    if(current == NULL)
        printf("%d not found\n",key);
}

void printList(Node* node){
    while(node!= NULL){
        printf("%d ",node->data);
        node = node->next;
    }
}

int main(){
    Node* head = NULL;
    insertNode(&head,1);
    insertNode(&head,2);
    insertNode(&head,3);
    insertNode(&head,4);
    printList(head);
    searchNode(head,3);
    deleteNode(&head,2);
    printList(head);
    return 0;
}