//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: random
/*
 * C Database Simulation Example Program
 *
 * This program simulates a database by storing and retrieving data from a
 * linked list. It demonstrates the use of a linked list to store data and
 * provides a simple interface for adding, removing, and retrieving data.
 */

#include <stdio.h>
#include <stdlib.h>

// Struct for a linked list node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node
Node *create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a new node to the linked list
void add_node(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to remove a node from the linked list
void remove_node(Node **head, int data) {
    Node *current = *head;
    Node *previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to retrieve a node from the linked list
Node *get_node(Node *head, int data) {
    Node *current = head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    return current;
}

// Function to print the linked list
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a new linked list
    Node *head = NULL;

    // Add some nodes to the linked list
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    // Remove a node from the linked list
    remove_node(&head, 3);

    // Retrieve a node from the linked list
    Node *node = get_node(head, 2);
    printf("Node with data 2: %d\n", node->data);

    // Print the linked list
    print_list(head);

    return 0;
}