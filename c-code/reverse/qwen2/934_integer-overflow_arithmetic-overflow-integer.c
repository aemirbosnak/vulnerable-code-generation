#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top >= STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top <= -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main() {
    char expression[256];
    int i, num1, num2, result;

    printf("Enter RPN expression: ");
    fgets(expression, sizeof(expression), stdin);

    for (i = 0; expression[i]; i++) {
        if (expression[i] == ' ') continue;
        if (expression[i] >= '0' && expression[i] <= '9') {
            ungetc(expression[i], stdin);
            scanf("%d", &num1);
            push(num1);
        } else {
            num2 = pop();
            num1 = pop();
            switch (expression[i]) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 != 0)
                        result = num1 / num2;
                    else {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
            push(result);
        }
    }

    printf("Result: %d\n", pop());

    return 0;
}
