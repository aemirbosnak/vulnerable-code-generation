//Falcon-180B DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node_t {
    void *data;
    struct node_t *next;
} node_t;

// Linked list structure
typedef struct list_t {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

// Function to create a new node
node_t *node_create(void *data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Error: Unable to allocate memory for node.\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node to the end of the linked list
void list_add(list_t *list, void *data) {
    node_t *node = node_create(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// Function to remove a node from the linked list
void list_remove(list_t *list, void *data) {
    node_t *prev = NULL;
    node_t *curr = list->head;
    while (curr!= NULL) {
        if (curr->data == data) {
            if (prev == NULL) {
                list->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            if (list->tail == curr) {
                list->tail = prev;
            }
            free(curr);
            list->size--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Function to print the linked list
void list_print(list_t *list) {
    node_t *curr = list->head;
    while (curr!= NULL) {
        printf("%p -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    list_t list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    list_add(&list, "Hello");
    list_add(&list, "World");

    printf("Linked List:\n");
    list_print(&list);

    list_remove(&list, "Hello");

    printf("\nLinked List after removing 'Hello':\n");
    list_print(&list);

    return 0;
}