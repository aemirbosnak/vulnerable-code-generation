//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: light-weight
/*
 * A simple C Linked list operations example program
 */

#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node {
    int data;
    struct Node *next;
};

// Linked list structure
struct LinkedList {
    struct Node *head;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert a node at the beginning of the list
void insertNode(struct LinkedList *list, struct Node *node) {
    node->next = list->head;
    list->head = node;
}

// Insert a node at the end of the list
void insertNodeAtEnd(struct LinkedList *list, struct Node *node) {
    struct Node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

// Delete a node from the list
void deleteNode(struct LinkedList *list, int data) {
    struct Node *current = list->head;
    struct Node *previous = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Print the list
void printList(struct LinkedList *list) {
    struct Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create a new list
    struct LinkedList list;
    list.head = NULL;

    // Insert nodes
    insertNode(&list, createNode(1));
    insertNodeAtEnd(&list, createNode(2));
    insertNodeAtEnd(&list, createNode(3));
    insertNodeAtEnd(&list, createNode(4));

    // Delete a node
    deleteNode(&list, 2);

    // Print the list
    printList(&list);

    return 0;
}