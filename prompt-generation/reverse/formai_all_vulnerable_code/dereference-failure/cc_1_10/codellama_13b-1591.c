//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertBegin(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a node at a specific position
void insertAt(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int i = 1;
    while (i < pos) {
        current = current->next;
        i++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a node from the beginning of the list
void deleteBegin(struct Node** head) {
    struct Node* current = *head;
    *head = current->next;
    free(current);
}

// Function to delete a node from the end of the list
void deleteEnd(struct Node** head) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);
}

// Function to delete a node from a specific position
void deleteAt(struct Node** head, int pos) {
    struct Node* current = *head;
    struct Node* previous = NULL;
    int i = 1;
    while (i < pos) {
        previous = current;
        current = current->next;
        i++;
    }
    previous->next = current->next;
    free(current);
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
    // Creating a linked list
    struct Node* head = createNode(1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);
    insertBegin(&head, 0);

    // Printing the linked list
    printList(head);

    // Deleting nodes from the linked list
    deleteBegin(&head);
    deleteEnd(&head);
    deleteAt(&head, 3);

    // Printing the linked list
    printList(head);

    return 0;
}