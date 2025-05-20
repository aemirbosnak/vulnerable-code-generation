//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for linked list
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

// Function to add a node at the end of the list
void addNode(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    struct Node* last = *headRef;

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

// Function to print the linked list
void printList(struct Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to reverse the linked list
void reverseList(struct Node** headRef) {
    struct Node* prev = NULL;
    struct Node* curr = *headRef;

    while (curr!= NULL) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *headRef = prev;
}

// Function to sort the linked list in ascending order
void sortList(struct Node** headRef) {
    struct Node* curr = *headRef;
    struct Node* next;
    int temp;

    while (curr!= NULL && curr->next!= NULL) {
        if (curr->data > curr->next->data) {
            temp = curr->data;
            curr->data = curr->next->data;
            curr->next->data = temp;
        }
        curr = curr->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Insert 5 nodes
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the list
    printf("Original list: ");
    printList(head);

    // Reverse the list
    reverseList(&head);
    printf("\nList after reversing: ");
    printList(head);

    // Sort the list
    sortList(&head);
    printf("\nList after sorting: ");
    printList(head);

    return 0;
}