//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the list
void push(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* last = *head_ref;

    // If the list is empty, set the new node as the head
    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    // Traverse till the end of the list
    while (last->next!= NULL)
        last = last->next;

    // Add the new node at the end of the list
    last->next = new_node;

    return;
}

// Function to print the list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Function to search for an element in the list
Node* search(Node* head, int x) {
    Node* current = head;

    // Traverse through the list
    while (current!= NULL) {
        // If the element is found, return the node
        if (current->data == x)
            return current;

        // Move to the next node
        current = current->next;
    }

    // If the element is not found, return NULL
    return NULL;
}

// Driver code
int main() {
    Node* head = NULL;

    // Insert elements into the list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    // Print the list
    printf("List: ");
    printList(head);
    printf("\n");

    // Search for an element
    Node* result = search(head, 3);

    // If the element is found, print its position
    if (result!= NULL)
        printf("Element found at position %d\n", result->data);
    else
        printf("Element not found\n");

    return 0;
}