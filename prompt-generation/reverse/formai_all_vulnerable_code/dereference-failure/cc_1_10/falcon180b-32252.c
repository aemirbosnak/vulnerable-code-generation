//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

int main() {
    Node* head = NULL;

    // Insert nodes
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Print list
    printf("Original list:\n");
    printList(head);

    // Delete nodes
    deleteNode(&head, 3);
    deleteNode(&head, 5);

    // Print list
    printf("\nList after deleting nodes 3 and 5:\n");
    printList(head);

    return 0;
}

// Create a new node with given data
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

// Insert a new node with given data at the beginning of the list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Delete a node with given data from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Print the list
void printList(Node* head) {
    Node* curr = head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}