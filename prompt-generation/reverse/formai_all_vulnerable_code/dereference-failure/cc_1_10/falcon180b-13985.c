//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 64
#define MAX_EMAIL_LENGTH 256

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, char* name, char* email);
void deleteNode(Node** head, char* email);
void printList(Node* head);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, "John Doe", "johndoe@example.com");
    addNode(&head, "Jane Smith", "janesmith@example.com");

    // Print the list
    printList(head);

    // Delete a node from the list
    deleteNode(&head, "johndoe@example.com");

    // Print the updated list
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, char* name, char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node from the list
void deleteNode(Node** head, char* email) {
    Node* currNode = *head;
    Node* prevNode = NULL;

    while (currNode!= NULL && strcmp(currNode->email, email)!= 0) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (prevNode == NULL) {
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    free(currNode);
}

// Function to print the list
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* currNode = head;
    while (currNode!= NULL) {
        printf("Name: %s, Email: %s\n", currNode->name, currNode->email);
        currNode = currNode->next;
    }
}