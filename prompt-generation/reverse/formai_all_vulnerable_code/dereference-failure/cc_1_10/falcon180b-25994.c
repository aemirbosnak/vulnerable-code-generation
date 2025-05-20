//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the list
void push(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to add a node at the end of the list
void append(Node** headRef, int newData) {
    Node* newNode = createNode(newData);

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }

    Node* last = *headRef;
    while (last->next!= NULL)
        last = last->next;

    last->next = newNode;
    return;
}

// Function to add a node after a given position in the list
void addAfter(Node* prevNode, int newData) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    Node* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    return;
}

// Function to delete a node with the given data value
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef, *prev;

    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);            
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to display the list
void display(Node* node) {
    while (node!= NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    // Adding nodes at the beginning
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);

    // Displaying the list
    printf("List after adding nodes at the beginning:\n");
    display(head);

    // Adding nodes at the end
    append(&head, 2);
    append(&head, 4);
    append(&head, 5);

    // Displaying the list
    printf("\nList after adding nodes at the end:\n");
    display(head);

    // Adding nodes after a given position
    addAfter(head->next, 6);

    // Displaying the list
    printf("\nList after adding a node after a given position:\n");
    display(head);

    // Deleting a node with a given data value
    deleteNode(&head, 1);

    // Displaying the list
    printf("\nList after deleting a node with a given data value:\n");
    display(head);

    return 0;
}