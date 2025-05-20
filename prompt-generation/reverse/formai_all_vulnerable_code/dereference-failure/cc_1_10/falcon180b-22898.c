//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* lastNode = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
    }
    else {
        while (lastNode->next!= NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = NULL;
    }
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to reverse the list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to sort the list in ascending order
void sortList(Node** headRef) {
    Node* curr = *headRef;
    Node* next;
    int temp;
    while (curr!= NULL && curr->next!= NULL) {
        next = curr->next;
        while (next!= NULL) {
            if (curr->data > next->data) {
                temp = curr->data;
                curr->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        curr = curr->next;
    }
}

int main() {
    Node* head = NULL;
    addNode(&head, 5);
    addNode(&head, 3);
    addNode(&head, 7);
    addNode(&head, 1);
    addNode(&head, 9);
    printf("Original list: ");
    printList(head);
    head = reverseList(head);
    printf("Reversed list: ");
    printList(head);
    sortList(&head);
    printf("Sorted list: ");
    printList(head);
    return 0;
}