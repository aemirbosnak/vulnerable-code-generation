//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure definition
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, char* data);
void printList(Node* head);
Node* searchList(Node* head, char* data);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, "apple");
    addNode(&head, "banana");
    addNode(&head, "cherry");
    addNode(&head, "date");
    addNode(&head, "elderberry");

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Search for a node
    Node* foundNode = searchList(head, "banana");
    if (foundNode!= NULL) {
        printf("\nFound node with data: %s\n", foundNode->data);
    } else {
        printf("\nNode not found.\n");
    }

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, char* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%s -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to search for a node in the list
Node* searchList(Node* head, char* data) {
    while (head!= NULL) {
        if (strcmp(head->data, data) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}