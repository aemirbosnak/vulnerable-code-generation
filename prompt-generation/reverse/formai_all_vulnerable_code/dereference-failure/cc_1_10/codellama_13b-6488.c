//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: realistic
/*
 * A linked list example program
 *
 * This program demonstrates basic linked list operations
 * in a realistic style.
 */

#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// A function to create a new linked list node
struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// A function to add a new node to the end of the linked list
void addNode(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = createNode(data);

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Find the last node in the list
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Add the new node to the end of the list
    current->next = newNode;
}

// A function to remove a node from the linked list
void removeNode(struct Node** head, int data) {
    // If the list is empty, return
    if (*head == NULL) {
        return;
    }

    // Find the node to be removed
    struct Node* current = *head;
    struct Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    // If the node was found, remove it
    if (current != NULL) {
        // If the node is the head, set the new head
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }

        // Free the node
        free(current);
    }
}

// A function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Initialize the list
    struct Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the list
    printList(head);

    // Remove a node from the list
    removeNode(&head, 3);

    // Print the list again
    printList(head);

    return 0;
}