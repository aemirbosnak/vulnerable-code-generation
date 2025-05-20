//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_OPERANDS 10
#define MAX_OPERATORS 5

enum {
    PLUS = 1,
    MINUS = 2,
    MULTIPLY = 3,
    DIVIDE = 4
};

struct operand {
    double value;
    int operator;
};

struct operand stack[MAX_OPERANDS];
int top;

void push(double value, int operator) {
    if (top >= MAX_OPERANDS) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[top].value = value;
    stack[top].operator = operator;
    top++;
}

double pop() {
    if (top <= 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    double value = stack[top - 1].value;
    int operator = stack[top - 1].operator;
    top--;
    return value;
}

double perform_operation(int operator) {
    double operand2 = pop();
    double operand1 = pop();

    switch (operator) {
        case PLUS:
            return operand1 + operand2;
        case MINUS:
            return operand1 - operand2;
        case MULTIPLY:
            return operand1 * operand2;
        case DIVIDE:
            if (operand2 == 0) {
                printf("Division by zero\n");
                exit(1);
            }
            return operand1 / operand2;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

int main() {
    int i;
    double operand;
    char operation[MAX_OPERATORS];

    printf("Enter expression: ");
    for (i = 0; i < MAX_OPERATORS; i++) {
        scanf("%lf %s", &operand, operation);
        if (i == 0) {
            push(operand, 0);
        } else {
            while (top > 0 && stack[top - 1].operator!= 0) {
                operand = perform_operation(stack[top - 1].operator);
            }
            push(operand, atoi(operation));
        }
    }

    while (top > 0) {
        operand = perform_operation(stack[top - 1].operator);
    }

    printf("Result: %lf\n", operand);

    return 0;
}