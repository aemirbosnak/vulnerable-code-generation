//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

// Function declarations
void parseExpression(const char *expression);
int evaluate(int leftOperand, char operator, int rightOperand);
int getNextToken(const char *expr, int *index, char *token);

// Main function
int main() {
    char expression[MAX_LENGTH];

    // User input
    printf("Enter a simple expression (e.g., 3 + 5): ");
    fgets(expression, sizeof(expression), stdin);
    
    // Remove newline character
    expression[strcspn(expression, "\n")] = 0;

    // Parse and evaluate the expression
    parseExpression(expression);

    return 0;
}

// Function to parse and evaluate expression
void parseExpression(const char *expression) {
    int index = 0;
    char token[MAX_LENGTH];
    int leftOperand, rightOperand;
    char operator;

    // Get first operand
    if (getNextToken(expression, &index, token)) {
        leftOperand = atoi(token);
    } else {
        printf("Invalid expression.\n");
        return;
    }

    // Get operator
    if (getNextToken(expression, &index, token)) {
        operator = token[0];
    } else {
        printf("Invalid expression.\n");
        return;
    }

    // Get second operand
    if (getNextToken(expression, &index, token)) {
        rightOperand = atoi(token);
    } else {
        printf("Invalid expression.\n");
        return;
    }

    // Evaluate expression
    int result = evaluate(leftOperand, operator, rightOperand);
    printf("Result: %d\n", result);
}

// Function to evaluate the expression
int evaluate(int leftOperand, char operator, int rightOperand) {
    switch(operator) {
        case '+': return leftOperand + rightOperand;
        case '-': return leftOperand - rightOperand;
        case '*': return leftOperand * rightOperand;
        case '/': 
            if (rightOperand != 0)
                return leftOperand / rightOperand;
            else {
                printf("Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Invalid operator: %c\n", operator);
            exit(EXIT_FAILURE);
    }
}

// Function to get the next token from the expression
int getNextToken(const char *expr, int *index, char *token) {
    while (isspace(expr[*index])) (*index)++; // Skip whitespace

    if (expr[*index] == '\0') return 0; // End of expression

    int tokenLength = 0;

    // Process numbers
    while (isdigit(expr[*index])) {
        token[tokenLength++] = expr[*index];
        (*index)++;
    }
    if (tokenLength > 0) {
        token[tokenLength] = '\0';
        return 1; // Found a number
    }

    // Process operators
    if (strchr("+-*/", expr[*index])) {
        token[0] = expr[*index];
        token[1] = '\0';
        (*index)++;
        return 1; // Found an operator
    }
    
    return 0; // No valid token found
}