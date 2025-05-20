//Falcon-180B DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int top = -1;

void push(int x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(0);
    }
    arr[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(0);
    }
    return arr[top--];
}

int peek() {
    if (top == -1) {
        printf("Stack is Empty\n");
        exit(0);
    }
    return arr[top];
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if (top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void display() {
    if (top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Stack Elements are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\n", arr[i]);
    }
}

void main() {
    int choice, x;
    do {
        printf("\n\n********** STACK OPERATIONS **********\n");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            printf("The popped element is: %d\n", x);
            break;
        case 3:
            x = peek();
            printf("The topmost element is: %d\n", x);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);
}