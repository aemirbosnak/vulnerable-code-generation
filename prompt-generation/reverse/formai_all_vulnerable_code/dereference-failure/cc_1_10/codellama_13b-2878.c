//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: future-proof
/*
 * Future-proof Linked List operations example program
 */

#include <stdio.h>
#include <stdlib.h>

// Define a node struct
struct node {
    int data;
    struct node *next;
};

// Define a list struct
struct list {
    struct node *head;
    struct node *tail;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create a new list
struct list* create_list() {
    struct list *new_list = malloc(sizeof(struct list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

// Function to add a node to the list
void add_node(struct list *list, int data) {
    struct node *new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }
    list->tail = new_node;
}

// Function to traverse the list
void traverse_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Function to free the list
void free_list(struct list *list) {
    struct node *current = list->head;
    struct node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    // Create a list
    struct list *my_list = create_list();

    // Add nodes to the list
    add_node(my_list, 1);
    add_node(my_list, 2);
    add_node(my_list, 3);

    // Traverse the list
    traverse_list(my_list);

    // Free the list
    free_list(my_list);

    return 0;
}