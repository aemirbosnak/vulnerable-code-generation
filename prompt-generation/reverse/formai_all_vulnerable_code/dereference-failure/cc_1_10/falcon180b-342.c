//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void append(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    Node* last = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
    return;
}

// Function to add a node at the beginning of the list
void prepend(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
    return;
}

// Function to delete a node with given data
void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    if (temp!= NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    Node* t = temp->next;
    free(temp);
    temp = t;
    return;
}

// Function to search for a node with given data
Node* search(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver code
int main() {
    Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    prepend(&head, 0);
    printList(head);
    deleteNode(&head, 2);
    printList(head);
    Node* found = search(head, 3);
    if (found!= NULL)
        printf("Found %d\n", found->data);
    else
        printf("Not found\n");
    return 0;
}