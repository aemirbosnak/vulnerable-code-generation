//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configurable variables
#define MAX_OPERANDS 5
#define OPERATORS " + - x * / "

// Function prototypes
int parse_expression(char *expression);
int evaluate_expression(int num1, int num2, char op);

int main() {
    // Get the expression from the user
    char expression[100];
    printf("Enter an arithmetic expression (%s): ", OPERATORS);
    fgets(expression, 100, stdin);

    // Parse the expression
    int operands[MAX_OPERANDS];
    char *token;
    int i = 0;
    while ((token = strtok(expression, " ")) != NULL) {
        operands[i++] = atoi(token);
    }

    // Evaluate the expression
    int result = evaluate_expression(operands[0], operands[1], operands[2]);

    // Print the result
    printf("Result: %d\n", result);

    return 0;
}

// Parse an expression
int parse_expression(char *expression) {
    char *token;
    int operands[MAX_OPERANDS];
    int i = 0;

    // Tokenize the expression
    while ((token = strtok(expression, " ")) != NULL) {
        operands[i++] = atoi(token);
    }

    // Check for invalid expressions
    if (i < 2 || operands[0] == operands[1]) {
        printf("Invalid expression\n");
        return 0;
    }

    return 1;
}

// Evaluate an expression
int evaluate_expression(int num1, int num2, char op) {
    int result;

    switch (op) {
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
            result = num1 / num2;
            break;
        default:
            printf("Invalid operator\n");
            return 0;
    }

    return result;
}