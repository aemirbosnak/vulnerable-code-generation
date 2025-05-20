//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Node structure for linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(Node** head, char data) {
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

// Function to search for a node with given data in the list
Node* searchNode(Node* head, char data) {
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
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    // Loop until user chooses to exit
    while (TRUE) {
        printf("1. Add node\n2. Search node\n3. Print list\n4. Exit\n");
        scanf("%d", &choice);

        // Add node
        if (choice == 1) {
            printf("Enter data: ");
            scanf(" %c", &data);
            addNode(&head, data);
        }

        // Search node
        else if (choice == 2) {
            printf("Enter data to search: ");
            scanf(" %c", &data);
            Node* result = searchNode(head, data);
            if (result!= NULL) {
                printf("Node found\n");
            } else {
                printf("Node not found\n");
            }
        }

        // Print list
        else if (choice == 3) {
            printList(head);
        }

        // Exit
        else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}