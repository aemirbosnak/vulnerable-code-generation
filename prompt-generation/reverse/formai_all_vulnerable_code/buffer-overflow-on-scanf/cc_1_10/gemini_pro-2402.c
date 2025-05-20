//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to get the operator from the user
char getOperator() {
    char operator;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    return operator;
}

// Function to get the operands from the user
double getOperands() {
    double operand;
    printf("Enter an operand: ");
    scanf(" %lf", &operand);
    return operand;
}

// Function to perform the calculation
double calculate(double operand1, double operand2, char operator) {
    double result;
    switch (operator) {
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
            if (operand2 == 0) {
                printf("Error: division by zero\n");
                return NAN;
            }
            result = operand1 / operand2;
            break;
        default:
            printf("Error: invalid operator\n");
            return NAN;
    }
    return result;
}

// Function to print the result
void printResult(double result) {
    printf("Result: %lf\n", result);
}

// Main function
int main() {
    // Get the operator from the user
    char operator = getOperator();

    // Get the operands from the user
    double operand1 = getOperands();
    double operand2 = getOperands();

    // Perform the calculation
    double result = calculate(operand1, operand2, operator);

    // Print the result
    printResult(result);

    return 0;
}