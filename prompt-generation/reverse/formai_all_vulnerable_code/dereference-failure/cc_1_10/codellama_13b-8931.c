//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: multivariable
// Linked List Operations Example Program

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the list
void insert_beginning(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a new node at the end of the list
void insert_end(struct Node **head_ref, int new_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    struct Node *last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to insert a new node after a given node
void insert_after(struct Node **head_ref, int new_data, int node_data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;

    struct Node *current = *head_ref;
    while (current->data != node_data) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Function to delete a node with a given data value
void delete_node(struct Node **head_ref, int node_data) {
    struct Node *current = *head_ref;
    struct Node *previous = NULL;

    while (current->data != node_data) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        *head_ref = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

// Function to print the list
void print_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Node *head = NULL;

    // Insert nodes at the beginning of the list
    insert_beginning(&head, 5);
    insert_beginning(&head, 10);
    insert_beginning(&head, 15);

    // Insert nodes at the end of the list
    insert_end(&head, 20);
    insert_end(&head, 25);
    insert_end(&head, 30);

    // Insert nodes after a given node
    insert_after(&head, 18, 15);
    insert_after(&head, 13, 10);
    insert_after(&head, 17, 15);

    // Delete a node with a given data value
    delete_node(&head, 25);

    // Print the list
    print_list(head);

    return 0;
}