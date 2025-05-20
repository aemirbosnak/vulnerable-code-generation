//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: modular
// Searching algorithm example program in a modular style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the node of a linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define a function to create a new node
Node* create_node(int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Define a function to insert a new node into the linked list
void insert_node(Node **head, int data) {
    Node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Define a function to search for a node with a given data
Node* search_node(Node *head, int data) {
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Define a function to print the linked list
void print_list(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create a linked list
    Node *head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    // Search for a node with data = 3
    Node *node = search_node(head, 3);
    if (node != NULL) {
        printf("Node with data = 3 found at address %p\n", node);
    } else {
        printf("Node with data = 3 not found\n");
    }

    // Print the linked list
    print_list(head);

    return 0;
}