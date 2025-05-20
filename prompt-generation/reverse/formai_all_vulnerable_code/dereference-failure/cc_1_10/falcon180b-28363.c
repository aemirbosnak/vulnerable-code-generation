//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
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

// Function to add a node at the beginning of the list
void push(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* last = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (last->next!= NULL)
        last = last->next;
    last->next = newNode;
}

// Function to add a node after a given position
void insertAfter(Node* prevNode, int data) {
    Node* newNode = createNode(data);
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete a node with the given data
void deleteNode(Node** head, int data) {
    Node* temp = *head, *prev;
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

// Function to reverse the linked list
void reverseList(Node** head) {
    Node* prev = NULL, *next = *head, *temp;
    while (next!= NULL) {
        temp = next->next;
        next->next = prev;
        prev = next;
        next = temp;
    }
    *head = prev;
}

// Function to print the linked list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    push(&head, 40);
    printList(head);
    printf("\n");
    append(&head, 50);
    printList(head);
    printf("\n");
    insertAfter(head->next, 25);
    printList(head);
    printf("\n");
    deleteNode(&head, 20);
    printList(head);
    printf("\n");
    reverseList(&head);
    printList(head);
    printf("\n");
    return 0;
}