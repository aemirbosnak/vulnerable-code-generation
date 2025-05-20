//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: surprised
/*
 * Program: Linked List Example Program
 * Description: This program demonstrates basic linked list operations in C.
 * Author: [Your Name]
 * Date: [Current Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct node {
    int data;
    struct node *next;
};

// Linked list structure
struct linked_list {
    struct node *head;
};

// Function to create a new linked list
struct linked_list* create_linked_list() {
    struct linked_list *list = malloc(sizeof(struct linked_list));
    list->head = NULL;
    return list;
}

// Function to insert a new node at the end of the linked list
void insert_node(struct linked_list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to traverse the linked list
void traverse_list(struct linked_list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to delete a node from the linked list
void delete_node(struct linked_list *list, int data) {
    struct node *current = list->head;
    struct node *prev = NULL;

    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            list->head = current->next;
        }
        free(current);
    }
}

int main() {
    struct linked_list *list = create_linked_list();
    insert_node(list, 10);
    insert_node(list, 20);
    insert_node(list, 30);
    traverse_list(list);
    delete_node(list, 20);
    traverse_list(list);
    free(list);
    return 0;
}