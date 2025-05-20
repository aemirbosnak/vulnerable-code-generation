//Code Llama-13B DATASET v1.0 Category: Linked list operations ; Style: portable
/*
 * Linked list operations example program in a portable style
 */

#include <stdio.h>
#include <stdlib.h>

// Struct for storing data in each node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the linked list
void addNodeAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the linked list
void addNodeAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data) {
    struct Node* current = *head;
    if (current->data == data) {
        *head = current->next;
        free(current);
        return;
    }
    while (current->next != NULL) {
        if (current->next->data == data) {
            struct Node* tmp = current->next;
            current->next = tmp->next;
            free(tmp);
            return;
        }
        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Add nodes to the beginning of the linked list
    addNodeAtBeginning(&head, 10);
    addNodeAtBeginning(&head, 20);
    addNodeAtBeginning(&head, 30);

    // Add nodes to the end of the linked list
    addNodeAtEnd(&head, 40);
    addNodeAtEnd(&head, 50);

    // Delete a node from the linked list
    deleteNode(&head, 30);

    // Print the linked list
    printList(head);

    return 0;
}