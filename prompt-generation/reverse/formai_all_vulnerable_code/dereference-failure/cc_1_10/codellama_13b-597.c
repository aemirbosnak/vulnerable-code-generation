//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: puzzling
// C Data structures visualization program in a puzzling style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node in the linked list
void insertNode(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Driver code
int main() {
    // Initialize the head of the linked list
    struct Node* head = NULL;

    // Insert nodes in the linked list
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);

    // Print the linked list
    printList(head);

    // Free the linked list
    freeList(head);

    return 0;
}