//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each node in the linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Create a new node with the given data
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory for new node.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add a node to the end of the linked list
void addNode(Node** head, char data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        return;
    }
    Node* current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Remove a node with the given data from the linked list
void removeNode(Node** head, char data) {
    Node* current = *head;
    Node* previous = NULL;
    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: Node with data '%c' not found in linked list.\n", data);
        return;
    }
    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
}

// Print the contents of the linked list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to demonstrate linked list operations
int main() {
    Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, 'a');
    addNode(&head, 'b');
    addNode(&head, 'c');
    addNode(&head, 'd');

    // Print the contents of the list
    printf("Initial list:\n");
    printList(head);

    // Remove a node
    removeNode(&head, 'b');

    // Print the contents of the list again
    printf("List after removing node with data 'b':\n");
    printList(head);

    // Add another node
    addNode(&head, 'e');

    // Print the contents of the list again
    printf("List after adding node with data 'e':\n");
    printList(head);

    // Remove the last node
    removeNode(&head, 'e');

    // Print the contents of the list again
    printf("List after removing node with data 'e':\n");
    printList(head);

    return 0;
}