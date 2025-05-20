//Code Llama-13B DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node to the linked list
void addNode(struct Node** head, int data) {
    // Allocate memory for the new node
    struct Node* newNode = malloc(sizeof(struct Node));
    // Add the data to the node
    newNode->data = data;
    // If the head pointer is NULL, the list is empty
    if (*head == NULL) {
        // Make the new node the head of the list
        *head = newNode;
    } else {
        // Find the last node in the list
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        // Add the new node to the end of the list
        last->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

// Driver code
int main() {
    // Initialize the head pointer to NULL
    struct Node* head = NULL;
    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    // Print the list
    printList(head);
    return 0;
}