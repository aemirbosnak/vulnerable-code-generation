//MISTRAL-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_OPERANDS 10
#define MAX_OPERATIONS 5
#define BUF_SIZE 80

typedef struct {
    double value;
    char op;
} Operand;

Operand operands[MAX_OPERANDS];
int top = -1;

typedef enum {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    POWER
} Operations;

char* operations[MAX_OPERATIONS] = {
    "+",
    "-",
    "*",
    "/",
    "^"
};

void push_operand(double value) {
    if (top >= MAX_OPERANDS - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    operands[++top].value = value;
}

double pop_operand() {
    if (top < 0) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return operands[top--].value;
}

void apply_operation(Operations op) {
    double b = pop_operand();
    double a = pop_operand();

    switch (op) {
        case ADD:
            push_operand(a + b);
            break;
        case SUBTRACT:
            push_operand(a - b);
            break;
        case MULTIPLY:
            push_operand(a * b);
            break;
        case DIVIDE:
            if (b == 0) {
                printf("Division by zero!\n");
                exit(EXIT_FAILURE);
            }
            push_operand(a / b);
            break;
        case POWER:
            push_operand(pow(a, b));
            break;
    }
}

void print_menu() {
    printf("\nScientific Calculator\n");
    printf("----------------------\n");
    printf("Enter a number to push it onto the stack\n");
    printf("Enter an operation (+, -, *, /, ^) followed by a number to perform that operation\n");
    printf("Enter q to quit\n");
}

int main() {
    double num1, num2;
    Operations op;
    char input[BUF_SIZE];

    print_menu();

    while (1) {
        scanf("%s", input);

        if (strlen(input) == 1 && input[0] == 'q') {
            break;
        }

        sscanf(input, "%lf %c %lf", &num1, &op, &num2);

        if (op != '+' && op != '-' && op != '*' && op != '/' && op != '^') {
            printf("Invalid operation!\n");
            continue;
        }

        push_operand(num1);
        apply_operation((Operations)(op - '+' + 1));
        push_operand(num2);
    }

    printf("Result: %.2lf\n", operands[top].value);

    return EXIT_SUCCESS;
}