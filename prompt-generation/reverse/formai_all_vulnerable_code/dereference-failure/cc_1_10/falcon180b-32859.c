//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for new node
    newNode->data = data; // Add data to the node
    newNode->next = NULL; // Initialize next pointer to NULL
    if (*head == NULL) { // If the list is empty, set the head to the new node
        *head = newNode;
    } else { // Otherwise, traverse the list until the end and add the new node
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a node recursively
Node* searchRecursive(Node* head, int data) {
    if (head == NULL) { // Base case: empty list
        return NULL;
    } else if (head->data == data) { // Base case: found the node
        return head;
    } else { // Recursive case: continue searching in the rest of the list
        return searchRecursive(head->next, data);
    }
}

int main() {
    Node* head = NULL; // Initialize head to NULL
    addNode(&head, 1); // Add nodes to the list
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    int searchData = 3; // Data to search for
    Node* result = searchRecursive(head, searchData); // Call search function

    if (result!= NULL) {
        printf("Node with data %d found!\n", result->data);
    } else {
        printf("Node with data %d not found.\n", searchData);
    }

    return 0;
}