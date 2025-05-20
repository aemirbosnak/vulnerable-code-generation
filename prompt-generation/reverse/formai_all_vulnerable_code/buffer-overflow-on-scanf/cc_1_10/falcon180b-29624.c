//Falcon-180B DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char *data;
    struct node *next;
} Node;

// Linked list structure
Node *head = NULL;

// Function to add a node to the linked list
void addNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove a node from the linked list
void removeNode(char *data) {
    Node *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, data) == 0) {
            Node *nextNode = temp->next;
            free(temp->data);
            free(temp);
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
}

// Function to print the linked list
void printList() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, len;
    char input[MAX_SIZE];

    // Loop until user chooses to exit
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Add a node\n");
        printf("2. Remove a node\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data for the new node: ");
            scanf("%s", input);
            addNode(input);
            break;
        case 2:
            printf("Enter the data for the node to be removed: ");
            scanf("%s", input);
            removeNode(input);
            break;
        case 3:
            printList();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}