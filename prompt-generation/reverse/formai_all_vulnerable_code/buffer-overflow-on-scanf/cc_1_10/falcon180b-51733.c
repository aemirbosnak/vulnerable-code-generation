//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
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

void insertNode(Node** head, int data) {
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
    return;
}

bool searchElement(Node* head, int data) {
    Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data;
    do {
        printf("1. Insert element\n2. Search element\n3. Print list\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (searchElement(head, data)) {
                    printf("Element found\n");
                } else {
                    printf("Element not found\n");
                }
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}