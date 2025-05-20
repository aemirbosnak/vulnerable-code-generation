//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Function to search for a node with a given value in a linked list
int search_linked_list(struct node* head, int value) {
    // Initialize a pointer to the head of the list
    struct node* current = head;

    // Iterate through the list until we find a node with the given value or reach the end of the list
    while (current != NULL) {
        // Check if the current node's data is equal to the given value
        if (current->data == value) {
            // If it is, return the index of the current node
            return current->data;
        }

        // Move on to the next node in the list
        current = current->next;
    }

    // If we reach the end of the list without finding a node with the given value, return -1
    return -1;
}

int main() {
    // Create a linked list with 5 nodes
    struct node* head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = malloc(sizeof(struct node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(struct node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(struct node));
    head->next->next->next->data = 4;
    head->next->next->next->next = malloc(sizeof(struct node));
    head->next->next->next->next->data = 5;

    // Search for a node with the value 3 in the linked list
    int index = search_linked_list(head, 3);

    // Print the index of the node if it was found
    if (index != -1) {
        printf("Found node with value %d at index %d\n", index, index);
    } else {
        printf("Node with value 3 not found\n");
    }

    // Free the memory allocated for the linked list
    free(head);
    return 0;
}