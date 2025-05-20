//Falcon-180B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct Node {
    char *data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node* createNode(char *data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(struct Node **head, char *data) {
    struct Node *newNode = createNode(data);
    struct Node *temp = *head;
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

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node *head) {
    struct Node *temp = head;
    while (temp!= NULL) {
        free(temp->data);
        free(temp);
        temp = temp->next;
    }
}

int main() {
    struct Node *head = NULL;

    // Add nodes to the list
    addNode(&head, "Hello");
    addNode(&head, "World");
    addNode(&head, "!");

    // Print the list
    printf("Linked List: ");
    printList(head);

    // Free the memory allocated for the list
    freeList(head);

    return 0;
}