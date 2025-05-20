//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to add a node to the end of the list
void addNode(Node** head, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a node with the given data
Node* searchList(Node* head, char* data) {
    Node* current = head;
    while (current!= NULL) {
        if (strcmp(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, "apple");
    addNode(&head, "banana");
    addNode(&head, "cherry");

    // Search for a node
    Node* result = searchList(head, "banana");

    // Print the result
    if (result!= NULL) {
        printf("Found node with data: %s\n", result->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}