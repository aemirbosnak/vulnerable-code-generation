//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERANDS 5

typedef struct {
    double value;
    int index;
} Operand;

Operand stack[MAX_OPERANDS];
int top = -1;

void push(double value) {
    if (top >= MAX_OPERANDS - 1) {
        fprintf(stderr, "Error: Stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    stack[++top].value = value;
    stack[top].index = top;
}

double pop() {
    if (top < 0) {
        fprintf(stderr, "Error: Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--].value;
}

void perform_operation(char op, double b, double a) {
    switch (op) {
        case '+':
            push(a + b);
            break;
        case '-':
            push(a - b);
            break;
        case '*':
            push(a * b);
            break;
        case '/':
            if (b == 0) {
                fprintf(stderr, "Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
            push(a / b);
            break;
        default:
            fprintf(stderr, "Error: Invalid operator.\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    char op;
    double num1, num2;

    printf("Enter numbers and operators (+, -, *, /) in postfix notation. Type 'q' to quit.\n");

    while (1) {
        scanf("%lf %c", &num1, &op);

        if (op == 'q') {
            break;
        }

        if (getchar() != ' ') {
            fprintf(stderr, "Error: Invalid input.\n");
            exit(EXIT_FAILURE);
        }

        scanf("%lf", &num2);

        perform_operation(op, num2, num1);
    }

    printf("Result: %.2lf\n", pop());

    return 0;
}