//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a node with the given data at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with the given data from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        return;
    }
    
    Node* nextNode = temp->next;
    free(temp);
    temp = nextNode;
}

// Function to search for a node with the given data in the list
Node* searchNode(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    
    // Add nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    
    // Print the list
    printList(head);
    
    // Delete a node from the list
    deleteNode(&head, 3);
    
    // Print the list again
    printList(head);
    
    return 0;
}