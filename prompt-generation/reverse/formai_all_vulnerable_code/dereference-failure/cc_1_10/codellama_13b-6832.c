//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: configurable
// Linked list operations example program

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Linked list structure
typedef struct list {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

// Create a new linked list
list_t *create_list() {
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Add a new node to the end of the linked list
void add_node(list_t *list, int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// Remove the node at the front of the linked list
int remove_node(list_t *list) {
    if (list->head == NULL) {
        return -1;
    }
    int data = list->head->data;
    node_t *node = list->head;
    list->head = node->next;
    free(node);
    list->size--;
    return data;
}

// Print the linked list
void print_list(list_t *list) {
    node_t *node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Test the linked list operations
int main() {
    list_t *list = create_list();
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    add_node(list, 4);
    print_list(list);
    remove_node(list);
    print_list(list);
    return 0;
}