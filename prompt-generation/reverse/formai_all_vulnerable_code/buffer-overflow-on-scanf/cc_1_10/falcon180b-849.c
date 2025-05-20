//Falcon-180B DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    arr[top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = arr[top];
    top--;
    return value;
}

int peek() {
    if (top < 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return arr[top];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top >= MAX_SIZE - 1;
}

void traverse() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value!= -1) {
                    printf("Popped value is: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value!= -1) {
                    printf("Top element is: %d\n", value);
                }
                break;
            case 4:
                traverse();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);
    return 0;
}