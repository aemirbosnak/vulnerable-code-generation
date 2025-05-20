//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: satisfied
/*
 * Linked list operations example program in C
 *
 * This program demonstrates how to create and manipulate
 * a linked list in C.
 */

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node at a given position
void deleteNode(Node **head, int position) {
    Node *current = *head;
    if (position == 0) {
        *head = current->next;
        free(current);
        return;
    }
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    Node *head = NULL;
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtEnd(&head, 4);

    // Display the linked list
    displayList(head);

    // Delete a node at position 2
    deleteNode(&head, 2);

    // Display the linked list again
    displayList(head);

    return 0;
}