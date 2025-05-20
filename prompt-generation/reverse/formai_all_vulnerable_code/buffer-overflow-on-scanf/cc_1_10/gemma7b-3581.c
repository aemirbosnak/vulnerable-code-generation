//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator {
    double accumulator;
    double operand;
    char operator;
    char buffer[MAX_BUFFER_SIZE];
    int bufferIndex;
} Calculator;

Calculator calculator = {
    .accumulator = 0,
    .operand = 0,
    .operator = '\0',
    .bufferIndex = 0,
    .buffer = ""
};

void calculate() {
    switch (calculator.operator) {
        case '+':
            calculator.accumulator += calculator.operand;
            break;
        case '-':
            calculator.accumulator -= calculator.operand;
            break;
        case '*':
            calculator.accumulator *= calculator.operand;
            break;
        case '/':
            if (calculator.operand == 0) {
                printf("Cannot divide by zero\n");
            } else {
                calculator.accumulator /= calculator.operand;
            }
            break;
        case '^':
            calculator.accumulator = pow(calculator.accumulator, calculator.operand);
            break;
        default:
            printf("Invalid operator\n");
    }

    calculator.operand = 0;
    calculator.operator = '\0';
}

void display() {
    printf("Accumulator: %.2lf\n", calculator.accumulator);
    printf("Operand: %.2lf\n", calculator.operand);
    printf("Operator: %c\n", calculator.operator);
    printf("Buffer: %s\n", calculator.buffer);
    printf("Buffer Index: %d\n", calculator.bufferIndex);
}

int main() {
    char input[MAX_BUFFER_SIZE];

    printf("Welcome to the Ken Thompson Style Scientific Calculator!\n");

    while (1) {
        printf("Enter an expression: ");
        scanf("%s", input);

        // Parse the input expression
        // (This code is omitted for brevity)

        // Calculate the expression
        calculate();

        // Display the results
        display();

        // Check if the user wants to continue
        if (strcmp(input, "q") == 0) {
            break;
        }
    }

    printf("Thank you for using the Ken Thompson Style Scientific Calculator!\n");

    return 0;
}