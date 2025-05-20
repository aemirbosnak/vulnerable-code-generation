//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Struct for a mathematical expression
typedef struct {
    char operation;
    int operand1;
    int operand2;
} MathExpression;

int main() {
    // Declare variables for memory allocation
    int numExpressions;
    MathExpression* expressions;
    
    // Get user input for number of expressions to create
    printf("How many mathematical expressions would you like to create? ");
    scanf("%d", &numExpressions);
    
    // Allocate memory for the expressions array
    expressions = (MathExpression*) malloc(numExpressions * sizeof(MathExpression));
    
    // Loop through and populate expressions
    for (int i = 0; i < numExpressions; i++) {
        // Get user input for expression details
        printf("Enter expression %d: ", i+1);
        char operation;
        int operand1, operand2;
        scanf(" %c %d %d", &operation, &operand1, &operand2);
        
        // Store expression in array
        expressions[i].operation = operation;
        expressions[i].operand1 = operand1;
        expressions[i].operand2 = operand2;
    }
    
    // Loop through and print out expressions with results
    for (int i = 0; i < numExpressions; i++) {
        // Get operands and operation
        int operand1 = expressions[i].operand1;
        int operand2 = expressions[i].operand2;
        char operation = expressions[i].operation;
        
        // Declare result variable
        int result;
        
        // Evaluate expression based on operation
        switch (operation) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                // Check for division by zero
                if (operand2 == 0) {
                    printf("Error: Division by zero\n");
                    continue; // Skip to next expression
                }
                result = operand1 / operand2;
                break;
            default:
                printf("Error: Invalid operation\n");
                continue; // Skip to next expression
        }
        
        // Print out expression and result
        printf("%d %c %d = %d\n", operand1, operation, operand2, result);
    }
    
    // Free memory for expressions array
    free(expressions);
    
    return 0;
}