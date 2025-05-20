//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

// Function to evaluate the expression
double evaluate(double num1, char operator, double num2) {
    switch (operator) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': 
            if (num2 != 0) 
                return num1 / num2; 
            else {
                printf("Error: Division by zero!\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Error: Unknown operator '%c'\n", operator);
            exit(EXIT_FAILURE);
    }
}

// Function to parse the input and extract components
void parse_input(char *input, double *num1, char *operator, double *num2) {
    char *token;

    // Get the first number
    token = strtok(input, " ");
    if (token != NULL) {
        *num1 = atof(token);
    }

    // Get the operator
    token = strtok(NULL, " ");
    if (token != NULL) {
        *operator = token[0];
    }

    // Get the second number
    token = strtok(NULL, " ");
    if (token != NULL) {
        *num2 = atof(token);
    }
}

// Main function
int main() {
    char input[MAX_INPUT];
    double num1, num2;
    char operator;

    printf("Welcome to the Simple Calculator!\n");
    printf("Please enter an expression in the format 'number operator number'\n");
    printf("Example: 3 + 4\n");
    
    // Read input from the user
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character at the end
    input[strcspn(input, "\n")] = 0;

    // Parse the input
    parse_input(input, &num1, &operator, &num2);
    
    // Evaluate the expression
    double result = evaluate(num1, operator, num2);

    // Output the result
    printf("The result of %.2f %c %.2f is: %.2f\n", num1, operator, num2, result);

    return 0;
}