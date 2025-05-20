//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_SIZE 50
#define MAX_VALUE_SIZE 100

// Node structure for linked list
typedef struct node {
    char name[MAX_NAME_SIZE];
    char value[MAX_VALUE_SIZE];
    struct node* next;
} Node;

// Function to add a new node to the end of the list
void addNode(Node** head, char* name, char* value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->value, value);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a node with a specific name
Node* searchNode(Node* head, char* name) {
    Node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the entire list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s : %s\n", temp->name, temp->value);
        temp = temp->next;
    }
}

int main() {
    // Initialize the list
    Node* head = NULL;

    // Add some nodes
    addNode(&head, "John", "25");
    addNode(&head, "Jane", "30");
    addNode(&head, "Bob", "35");

    // Print the list
    printList(head);

    // Search for a node
    Node* foundNode = searchNode(head, "Jane");
    if (foundNode!= NULL) {
        printf("Found node with name: %s\n", foundNode->name);
    } else {
        printf("Node not found.\n");
    }

    // Delete a node
    Node* nodeToDelete = searchNode(head, "Bob");
    if (nodeToDelete!= NULL) {
        Node* temp = head;
        while (temp->next!= nodeToDelete) {
            temp = temp->next;
        }
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }

    // Print the updated list
    printList(head);

    return 0;
}