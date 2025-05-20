//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a node
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(char data) {
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
void addNode(Node** head, char data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with given data
void deleteNode(Node** head, char data) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to search for a node with given data
Node* searchNode(Node* head, char data) {
    Node* temp = head;
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return NULL;
    }
    return temp;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 'a');
    addNode(&head, 'b');
    addNode(&head, 'c');

    // Print the list
    printf("List after adding nodes:\n");
    printList(head);

    // Search for a node
    Node* foundNode = searchNode(head, 'b');
    if (foundNode!= NULL) {
        printf("Found node with data: %c\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    // Delete a node
    deleteNode(&head, 'b');

    // Print the list after deletion
    printf("List after deleting node with data 'b':\n");
    printList(head);

    return 0;
}