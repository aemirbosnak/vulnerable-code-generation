//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);

    // Print the list
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 10);

    // Print the list again
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node from the list
void deleteNode(Node** head, int data) {
    Node* prevNode = NULL;
    Node* currNode = *head;

    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (prevNode == NULL) {
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    free(currNode);
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}