//MISTRAL-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OPERANDS 10
#define MAX_EXPRESSION_LENGTH 100

typedef struct {
    double value;
    int index;
} Operand;

Operand operands[MAX_OPERANDS];
int top = 0;

void push(double value) {
    if (top >= MAX_OPERANDS) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    operands[top].value = value;
    operands[top].index = top;
    top++;
}

double pop() {
    if (top <= 0) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    double value = operands[--top].value;
    memset(&operands[top], 0, sizeof(Operand));
    return value;
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
                printf("Division by zero\n");
                exit(EXIT_FAILURE);
            }
            push(a / b);
            break;
        case '^':
            push(pow(a, b));
            break;
        case 's':
            push(-pop());
            break;
        default:
            printf("Invalid operation\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    char expression[MAX_EXPRESSION_LENGTH];
    double a, b;
    char op;

    printf("Scientific calculator\n");
    printf("Enter expression in the following format: number operator number ...\n");
    printf("Supported operations: +, -, *, /, ^, s (negation)\n");
    printf("Enter 'q' to quit\n");

    while (1) {
        printf("\n%s", "> ");
        scanf("%s", expression);

        if (strcmp(expression, "q") == 0) {
            break;
        }

        sscanf(expression, "%lf%c%lf", &a, &op, &b);

        if (op != 's') {
            push(a);
        }

        perform_operation(op, b, pop());
    }

    printf("Result: %.10f\n", pop());

    return EXIT_SUCCESS;
}