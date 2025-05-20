//Falcon-180B DATASET v1.0 Category: Memory management ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define SIZE 10

typedef struct {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void push(int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory error\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    if (!head) {
        head = newnode;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

void display() {
    Node *temp = head;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    int choice, data;
    while (true) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
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
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}