//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024
#define MAX_INTEGER 100000

// Function to calculate the factorial of a given integer
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Function to calculate the value of a given expression
double evaluate(char *expression) {
    int num1, num2, op;
    double result;

    // Parse the expression and extract the numbers and operator
    sscanf(expression, "%d%c%d", &num1, &op, &num2);

    // Handle invalid expressions
    if (op != '+' && op != '-' && op != '*' && op != '/') {
        printf("Invalid expression: %s\n", expression);
        return 0;
    }

    // Handle division by zero
    if (num2 == 0) {
        printf("Division by zero: %s\n", expression);
        return 0;
    }

    // Perform the operation
    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;
    }

    return result;
}

int main() {
    char expression[MAX_STRING_LENGTH];
    int choice;
    double result;

    // Ask the user for the expression and calculate its value
    printf("Enter an expression: ");
    fgets(expression, MAX_STRING_LENGTH, stdin);
    result = evaluate(expression);

    // Handle invalid input
    if (result == 0) {
        printf("Invalid expression: %s\n", expression);
    } else {
        // Print the result
        printf("Result: %f\n", result);
    }

    // Ask the user for another expression
    printf("Do you want to enter another expression? (y/n): ");
    scanf("%d", &choice);

    // Repeat the process until the user says no
    while (choice == 1) {
        // Ask the user for the expression and calculate its value
        printf("Enter an expression: ");
        fgets(expression, MAX_STRING_LENGTH, stdin);
        result = evaluate(expression);

        // Handle invalid input
        if (result == 0) {
            printf("Invalid expression: %s\n", expression);
        } else {
            // Print the result
            printf("Result: %f\n", result);
        }

        // Ask the user for another expression
        printf("Do you want to enter another expression? (y/n): ");
        scanf("%d", &choice);
    }

    return 0;
}