//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 1000
#define TRUE 1
#define FALSE 0

typedef struct {
    int data;
    int next;
} Node;

Node *head = NULL;

void push(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void pop() {
    if (head == NULL) {
        printf("Stack is Empty\n");
    }
    else {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int peek() {
    if (head == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }
    else {
        return head->data;
    }
}

int isEmpty() {
    return head == NULL;
}

int isFull() {
    return head == NULL;
}

int main() {
    int choice, data;

    while (TRUE) {
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                data = peek();
                if (data == -1) {
                    printf("Stack is Empty\n");
                }
                else {
                    printf("Top element is %d\n", data);
                }
                break;
            case 4:
                if (head == NULL) {
                    printf("Stack is Empty\n");
                }
                else {
                    Node *temp = head;
                    while (temp!= NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}