//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void addNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
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

void search(int data) {
    Node *temp = head;
    int found = 0;
    while (temp!= NULL &&!found) {
        if (temp->data == data) {
            found = 1;
            printf("Element found\n");
        } else {
            temp = temp->next;
        }
    }
    if (!found) {
        printf("Element not found\n");
    }
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Add element\n2. Search element\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &data);
            addNode(data);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &data);
            search(data);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}