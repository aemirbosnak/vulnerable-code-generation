//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: curious
/*
* C Linked list operations example program in a curious style
*/

#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Create a new node
Node* create_node(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Add a node to the end of the list
void add_node(Node **head, int data) {
    Node *new_node = create_node(data);
    Node *current = *head;
    if (*head == NULL) {
        *head = new_node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Remove a node from the list
void remove_node(Node **head, int data) {
    Node *current = *head;
    Node *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Print the list
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    // Add some nodes to the list
    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    // Print the list
    print_list(head);

    // Remove a node from the list
    remove_node(&head, 3);

    // Print the list again
    print_list(head);

    return 0;
}