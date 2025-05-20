//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the linked list structure
typedef struct list {
    Node* head;
} List;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(List* list, int data) {
    Node* newNode = createNode(data);
    Node* temp = list->head;

    // If the list is empty, set the new node as the head
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    // Traverse the list until the end is reached
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Set the next pointer of the last node to the new node
    temp->next = newNode;
}

// Function to print the list
void printList(List* list) {
    Node* temp = list->head;

    // Traverse the list and print each node's data
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    List* myList = (List*) malloc(sizeof(List));
    myList->head = NULL;

    // Add some nodes to the list
    addNode(myList, 1);
    addNode(myList, 2);
    addNode(myList, 3);

    // Print the list
    printList(myList);

    // Free the memory allocated for the list and its nodes
    free(myList->head);
    free(myList);

    return 0;
}