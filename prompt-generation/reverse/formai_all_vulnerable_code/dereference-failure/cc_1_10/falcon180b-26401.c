//Falcon-180B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void addNode(Node** head, int data);
void printList(Node* head);
void deleteList(Node** head);

// Main function
int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Delete the list
    deleteList(&head);

    // Print the list again (should be empty)
    printf("\nList after deletion:\n");
    printList(head);

    return 0;
}

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
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
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the list
void deleteList(Node** head) {
    Node* temp = *head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}