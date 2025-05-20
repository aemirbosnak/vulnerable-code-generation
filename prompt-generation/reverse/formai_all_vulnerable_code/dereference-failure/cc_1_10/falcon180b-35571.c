//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, char* data) {
    Node* newNode = createNode(data);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next!= NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to search for a node with given data
Node* searchNode(Node* head, char* data) {
    Node* temp = head;

    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;

    if (head == NULL)
        printf("Empty list\n");
    else {
        printf("List elements are: ");
        while (temp!= NULL) {
            printf("%s ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Node* head = NULL;

    // Inserting nodes
    insertAtEnd(&head, "apple");
    insertAtEnd(&head, "banana");
    insertAtEnd(&head, "cherry");
    insertAtEnd(&head, "date");

    // Printing the list
    printList(head);

    // Searching for a node
    Node* result = searchNode(head, "banana");

    if (result!= NULL)
        printf("Node found with data: %s\n", result->data);
    else
        printf("Node not found\n");

    return 0;
}