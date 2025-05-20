//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: sophisticated
// Linked list operations example program

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct node {
    int data;
    struct node *next;
};

// Linked list structure
struct list {
    struct node *head;
    struct node *tail;
};

// Function to create a new linked list
struct list* create_list() {
    struct list *new_list = malloc(sizeof(struct list));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

// Function to insert a new node at the beginning of the list
void insert_beginning(struct list *list, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

// Function to insert a new node at the end of the list
void insert_end(struct list *list, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

// Function to print the linked list
void print_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to remove a node from the linked list
void remove_node(struct list *list, int value) {
    struct node *current = list->head;
    struct node *previous = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    struct list *list = create_list();
    insert_beginning(list, 1);
    insert_beginning(list, 2);
    insert_end(list, 3);
    insert_end(list, 4);
    print_list(list);
    remove_node(list, 3);
    print_list(list);
    return 0;
}