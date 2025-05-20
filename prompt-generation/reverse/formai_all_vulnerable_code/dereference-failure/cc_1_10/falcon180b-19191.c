//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to add a node at the end of the list
void append(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    Node* last = *headRef;
    if (last == NULL) {
        push(headRef, newData);
        return;
    }
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to add a node at the specified position
void addAtPosition(Node** headRef, int newData, int pos) {
    Node* newNode = createNode(newData);
    Node* temp = *headRef;
    if (pos == 1) {
        push(headRef, newData);
        return;
    }
    for (int i = 1; i < pos - 1 && temp!= NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node with the given data
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void display(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    push(&head, 5);
    push(&head, 7);
    push(&head, 3);
    display(head);
    append(&head, 9);
    display(head);
    addAtPosition(&head, 2, 2);
    display(head);
    deleteNode(&head, 7);
    display(head);
    return 0;
}