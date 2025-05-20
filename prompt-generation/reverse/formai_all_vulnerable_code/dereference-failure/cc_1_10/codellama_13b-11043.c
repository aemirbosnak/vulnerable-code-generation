//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: secure
// Linked list operations example program in a secure style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure for the linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define a function to create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory for new node\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Define a function to insert a node at the beginning of the list
void insert_node(node_t **head, int data) {
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Define a function to delete a node from the list
void delete_node(node_t **head, int data) {
    node_t *current = *head;
    node_t *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

// Define a function to print the list
void print_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Initialize the list
    node_t *head = NULL;

    // Insert nodes into the list
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    // Print the list
    print_list(head);

    // Delete a node from the list
    delete_node(&head, 3);

    // Print the list again
    print_list(head);

    // Free the memory
    while (head != NULL) {
        node_t *current = head;
        head = head->next;
        free(current);
    }

    return 0;
}