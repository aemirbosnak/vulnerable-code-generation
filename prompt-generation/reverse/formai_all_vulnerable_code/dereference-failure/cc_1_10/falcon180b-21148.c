//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function prototypes
void addNode(Node** head, int data);
void printList(Node* head);
void deleteNode(Node** head, int data);
void reverseList(Node** head);

int main() {
    Node* head = NULL;

    // Add nodes to the list
    addNode(&head, 5);
    addNode(&head, 10);
    addNode(&head, 15);
    addNode(&head, 20);

    // Print the list
    printf("Original list:\n");
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 10);

    // Print the updated list
    printf("\nList after deleting node with data 10:\n");
    printList(head);

    // Reverse the list
    reverseList(&head);

    // Print the reversed list
    printf("\nReversed list:\n");
    printList(head);

    return 0;
}

// Function to add a node to the list
void addNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return;
    }

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the list
void printList(Node* head) {
    while (head!= NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to delete a node from the list
void deleteNode(Node** head, int data) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Function to reverse the list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;

    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}