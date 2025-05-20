//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node with given data
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

// Add a node at the beginning of the list
void push(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Add a node at the end of the list
void append(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* last = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
}

// Add a node at a specific position in the list
void addAtPosition(Node** headRef, int data, int pos) {
    Node* newNode = createNode(data);
    Node* temp = *headRef;
    if (pos == 0) {
        newNode->next = temp;
        *headRef = newNode;
        return;
    }
    for (int i = 0; i < pos - 1 && temp!= NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node with given data
void deleteNode(Node** headRef, int data) {
    Node* temp = *headRef;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// Display the contents of the list
void display(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    display(head);
    printf("\n");
    append(&head, 40);
    display(head);
    printf("\n");
    addAtPosition(&head, 15, 2);
    display(head);
    printf("\n");
    deleteNode(&head, 20);
    display(head);
    printf("\n");
    deleteNode(&head, 10);
    display(head);
    printf("\n");
    deleteNode(&head, 30);
    display(head);
    printf("\n");
    deleteNode(&head, 15);
    display(head);
    printf("\n");
    deleteNode(&head, 40);
    display(head);
    printf("\n");
    return 0;
}