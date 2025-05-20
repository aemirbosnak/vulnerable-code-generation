//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int binarySearch(Node* head, int target) {
    Node* mid = head;
    Node* end = head;
    while (end->next!= NULL && end!= head) {
        end = end->next;
    }
    while (mid!= end) {
        if (target < mid->data) {
            mid = mid->next;
        } else if (target > mid->data) {
            mid = head;
        } else {
            return 1;
        }
    }
    return 0;
}

int main() {
    Node* head = NULL;
    int choice, data, target;

    do {
        printf("1. Add element\n");
        printf("2. Print list\n");
        printf("3. Binary search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            addNode(&head, data);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            printf("Enter the target: ");
            scanf("%d", &target);
            if (binarySearch(head, target)) {
                printf("Element found\n");
            } else {
                printf("Element not found\n");
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}