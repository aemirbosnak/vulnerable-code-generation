//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: realistic
// Program to perform operations on a linked list

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node* create_node(int data) {
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
    node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(node **head, int data) {
    node *new_node = create_node(data);
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// Function to insert a node after a given node in the linked list
void insert_after(node **head, int data, int position) {
    node *new_node = create_node(data);
    node *current = *head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

// Function to delete a node from the linked list
void delete(node **head, int position) {
    node *current = *head;
    node *previous = NULL;
    for (int i = 0; i < position; i++) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}

// Function to display the linked list
void display(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a new linked list with three nodes
    node *head = create_node(1);
    insert_at_end(&head, 2);
    insert_at_end(&head, 3);

    // Insert a node at the beginning of the linked list
    insert_at_beginning(&head, 0);

    // Insert a node after the first node in the linked list
    insert_after(&head, 4, 1);

    // Delete the third node in the linked list
    delete(&head, 2);

    // Display the linked list
    display(head);

    // Free the memory allocated for the linked list
    node *current = head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}