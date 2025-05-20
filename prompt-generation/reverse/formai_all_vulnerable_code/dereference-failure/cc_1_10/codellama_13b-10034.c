//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a function to allocate memory for a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Define a function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Define a function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Define a function to insert a node at a given position in the list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Define a function to delete a node at the beginning of the list
void deleteAtBeginning(struct Node** head) {
    struct Node* current = *head;
    *head = current->next;
    free(current);
}

// Define a function to delete a node at the end of the list
void deleteAtEnd(struct Node** head) {
    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}

// Define a function to delete a node at a given position in the list
void deleteAtPosition(struct Node** head, int position) {
    struct Node* current = *head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Define a function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning of the list
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);

    // Insert nodes at the end of the list
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);

    // Insert nodes at a given position in the list
    insertAtPosition(&head, 7, 2);
    insertAtPosition(&head, 8, 4);

    // Delete nodes at the beginning of the list
    deleteAtBeginning(&head);
    deleteAtBeginning(&head);

    // Delete nodes at the end of the list
    deleteAtEnd(&head);
    deleteAtEnd(&head);

    // Delete nodes at a given position in the list
    deleteAtPosition(&head, 2);
    deleteAtPosition(&head, 4);

    // Print the linked list
    printList(head);

    return 0;
}