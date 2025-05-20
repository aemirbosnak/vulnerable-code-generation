//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a node structure for our linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the end of the linked list
void addNode(Node** head, char data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create an empty linked list
    Node* head = NULL;

    // Add some nodes to the linked list
    addNode(&head, 'a');
    addNode(&head, 'b');
    addNode(&head, 'c');

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    // Reverse the linked list
    Node* prev = NULL;
    Node* curr = head;
    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;

    // Print the reversed linked list
    printf("\nReversed List:\n");
    printList(head);

    return 0;
}