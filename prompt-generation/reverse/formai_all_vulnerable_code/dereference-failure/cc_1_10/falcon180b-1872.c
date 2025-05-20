//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to calculate the result of the expression
double calculate(char expression[MAX_LENGTH]) {
    double num1, num2, result = 0;
    char operation;

    // Remove leading spaces from the expression
    while (isspace(expression[0])) {
        strcpy(expression, &expression[1]);
    }

    // Check if the expression is empty
    if (expression[0] == '\0') {
        printf("Error: Empty expression\n");
        return 0;
    }

    // Evaluate the expression
    for (int i = 0; expression[i]!= '\0'; i++) {
        if (isdigit(expression[i])) {
            // Number
            num1 = atof(&expression[i]);
            while (isdigit(expression[i])) {
                i++;
            }
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // Operator
            operation = expression[i];
            while (isspace(expression[i])) {
                i++;
            }
        } else if (expression[i] == '(') {
            // Open parenthesis
            while (expression[i]!= ')') {
                i++;
            }
            i++;
        } else if (expression[i] == ')') {
            // Close parenthesis
            while (expression[i - 1]!= '(') {
                i--;
            }
            i++;
        } else {
            // Invalid character
            printf("Error: Invalid character '%c'\n", expression[i]);
            return 0;
        }
    }

    // Check if the expression is valid
    if (result == 0) {
        printf("Error: Invalid expression\n");
        return 0;
    }

    return result;
}

int main() {
    char expression[MAX_LENGTH];
    double result;

    printf("Enter an expression: ");
    fgets(expression, MAX_LENGTH, stdin);

    // Remove newline character from the input
    expression[strcspn(expression, "\n")] = '\0';

    // Calculate the result
    result = calculate(expression);

    // Print the result
    if (result!= 0) {
        printf("Result: %.2f\n", result);
    }

    return 0;
}