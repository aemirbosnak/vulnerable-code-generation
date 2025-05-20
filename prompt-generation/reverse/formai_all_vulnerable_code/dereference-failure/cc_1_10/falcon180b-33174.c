//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to add a node to the end of the linked list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
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

// Function to search for a node in the linked list
Node* searchNode(Node* head, int data) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a node from the linked list
void deleteNode(Node** head, int data) {
    Node* current = searchNode(*head, data);
    if (current == NULL) {
        printf("Node not found.\n");
        return;
    }

    if (current == *head) {
        *head = current->next;
        free(current);
        return;
    }

    Node* temp = *head;
    while (temp->next!= current) {
        temp = temp->next;
    }
    temp->next = current->next;
    free(current);
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to sort the linked list in ascending order
void sortList(Node** head) {
    Node* current = *head;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = NULL;
        addNode(head, current->data);
        current = next;
    }
}

int main() {
    Node* head = NULL;

    // Add nodes to the linked list
    addNode(&head, 5);
    addNode(&head, 3);
    addNode(&head, 8);
    addNode(&head, 2);

    // Print the linked list
    printf("Original list:\n");
    printList(head);

    // Sort the linked list
    sortList(&head);

    // Print the sorted linked list
    printf("Sorted list:\n");
    printList(head);

    // Delete a node from the linked list
    deleteNode(&head, 5);

    // Print the updated linked list
    printf("Updated list:\n");
    printList(head);

    return 0;
}