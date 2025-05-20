//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    int choice, value;
    char ch;

    do {
        printf("Enter your choice:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the value to be pushed:\n");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            printf("The popped value is %d\n", value);
            break;
        case 3:
            printf("The stack elements are:\n");
            while (top >= 0) {
                value = pop();
                printf("%d ", value);
            }
            printf("\n");
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}