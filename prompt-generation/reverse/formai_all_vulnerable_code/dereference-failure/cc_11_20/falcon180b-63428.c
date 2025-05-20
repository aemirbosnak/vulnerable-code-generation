//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    // Initialize an empty linked list
    Node* head = NULL;

    // Create a new node with value 1
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 1;
    newNode->next = NULL;

    // Add the new node to the end of the linked list
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Print the linked list
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");

    // Insert a node with value 2 at the beginning of the linked list
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = 2;
    newNode->next = head;
    head = newNode;

    // Print the linked list
    currNode = head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");

    // Delete a node with value 1 from the linked list
    if (head!= NULL && head->data == 2) {
        head = head->next;
    } else {
        currNode = head;
        while (currNode!= NULL && currNode->data!= 2) {
            currNode = currNode->next;
        }
        if (currNode!= NULL) {
            currNode->next = currNode->next->next;
        }
    }

    // Print the linked list
    currNode = head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");

    // Reverse the linked list
    Node* prevNode = NULL;
    currNode = head;
    while (currNode!= NULL) {
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    head = prevNode;

    // Print the reversed linked list
    currNode = head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");

    return 0;
}