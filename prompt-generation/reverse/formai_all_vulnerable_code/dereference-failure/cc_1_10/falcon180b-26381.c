//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with the given data
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Error: Memory could not be allocated.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the end of the list
void addNode(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    struct node* lastNode = *headRef;

    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }

    while (lastNode->next!= NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->next = NULL;
}

// Function to delete a node with the given data from the list
void deleteNode(struct node** headRef, int data) {
    struct node* tempNode = *headRef;

    if (tempNode!= NULL && tempNode->data == data) {
        *headRef = tempNode->next;
        free(tempNode);
        return;
    }

    while (tempNode!= NULL && tempNode->data!= data) {
        tempNode = tempNode->next;
    }

    if (tempNode == NULL) {
        printf("Node not found.\n");
        return;
    }

    struct node* prevNode = tempNode->next;
    free(tempNode);
    prevNode->next = tempNode->next;
}

// Function to print the list
void printList(struct node* head) {
    struct node* currentNode = head;

    while (currentNode!= NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}

// Main function
int main() {
    struct node* head = NULL;

    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Print the list
    printf("Original List:\n");
    printList(head);

    // Delete a node
    deleteNode(&head, 3);

    // Print the updated list
    printf("\nList after deleting node with data 3:\n");
    printList(head);

    return 0;
}