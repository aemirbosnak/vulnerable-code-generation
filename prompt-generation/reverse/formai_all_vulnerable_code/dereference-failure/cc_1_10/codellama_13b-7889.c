//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: systematic
/*
 * A unique C data structures visualization example program
 *
 * This program shows how to use a doubly-linked list to store and visualize
 * data structures in a systematic way.
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Structures to represent a node and a list
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
} list_t;

// Function to create a new node
node_t* create_node(int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Function to insert a new node into the list
void insert_node(list_t *list, node_t *node) {
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}

// Function to delete a node from the list
void delete_node(list_t *list, node_t *node) {
    if (node == list->head) {
        list->head = node->next;
    } else if (node == list->tail) {
        list->tail = node->prev;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
}

// Function to print the list
void print_list(list_t *list) {
    node_t *curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Initialize the list
    list_t list;
    list.head = NULL;
    list.tail = NULL;

    // Insert nodes into the list
    insert_node(&list, create_node(1));
    insert_node(&list, create_node(2));
    insert_node(&list, create_node(3));

    // Print the list
    print_list(&list);

    // Delete a node from the list
    delete_node(&list, list.head->next);

    // Print the list again
    print_list(&list);

    return 0;
}