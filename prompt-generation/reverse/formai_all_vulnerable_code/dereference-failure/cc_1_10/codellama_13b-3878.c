//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for a linked list
struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

// Function to create a new linked list
struct LinkedList* create_linked_list() {
    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to insert a new node at the end of the linked list
void insert_node(struct LinkedList* list, int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    // If list is empty, insert the new node at the head
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Function to search for a node in the linked list
struct Node* search_node(struct LinkedList* list, int data) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a node from the linked list
void delete_node(struct LinkedList* list, int data) {
    struct Node* current = list->head;
    struct Node* previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
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

// Function to print the linked list
void print_linked_list(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList* list = create_linked_list();
    insert_node(list, 1);
    insert_node(list, 2);
    insert_node(list, 3);
    insert_node(list, 4);
    insert_node(list, 5);

    print_linked_list(list);

    struct Node* node = search_node(list, 3);
    if (node != NULL) {
        printf("Node found: %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    delete_node(list, 2);
    print_linked_list(list);

    return 0;
}