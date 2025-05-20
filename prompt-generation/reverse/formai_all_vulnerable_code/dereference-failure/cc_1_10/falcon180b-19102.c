//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the end of the list
void push(Node** headRef, int data) {
    Node* node = newNode(data);
    Node* last = *headRef;

    if (*headRef == NULL) {
        node->next = NULL;
        *headRef = node;
        return;
    }

    while (last->next!= NULL) {
        last = last->next;
    }

    last->next = node;
}

// Function to search for a node with given data in the list
Node* search(Node* head, int data) {
    Node* current = head;

    while (current!= NULL) {
        if (current->data == data) {
            return current;
        }
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
    int choice, data;
    Node* head = NULL;

    // Menu-driven program to perform various operations on the list
    while (true) {
        printf("\n1. Add element\n2. Search element\n3. Print list\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to add: ");
            scanf("%d", &data);
            push(&head, data);
            printf("%d added to the list.\n", data);
            break;

        case 2:
            printf("Enter element to search: ");
            scanf("%d", &data);
            Node* result = search(head, data);

            if (result == NULL) {
                printf("%d not found in the list.\n", data);
            } else {
                printf("%d found in the list.\n", data);
            }
            break;

        case 3:
            printf("List: ");
            printList(head);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}