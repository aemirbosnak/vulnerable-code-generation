//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(0);
    }
    top++;
    arr[top] = value;
    printf("%d pushed to stack\n", value);
}

void pop() {
    if (top < 0) {
        printf("Stack Underflow!\n");
        exit(0);
    }
    printf("%d popped from stack\n", arr[top]);
    top--;
}

void display() {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
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
            printf("Invalid choice! Please enter again.\n");
        }
    }

    return 0;
}