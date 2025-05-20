//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the structure for a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

void addNode(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
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

void printList(Node* head) {
    if (head == NULL) {
        printf("Empty list.\n");
        return;
    }
    printf("List elements:\n");
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice;
    do {
        printf("1. Add node\n");
        printf("2. Print list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int data;
            printf("Enter the data for the new node: ");
            scanf("%d", &data);
            addNode(&head, data);
        } else if (choice == 2) {
            printList(head);
        }
    } while (choice!= 3);
    return 0;
}