//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: mathematical
// This program demonstrates a simple C Browser Plugin example
// that performs mathematical operations on two numbers entered by the user.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    double num1, num2;
    char operation[50];

    // Prompt user to enter two numbers
    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    // Prompt user to select an operation
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%s", operation);

    // Perform selected operation and display result
    switch(atoi(operation)) {
        case 1:
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, add(num1, num2));
            break;
        case 2:
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, subtract(num1, num2));
            break;
        case 3:
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, multiply(num1, num2));
            break;
        case 4:
            if(num2 == 0)
                printf("Cannot divide by zero.\n");
            else
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, divide(num1, num2));
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    return a / b;
}