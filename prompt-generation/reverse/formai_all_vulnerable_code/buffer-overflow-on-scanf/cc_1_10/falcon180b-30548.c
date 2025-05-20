//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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

void push(Node** headRef, int newData) {
    Node* newNode = createNode(newData);
    newNode->next = *headRef;
    *headRef = newNode;
}

void pop(Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *headRef;
    *headRef = temp->next;
    free(temp);
}

void printList(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int search(Node* head, int key) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &data);
                push(&head, data);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Enter the value to be searched: ");
                scanf("%d", &data);
                if (search(head, data))
                    printf("Value found\n");
                else
                    printf("Value not found\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}