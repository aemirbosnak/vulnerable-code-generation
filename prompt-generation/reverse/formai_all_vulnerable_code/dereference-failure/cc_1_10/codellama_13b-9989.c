//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: visionary
/*
 * A visionary C data structures visualization example program
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for the nodes
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Struct for the linked list
typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

// Function to create a new node
Node* newNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new linked list
LinkedList* newLinkedList() {
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to add a node to the end of the linked list
void addNode(LinkedList *list, int data) {
    Node *node = newNode(data);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Function to print the linked list
void printLinkedList(LinkedList *list) {
    Node *node = list->head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to free the memory allocated to the linked list
void freeLinkedList(LinkedList *list) {
    Node *node = list->head;
    while (node != NULL) {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
    free(list);
}

int main() {
    LinkedList *list = newLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);
    printLinkedList(list);
    freeLinkedList(list);
    return 0;
}