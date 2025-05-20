//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    Node* last = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
    } else {
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = NULL;
    }
}

void prepend(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

void deleteNode(Node **headRef, int key) {
    Node* temp = *headRef, *prev;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next; 
        free(temp);            
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    append(&head, 1);
    prepend(&head, 0);
    append(&head, 2);
    printList(head);
    deleteNode(&head, 1);
    printList(head);
    return 0;
}