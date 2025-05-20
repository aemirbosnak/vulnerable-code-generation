//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    } else {
        while (temp->next!= NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("\n");
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Linked List: ");
                printList(head);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}