//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

// Function to add a new node to the linked list
void addNode(Node** head, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
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

// Function to search for a string in the linked list
Node* search(Node* head, char* key) {
    Node* current = head;
    while (current!= NULL) {
        if (strcmp(current->data, key) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Add some nodes to the linked list
    addNode(&head, "apple");
    addNode(&head, "banana");
    addNode(&head, "cherry");
    addNode(&head, "date");

    // Search for a string in the linked list
    Node* result = search(head, "banana");

    // Print the linked list
    printf("Linked List:\n");
    printList(head);

    // Print the search result
    if (result!= NULL) {
        printf("Search result: %s\n", result->data);
    } else {
        printf("Search result: NOT FOUND\n");
    }

    return 0;
}