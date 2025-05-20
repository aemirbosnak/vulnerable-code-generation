//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: expert-level
/*
 * linked_list.c
 *
 *  Created on: Nov 21, 2022
 *      Author: Expert
 */

#include <stdio.h>
#include <stdlib.h>

// Linked list node
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Linked list
typedef struct {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

// Function to create a new node
node_t* new_node(int data) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the beginning of the list
void insert_front(list_t *list, int data) {
    node_t *node = new_node(data);
    node->next = list->head;
    list->head = node;
    list->size++;
}

// Function to insert a new node at the end of the list
void insert_back(list_t *list, int data) {
    node_t *node = new_node(data);
    if (list->tail == NULL) {
        list->head = list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// Function to insert a new node at a specific position
void insert_at(list_t *list, int data, int pos) {
    if (pos < 0 || pos > list->size) {
        printf("Invalid position\n");
        return;
    }
    node_t *node = new_node(data);
    if (pos == 0) {
        insert_front(list, data);
    } else if (pos == list->size) {
        insert_back(list, data);
    } else {
        node_t *curr = list->head;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
        list->size++;
    }
}

// Function to delete a node from the list
void delete_node(list_t *list, int pos) {
    if (pos < 0 || pos >= list->size) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 0) {
        node_t *node = list->head;
        list->head = list->head->next;
        free(node);
    } else {
        node_t *curr = list->head;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        node_t *node = curr->next;
        curr->next = node->next;
        free(node);
    }
    list->size--;
}

// Function to traverse the list and print the nodes
void traverse_list(list_t *list) {
    node_t *curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    list_t list;
    list.head = list.tail = NULL;
    list.size = 0;

    // Insert elements in the list
    insert_front(&list, 1);
    insert_back(&list, 2);
    insert_at(&list, 3, 1);
    insert_at(&list, 4, 2);

    // Traverse the list
    traverse_list(&list);

    // Delete a node from the list
    delete_node(&list, 2);

    // Traverse the list again
    traverse_list(&list);

    return 0;
}