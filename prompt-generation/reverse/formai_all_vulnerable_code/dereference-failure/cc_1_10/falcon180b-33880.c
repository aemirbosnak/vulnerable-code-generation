//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a new node at the beginning of the list
void push(Node** headRef, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to add a new node at the end of the list
void append(Node** headRef, int newData) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    Node* last = *headRef;

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }

    while (last->next!= NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Function to add a new node at a specific position in the list
void insertAtPosition(Node** headRef, int newData, int position) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;

    Node* temp = *headRef;

    if (position == 0) {
        newNode->next = temp;
        *headRef = newNode;
        return;
    }

    for (int i = 0; i < position - 1; i++) {
        if (temp!= NULL) {
            temp = temp->next;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to remove a node from the list
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;

    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    Node* next = temp->next;
    free(temp);
    temp = next;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Add nodes to the list
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);

    // Print the list
    printf("List after adding nodes:\n");
    printList(head);

    // Insert a node at position 2
    insertAtPosition(&head, 25, 2);

    // Print the list
    printf("List after inserting a node at position 2:\n");
    printList(head);

    // Delete a node with value 20
    deleteNode(&head, 20);

    // Print the list
    printf("List after deleting a node with value 20:\n");
    printList(head);

    return 0;
}