#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top <= -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    int num1, num2, result;
    char operation;

    while (1) {
        printf("Enter an operation (+, -, *, /) or 'q' to quit: ");
        scanf(" %c", &operation);

        if (operation == 'q') {
            break;
        }

        printf("Enter two numbers: ");
        scanf("%d %d", &num1, &num2);

        switch (operation) {
            case '+':
                result = num1 + num2;
                push(result);
                printf("Result: %d\n", result);
                break;
            case '-':
                result = num1 - num2;
                push(result);
                printf("Result: %d\n", result);
                break;
            case '*':
                result = num1 * num2;
                push(result);
                printf("Result: %d\n", result);
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    push(result);
                    printf("Result: %d\n", result);
                } else {
                    printf("Error: Division by zero\n");
                }
                break;
            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}
