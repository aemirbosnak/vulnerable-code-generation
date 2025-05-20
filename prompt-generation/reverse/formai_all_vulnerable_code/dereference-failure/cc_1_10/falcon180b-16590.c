//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print the linked list
void printList(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

// Add a node to the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* currNode = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (currNode->next!= NULL) {
        currNode = currNode->next;
    }
    currNode->next = newNode;
}

// Remove a node with given data from the list
void removeNode(Node** head, int data) {
    Node* currNode = *head;
    Node* prevNode = NULL;
    if (currNode!= NULL && currNode->data == data) {
        *head = currNode->next;
        free(currNode);
        return;
    }
    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        return;
    }
    prevNode->next = currNode->next;
    free(currNode);
}

// Reverse the linked list
void reverseList(Node** head) {
    Node* currNode = *head;
    Node* prevNode = NULL;
    Node* nextNode = NULL;
    while (currNode!= NULL) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    *head = prevNode;
}

int main() {
    Node* head = NULL;
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    printList(head);
    removeNode(&head, 2);
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;
}