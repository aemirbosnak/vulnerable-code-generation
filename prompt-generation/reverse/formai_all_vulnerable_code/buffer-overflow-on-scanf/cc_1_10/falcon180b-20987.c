//Falcon-180B DATASET v1.0 Category: Recursive ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int a[MAX];
int top = -1;

void push(int x) {
    if (top >= (MAX - 1)) {
        printf("\nStack Overflow");
        exit(0);
    } else {
        top++;
        a[++top] = x;
    }
}

int pop() {
    int x;
    if (top < 0) {
        printf("\nStack Underflow");
        exit(0);
    } else {
        x = a[top--];
        return x;
    }
}

void display() {
    if (top >= 0) {
        printf("\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", a[i]);
        }
    } else {
        printf("\nStack is Empty");
    }
}

int main() {
    int choice, x;
    while (1) {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter the element to be pushed: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            printf("\nThe popped element is: %d", x);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}