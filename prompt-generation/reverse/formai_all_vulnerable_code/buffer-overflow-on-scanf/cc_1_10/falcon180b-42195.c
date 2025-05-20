//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
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
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to search for a node with the given data
Node* searchNode(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Search node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data for the new node: ");
            scanf("%d", &data);
            addNode(&head, data);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            printf("Enter the data to search: ");
            scanf("%d", &data);
            Node* result = searchNode(head, data);
            if (result == NULL)
                printf("Node not found\n");
            else
                printf("Node found with data %d\n", result->data);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 4);

    return 0;
}