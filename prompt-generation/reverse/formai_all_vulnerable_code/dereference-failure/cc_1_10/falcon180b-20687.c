//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        printf("Memory error\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to add a node at the end of the list
void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// Function to search for a node with given data in the list
Node* search(Node* head, int x) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == x)
            return current;
        current = current->next;
    }
    return NULL;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* head = NULL;

    // Adding nodes at the beginning
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    // Adding nodes at the end
    append(&head, 40);
    append(&head, 50);

    // Printing the list
    printf("List after adding nodes at the beginning and end:\n");
    printList(head);

    // Searching for a node with data 30
    Node* result = search(head, 30);
    if (result!= NULL)
        printf("\nNode found with data %d\n", result->data);
    else
        printf("\nNode not found\n");

    // Searching for a node with data 60
    result = search(head, 60);
    if (result!= NULL)
        printf("\nNode found with data %d\n", result->data);
    else
        printf("\nNode not found\n");

    return 0;
}