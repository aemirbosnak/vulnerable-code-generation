//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_OPERANDS 5
#define MAX_OPERATORS 5

// Define a struct to represent a mathematical expression
typedef struct {
    int operand1;
    int operand2;
    char operator;
} expression;

// Function to evaluate an expression
int evaluate(expression *exp) {
    int result = 0;

    // Evaluate the expression based on the operator
    switch (exp->operator) {
        case '+':
            result = exp->operand1 + exp->operand2;
            break;
        case '-':
            result = exp->operand1 - exp->operand2;
            break;
        case '*':
            result = exp->operand1 * exp->operand2;
            break;
        case '/':
            result = exp->operand1 / exp->operand2;
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }

    return result;
}

int main() {
    // Create an array to store the expressions
    expression expressions[MAX_OPERANDS];

    // Initialize the array with some expressions
    expressions[0].operand1 = 2;
    expressions[0].operand2 = 3;
    expressions[0].operator = '+';

    expressions[1].operand1 = 4;
    expressions[1].operand2 = 5;
    expressions[1].operator = '*';

    expressions[2].operand1 = 10;
    expressions[2].operand2 = 20;
    expressions[2].operator = '/';

    // Evaluate the expressions and print the results
    for (int i = 0; i < MAX_OPERANDS; i++) {
        printf("%d x %d = %d\n", expressions[i].operand1, expressions[i].operand2, evaluate(expressions + i));
    }

    return 0;
}