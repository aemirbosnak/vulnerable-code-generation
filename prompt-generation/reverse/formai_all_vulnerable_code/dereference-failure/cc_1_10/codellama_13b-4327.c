//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: thoughtful
// C Data structures visualization example program

#include <stdio.h>
#include <stdlib.h>

// Linked list node
struct Node {
    int data;
    struct Node *next;
};

// Linked list
struct LinkedList {
    struct Node *head;
    struct Node *tail;
};

// Create a new linked list
struct LinkedList* createLinkedList() {
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Insert a node into the linked list
void insertNode(struct LinkedList *list, int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Print the linked list
void printLinkedList(struct LinkedList *list) {
    struct Node *node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Free the linked list
void freeLinkedList(struct LinkedList *list) {
    struct Node *node = list->head;
    while (node != NULL) {
        struct Node *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

int main() {
    // Create a linked list
    struct LinkedList *list = createLinkedList();

    // Insert nodes into the linked list
    insertNode(list, 1);
    insertNode(list, 2);
    insertNode(list, 3);
    insertNode(list, 4);
    insertNode(list, 5);

    // Print the linked list
    printLinkedList(list);

    // Free the linked list
    freeLinkedList(list);

    return 0;
}