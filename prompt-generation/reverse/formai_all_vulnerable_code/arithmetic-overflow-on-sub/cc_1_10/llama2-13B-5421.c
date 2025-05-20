//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERANDS 5
#define MAX_OPERATORS 5

// Structure to store operands and operators
typedef struct {
    int operand;
    char operator;
} operand_t;

// Function to parse the expression
void parse_expression(char* expression) {
    // Initialize operands and operators arrays
    operand_t operands[MAX_OPERANDS];
    char operators[MAX_OPERATORS];

    // Split the expression into operands and operators
    char* token = strtok(expression, " ");
    int i = 0;
    while (token != NULL) {
        if (i < MAX_OPERANDS) {
            operands[i].operand = atoi(token);
        } else {
            operators[i - MAX_OPERANDS] = token[0];
        }
        token = strtok(NULL, " ");
        i++;
    }

    // Check if the expression is valid
    if (i < MAX_OPERANDS && operators[0] == '+') {
        // Perform the addition
        int result = operands[0].operand + operands[1].operand;

        // Print the result
        printf("Result: %d\n", result);
    } else if (i < MAX_OPERANDS && operators[0] == '-') {
        // Perform the subtraction
        int result = operands[0].operand - operands[1].operand;

        // Print the result
        printf("Result: %d\n", result);
    } else if (i < MAX_OPERANDS && operators[0] == '*') {
        // Perform the multiplication
        int result = operands[0].operand * operands[1].operand;

        // Print the result
        printf("Result: %d\n", result);
    } else if (i < MAX_OPERANDS && operators[0] == '/') {
        // Perform the division
        int result = operands[0].operand / operands[1].operand;

        // Print the result
        printf("Result: %d\n", result);
    } else {
        printf("Invalid expression\n");
    }
}

int main() {
    char expression[100];

    // Ask the user for the expression
    printf("Enter an arithmetic expression: ");
    fgets(expression, 100, stdin);

    // Parse the expression
    parse_expression(expression);

    return 0;
}