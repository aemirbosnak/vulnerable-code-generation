//Falcon-180B DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    stack[top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value = stack[top];
    top--;
    return value;
}

int peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}

int is_empty() {
    return (top == -1);
}

int is_full() {
    return (top >= MAX_SIZE - 1);
}

void display() {
    if (is_empty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

void main() {
    int choice, value;
    do {
        printf("Enter 1 to push an element\n");
        printf("Enter 2 to pop an element\n");
        printf("Enter 3 to display the stack\n");
        printf("Enter 4 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            printf("Popped element is: %d\n", value);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 4);
}