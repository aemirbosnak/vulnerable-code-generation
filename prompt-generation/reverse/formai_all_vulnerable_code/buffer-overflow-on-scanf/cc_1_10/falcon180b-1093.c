//Falcon-180B DATASET v1.0 Category: Memory management ; Style: dynamic
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
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
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
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free all nodes in the list
void freeList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("1. Add node\n2. Print list\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}