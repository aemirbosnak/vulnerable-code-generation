//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* push(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* pop(Node* head) {
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

int isEmpty(Node* head) {
    return head == NULL;
}

int peek(Node* head) {
    if (isEmpty(head)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return head->data;
}

int main() {
    Node* head = NULL;
    int choice, data;

    while (true) {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push:\n");
                scanf("%d", &data);
                head = push(head, data);
                break;
            case 2:
                head = pop(head);
                break;
            case 3:
                data = peek(head);
                printf("Peeked data: %d\n", data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}