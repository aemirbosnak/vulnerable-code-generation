//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void printList(Node* head);
void addNode(Node** head, int data);
void deleteNode(Node** head, int data);
void reverseList(Node** head);

int main() {
    Node* head = NULL;

    // Create nodes and add to list
    head = createNode(1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print list
    printf("Original list:\n");
    printList(head);

    // Reverse list
    reverseList(&head);

    // Print reversed list
    printf("\nReversed list:\n");
    printList(head);

    // Delete node with value 3
    deleteNode(&head, 3);

    // Print list after deletion
    printf("\nList after deleting node with value 3:\n");
    printList(head);

    return 0;
}

// Function to create a new node with given data
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

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
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
    newNode->next = NULL;
}

// Function to delete a node with given data
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

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to reverse the list
void reverseList(Node** head) {
    Node* current = *head;
    Node* next;
    Node* prev = NULL;

    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}