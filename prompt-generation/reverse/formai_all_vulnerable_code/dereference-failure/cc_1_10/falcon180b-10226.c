//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Linked list structure
Node* linkedList = NULL;

// Function to add a node to the linked list
void addNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    if (linkedList == NULL) {
        linkedList = newNode;
    } else {
        Node* temp = linkedList;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a node in the linked list
Node* searchNode(char* data) {
    Node* temp = linkedList;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    // Add nodes to the linked list
    addNode("apple");
    addNode("banana");
    addNode("cherry");
    addNode("date");

    // Search for a node
    Node* result = searchNode("banana");
    if (result!= NULL) {
        printf("Found node with data: %s\n", result->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}