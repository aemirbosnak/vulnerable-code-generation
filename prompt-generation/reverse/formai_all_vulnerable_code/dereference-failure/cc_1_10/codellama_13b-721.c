//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: sophisticated
/*
 * Linked list operations example program in a sophisticated style
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
    struct Node *tail;
};

// Create a new node
struct Node *newNode(int data) {
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Create a new linked list
struct LinkedList *newLinkedList() {
    struct LinkedList *list = malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Insert a node at the beginning of the linked list
void insertAtBeginning(struct LinkedList *list, int data) {
    struct Node *node = newNode(data);
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL) {
        list->tail = node;
    }
}

// Insert a node at the end of the linked list
void insertAtEnd(struct LinkedList *list, int data) {
    struct Node *node = newNode(data);
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Insert a node after a specific node in the linked list
void insertAfter(struct LinkedList *list, int data, int after) {
    struct Node *node = newNode(data);
    struct Node *temp = list->head;
    while (temp != NULL) {
        if (temp->data == after) {
            node->next = temp->next;
            temp->next = node;
            return;
        }
        temp = temp->next;
    }
}

// Delete a node from the linked list
void deleteNode(struct LinkedList *list, int data) {
    struct Node *temp = list->head;
    if (temp != NULL && temp->data == data) {
        list->head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == data) {
            struct Node *node = temp->next;
            temp->next = node->next;
            free(node);
            return;
        }
        temp = temp->next;
    }
}

// Display the linked list
void display(struct LinkedList *list) {
    struct Node *temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList *list = newLinkedList();
    insertAtBeginning(list, 1);
    insertAtEnd(list, 2);
    insertAfter(list, 3, 1);
    insertAfter(list, 4, 2);
    display(list);
    deleteNode(list, 3);
    display(list);
    return 0;
}