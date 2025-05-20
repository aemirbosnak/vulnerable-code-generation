//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
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

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchRecursive(Node* head, int target) {
    if (head == NULL) {
        return -1;
    }
    if (head->data == target) {
        return 0;
    }
    return searchRecursive(head->next, target);
}

int main() {
    Node* head = NULL;
    int choice, data, target, position;

    do {
        printf("\nLinked List Menu\n");
        printf("1. Insert at end\n");
        printf("2. Print list\n");
        printf("3. Search recursive\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 2:
            printf("The list is: ");
            printList(head);
            break;
        case 3:
            printf("Enter the target value to search: ");
            scanf("%d", &target);
            position = searchRecursive(head, target);
            if (position == -1) {
                printf("Element not found!\n");
            } else {
                printf("Element found at position %d!\n", position);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}