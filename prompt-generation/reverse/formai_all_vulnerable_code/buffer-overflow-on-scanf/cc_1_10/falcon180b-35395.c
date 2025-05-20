//Falcon-180B DATASET v1.0 Category: Recursive ; Style: inquisitive
#include <stdio.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full!\n");
        return;
    }
    top++;
    arr[top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    int value = arr[top];
    top--;
    return value;
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
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
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value!= -1)
                printf("Popped value is: %d\n", value);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}