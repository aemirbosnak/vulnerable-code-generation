//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: energetic
/*
 * Unique C Linked List Operations Example Program
 *
 * Description: This program demonstrates some unique linked list operations in C.
 */

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a node at a given position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(struct Node** head) {
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end of the list
void deleteFromEnd(struct Node** head) {
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Function to delete a node from a given position
void deleteFromPosition(struct Node** head, int position) {
    struct Node* current = *head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list with nodes containing values 1 to 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Insert a node at the beginning
    insertAtBeginning(&head, 0);

    // Insert a node at the end
    insertAtEnd(&head, 6);

    // Insert a node at a given position
    insertAtPosition(&head, 7, 4);

    // Delete a node from the beginning
    deleteFromBeginning(&head);

    // Delete a node from the end
    deleteFromEnd(&head);

    // Delete a node from a given position
    deleteFromPosition(&head, 4);

    // Print the linked list
    printList(head);

    return 0;
}