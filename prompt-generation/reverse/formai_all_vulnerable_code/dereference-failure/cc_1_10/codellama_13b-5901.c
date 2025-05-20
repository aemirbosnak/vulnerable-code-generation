//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: imaginative
/*
 * Linked List Operations Example Program
 *
 * In this program, we will demonstrate how to perform various linked list operations in C.
 * We will create a linked list of integers, and perform various operations on it, such as insertion, deletion, traversal, and sorting.
 */

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node **head_ref, int data) {
    Node *node = createNode(data);
    node->next = *head_ref;
    *head_ref = node;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node **head_ref, int data) {
    Node *node = createNode(data);
    Node *current = *head_ref;
    if (current == NULL) {
        *head_ref = node;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
}

// Function to delete a node from the linked list
void deleteNode(Node **head_ref, int data) {
    Node *current = *head_ref;
    Node *previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Data not found in the linked list\n");
        return;
    }
    if (previous == NULL) {
        *head_ref = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

// Function to traverse the linked list
void traverse(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to sort the linked list
void sort(Node **head_ref) {
    Node *current = *head_ref;
    Node *previous = NULL;
    while (current != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        return;
    }
    previous->next = NULL;
    while (previous != NULL) {
        current = previous->next;
        previous->next = current->next;
        current->next = current->next->next;
        previous = previous->next;
    }
}

int main() {
    Node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    traverse(head);
    deleteNode(&head, 30);
    traverse(head);
    sort(&head);
    traverse(head);
    return 0;
}