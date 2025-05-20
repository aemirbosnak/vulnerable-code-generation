//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int search(Node* head, int target) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == target) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    int choice, data, target;

    do {
        printf("1. Add element\n");
        printf("2. Display list\n");
        printf("3. Search element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            head = createNode(data);
            break;
        case 2:
            printList(head);
            break;
        case 3:
            printf("Enter the target data: ");
            scanf("%d", &target);
            if (search(head, target)) {
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