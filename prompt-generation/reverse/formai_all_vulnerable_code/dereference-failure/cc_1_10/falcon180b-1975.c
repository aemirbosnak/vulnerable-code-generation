//Falcon-180B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the linked list
void addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Add some nodes to the linked list
    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    // Remove a node from the linked list
    Node* temp = head;
    while (temp->next!= NULL) {
        if (temp->next->data == 2) {
            Node* nodeToRemove = temp->next;
            temp->next = temp->next->next;
            free(nodeToRemove);
            break;
        }
        temp = temp->next;
    }

    // Print the updated linked list
    printf("\nLinked List after removing node with data 2:\n");
    printList(head);

    // Free the memory allocated for the linked list
    while (head!= NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}