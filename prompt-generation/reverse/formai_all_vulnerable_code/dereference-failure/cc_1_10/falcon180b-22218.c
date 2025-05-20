//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node with data and a pointer to the next node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a linked list with a head pointer
typedef struct LinkedList {
    Node* head;
} LinkedList;

// Create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append a node to the end of the linked list
void append(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Print the contents of the linked list
void printList(LinkedList* list) {
    Node* current = list->head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList list;
    list.head = NULL;

    // Append some nodes to the linked list
    append(&list, 1);
    append(&list, 2);
    append(&list, 3);

    // Print the contents of the linked list
    printList(&list);

    // Free the memory used by the linked list
    Node* current = list.head;
    while (current!= NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}