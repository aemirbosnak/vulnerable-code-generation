//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
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

// Function to add a node at the beginning of the list
void addNodeAtBeginning(struct node** headRef, int data) {
    struct node* newNode = createNode(data);
    
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
        return;
    }
    
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to add a node at a specific position in the list
void addNodeAtPosition(struct node** headRef, int data, int position) {
    struct node* newNode = createNode(data);
    struct node* tempNode = *headRef;
    int currentPosition = 1;
    
    if (position == 1) {
        addNodeAtBeginning(headRef, data);
        return;
    }
    
    while (tempNode!= NULL && currentPosition < position - 1) {
        tempNode = tempNode->next;
        currentPosition++;
    }
    
    if (tempNode == NULL) {
        printf("Invalid position\n");
        return;
    }
    
    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

// Function to delete a node with a given value
void deleteNode(struct node** headRef, int value) {
    struct node* tempNode = *headRef;
    struct node* previousNode = NULL;
    
    if (tempNode!= NULL && tempNode->data == value) {
        *headRef = tempNode->next;
        free(tempNode);
        return;
    }
    
    while (tempNode!= NULL && tempNode->data!= value) {
        previousNode = tempNode;
        tempNode = tempNode->next;
    }
    
    if (tempNode == NULL) {
        printf("Node not found\n");
        return;
    }
    
    previousNode->next = tempNode->next;
    free(tempNode);
}

// Function to display the list
void displayList(struct node* head) {
    struct node* tempNode = head;
    
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
}

// Main function
int main() {
    struct node* head = NULL;
    
    // Add nodes to the list
    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);
    
    // Display the list
    printf("List before deletion:\n");
    displayList(head);
    
    // Delete a node
    deleteNode(head, 3);
    
    // Display the list
    printf("\nList after deletion:\n");
    displayList(head);
    
    return 0;
}