//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in a linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of a linked list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* currNode = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (currNode->next!= NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

// Function to print a linked list
void printList(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Add nodes to the linked list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    // Reverse the linked list
    Node* prevNode = NULL;
    Node* currNode = head;
    while (currNode!= NULL) {
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;

    // Print the reversed linked list
    printf("\nReversed Linked List:\n");
    printList(head);

    return 0;
}