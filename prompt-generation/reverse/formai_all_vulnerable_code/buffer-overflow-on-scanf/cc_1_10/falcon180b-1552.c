//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

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

void addNodeAtEnd(Node** head, int data) {
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

void searchElement(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key) {
            printf("Element found\n");
            return;
        }
        current = current->next;
    }
    printf("Element not found\n");
}

int main() {
    Node* head = NULL;
    int choice, data, key;

    do {
        printf("Enter your choice:\n");
        printf("1. Add element\n");
        printf("2. Search element\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            addNodeAtEnd(&head, data);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            searchElement(head, key);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (true);
}