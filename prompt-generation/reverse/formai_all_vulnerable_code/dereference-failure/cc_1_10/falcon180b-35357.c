//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);
void reverseList(Node** head);

int main() {
    Node* head = NULL;

    // Add nodes
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print original list
    printf("Original List:\n");
    printList(head);

    // Reverse list
    reverseList(&head);

    // Print reversed list
    printf("\nReversed List:\n");
    printList(head);

    // Delete node with value 3
    deleteNode(&head, 3);

    // Print list after deletion
    printf("\nList after deleting node with value 3:\n");
    printList(head);

    return 0;
}

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with the given value
void deleteNode(Node** head, int data) {
    Node* temp = *head;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }

    Node* prev = temp->next;
    temp->next = NULL;
    free(temp);
    prev->next = temp->next;
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to reverse the list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;

    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}