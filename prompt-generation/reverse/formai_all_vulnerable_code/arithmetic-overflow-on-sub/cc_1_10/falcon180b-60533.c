//Falcon-180B DATASET v1.0 Category: Recursive ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    top++;
    arr[top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    int value = arr[top];
    top--;
    return value;
}

void print_stack() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void recursive_sum(int num, int *sum) {
    if (num == 0) {
        *sum = 0;
        return;
    }
    *sum += num;
    recursive_sum(num - 1, sum);
}

int main() {
    int choice, value, sum = 0;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Recursive Sum\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                printf("Popped value is: %d\n", value);
                break;
            case 3:
                print_stack();
                break;
            case 4:
                printf("Enter the number to calculate recursive sum: ");
                scanf("%d", &value);
                recursive_sum(value, &sum);
                printf("Recursive Sum is: %d\n", sum);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}