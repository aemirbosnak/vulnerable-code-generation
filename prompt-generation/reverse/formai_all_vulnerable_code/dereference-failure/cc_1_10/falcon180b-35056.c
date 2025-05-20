//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(struct Node** headRef, int newData) {
    struct Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to remove a node from the list by key
struct Node* removeNode(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp!= NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return head;

    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to search for a node in the list by key
struct Node* searchNode(struct Node* head, int key) {
    struct Node* current = head;

    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }

    return NULL;
}

// Function to print the list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Add nodes to the list
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    push(&head, 50);

    // Print the list
    printf("Original list: ");
    printList(head);

    // Remove a node from the list
    head = removeNode(head, 20);

    // Print the updated list
    printf("\nList after removing node with data 20: ");
    printList(head);

    return 0;
}