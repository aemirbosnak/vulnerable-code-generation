//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struct for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void addNode(Node** head, int data);
void printList(Node* head);

int main() {
    // Initialize head pointer
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    // Print the list
    printList(head);

    return 0;
}

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to add a node to the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // Traverse the list to find the end
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Add the new node to the end
    temp->next = newNode;
    newNode->next = NULL;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}