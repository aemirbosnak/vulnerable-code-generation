//Falcon-180B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Linked list functions
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: memory could not be allocated.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** headRef, int data) {
    Node* newNode = createNode(data);
    Node* last = *headRef;
    if (*headRef == NULL) {
        newNode->next = NULL;
        *headRef = newNode;
    } else {
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = NULL;
    }
}

void removeNode(Node** headRef, int data) {
    Node* currNode = *headRef;
    Node* prevNode = NULL;
    if (currNode!= NULL && currNode->data == data) {
        *headRef = currNode->next;
        free(currNode);
        return;
    }
    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        printf("Error: node not found.\n");
    } else {
        prevNode->next = currNode->next;
        free(currNode);
    }
}

void displayList(Node* head) {
    Node* currNode = head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("1. Add node\n");
        printf("2. Remove node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter data to remove: ");
                scanf("%d", &data);
                removeNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}