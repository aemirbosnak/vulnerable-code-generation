//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} node;

node *head = NULL;

void push(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
        return;
    }
    node *temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node *temp = head;
    head = head->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int is_empty() {
    if (head == NULL)
        return 1;
    else
        return 0;
}

int is_full() {
    node *temp = head;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    if (count == MAX_SIZE)
        return 1;
    else
        return 0;
}

void main() {
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &value);
                push(value);
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