//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** head, int data){
    Node* newNode = createNode(data);
    Node* temp = *head;
    if(*head == NULL){
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void printList(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void deleteNode(Node** head, int data){
    Node* temp = *head;
    Node* prev = NULL;
    if(temp!= NULL && temp->data == data){
        *head = temp->next;
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

int searchNode(Node* head, int data){
    Node* temp = head;
    while(temp!= NULL){
        if(temp->data == data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main(){
    Node* head = NULL;
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    addNode(&head, 20);
    printList(head);
    deleteNode(&head, 10);
    printList(head);
    int result = searchNode(head, 15);
    if(result == 1){
        printf("Element found\n");
    }else{
        printf("Element not found\n");
    }
    return 0;
}