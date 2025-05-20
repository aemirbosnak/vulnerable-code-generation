//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INPUT 100
#define MAX_OPERATIONS 10

// Structure to store operands and operations
typedef struct {
    double operands[2];
    char operations[2];
} arithmetic_expression;

// Function to evaluate the expression
double evaluate(arithmetic_expression exp) {
    double result = 0;

    // Evaluate the first operand
    result = exp.operands[0];

    // Evaluate the second operand
    result = result + exp.operands[1];

    // Perform the operation
    switch (exp.operations[0]) {
        case '+':
            result += exp.operations[1];
            break;
        case '-':
            result -= exp.operations[1];
            break;
        case '*':
            result *= exp.operations[1];
            break;
        case '/':
            result /= exp.operations[1];
            break;
        default:
            break;
    }

    return result;
}

int main() {
    // Initialize the operands and operations
    arithmetic_expression exp;
    exp.operands[0] = 0;
    exp.operands[1] = 0;
    exp.operations[0] = '+';
    exp.operations[1] = '+';

    // Get the first operand from the user
    printf("Enter the first operand: ");
    scanf("%lf", &exp.operands[0]);

    // Get the second operand from the user
    printf("Enter the second operand: ");
    scanf("%lf", &exp.operands[1]);

    // Get the operation from the user
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &exp.operations[0]);

    // Evaluate the expression
    double result = evaluate(exp);

    // Print the result
    printf("The result of %lf %c %lf is %lf\n", exp.operands[0], exp.operations[0], exp.operands[1], result);

    return 0;
}