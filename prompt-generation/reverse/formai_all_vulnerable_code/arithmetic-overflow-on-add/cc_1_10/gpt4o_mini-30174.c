//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LENGTH 100

// Function prototypes
void parseExpression(const char* expression);
int calculate(int a, int b, char operator);
int precedence(char operator);
int applyOperator(int a, int b, char operator);

int main() {
    char expression[MAX_EXPR_LENGTH];

    printf("Welcome to the Enthusiastic C Expression Parser!\n");
    printf("Please enter an arithmetic expression (e.g., 3 + 5 * 2 - 8 / 4):\n");

    if (fgets(expression, sizeof(expression), stdin) != NULL) {
        // Remove the newline character
        expression[strcspn(expression, "\n")] = 0;

        printf("You entered: %s\n", expression);
        parseExpression(expression);
    } else {
        printf("Error reading the input!\n");
    }

    return 0;
}

void parseExpression(const char* expression) {
    int values[MAX_EXPR_LENGTH]; // Stack for values
    char operators[MAX_EXPR_LENGTH]; // Stack for operators
    int valueIndex = 0, operatorIndex = 0;

    const char* p = expression;

    while (*p) {
        // Skip whitespace
        if (isspace(*p)) {
            p++;
            continue;
        }

        // If the character is a number
        if (isdigit(*p)) {
            int value = 0;
            while (isdigit(*p)) {
                value = value * 10 + (*p - '0');
                p++;
            }
            values[valueIndex++] = value; // Push value onto stack
        }
        // If the character is an operator
        else if (strchr("+-*/", *p)) {
            // While the top of the operator stack has the same or greater precedence
            while (operatorIndex > 0 && 
                   precedence(operators[operatorIndex - 1]) >= precedence(*p)) {
                // Pop from operator stack
                char operator = operators[--operatorIndex];
                int b = values[--valueIndex];
                int a = values[--valueIndex];
                int result = applyOperator(a, b, operator);
                values[valueIndex++] = result; // Push result onto value stack
            }
            operators[operatorIndex++] = *p; // Push the current operator onto the stack
            p++;
        } else {
            printf("Invalid character in expression: %c\n", *p);
            return;
        }
    }

    // Process remaining operators in the stack
    while (operatorIndex > 0) {
        char operator = operators[--operatorIndex];
        int b = values[--valueIndex];
        int a = values[--valueIndex];
        int result = applyOperator(a, b, operator);
        values[valueIndex++] = result; // Push result onto value stack
    }

    printf("Result: %d\n", values[0]);
}

int calculate(int a, int b, char operator) {
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // Simple division, no error checking
        default: return 0; // Should never happen
    }
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0; // Invalid operator
    }
}

int applyOperator(int a, int b, char operator) {
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? (a / b) : 0; // Protect against division by zero
        default: return 0; // Should never happen
    }
}