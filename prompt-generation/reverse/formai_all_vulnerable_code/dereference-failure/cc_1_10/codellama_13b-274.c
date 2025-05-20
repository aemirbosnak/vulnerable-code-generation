//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: creative
/*
 * Linked List operations example program in a creative style
 *
 * This program demonstrates the basic operations on a linked list:
 * 1. Creating a new linked list
 * 2. Adding new elements to the list
 * 3. Accessing and modifying elements in the list
 * 4. Deleting elements from the list
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>

/* Struct for a linked list node */
typedef struct node {
    int data;
    struct node *next;
} node_t;

/* Function to create a new linked list */
node_t* create_list() {
    return NULL;
}

/* Function to add a new element to the end of the list */
void add_element(node_t **list, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        node_t *current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

/* Function to access and modify an element in the list */
void modify_element(node_t **list, int index, int data) {
    if (index < 0) {
        return;
    }

    node_t *current = *list;
    for (int i = 0; i < index; i++) {
        if (current == NULL) {
            return;
        }
        current = current->next;
    }

    if (current != NULL) {
        current->data = data;
    }
}

/* Function to delete an element from the list */
void delete_element(node_t **list, int index) {
    if (index < 0) {
        return;
    }

    node_t *current = *list;
    node_t *previous = NULL;
    for (int i = 0; i < index; i++) {
        if (current == NULL) {
            return;
        }
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        *list = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

/* Function to print the contents of the list */
void print_list(node_t *list) {
    node_t *current = list;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    /* Create a new linked list */
    node_t *list = create_list();

    /* Add some elements to the list */
    add_element(&list, 1);
    add_element(&list, 2);
    add_element(&list, 3);
    add_element(&list, 4);
    add_element(&list, 5);

    /* Access and modify an element in the list */
    modify_element(&list, 2, 10);

    /* Print the contents of the list */
    print_list(list);

    /* Delete an element from the list */
    delete_element(&list, 3);

    /* Print the contents of the list again */
    print_list(list);

    return 0;
}