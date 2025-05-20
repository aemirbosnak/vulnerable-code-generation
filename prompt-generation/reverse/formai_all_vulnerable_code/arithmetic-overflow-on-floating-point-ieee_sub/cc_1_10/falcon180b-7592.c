//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: imaginative
/* This program is a simple calculator that takes two numbers and an operator as input and outputs the result */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform the calculations */
double calculate(double num1, double num2, char operation) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                exit(0);
            }
            return num1 / num2;
        default:
            printf("Error: Invalid operator.\n");
            exit(0);
    }
}

int main() {
    /* Variables to store the numbers and operator */
    double num1, num2;
    char operation;

    /* Prompt the user to enter the first number */
    printf("Enter the first number: ");
    if(scanf("%lf", &num1)!= 1) {
        printf("Error: Invalid input.\n");
        exit(0);
    }

    /* Prompt the user to enter the second number */
    printf("Enter the second number: ");
    if(scanf("%lf", &num2)!= 1) {
        printf("Error: Invalid input.\n");
        exit(0);
    }

    /* Prompt the user to enter the operator */
    printf("Enter the operator (+, -, *, /): ");
    if(scanf(" %c", &operation)!= 1) {
        printf("Error: Invalid input.\n");
        exit(0);
    }

    /* Call the calculate function and print the result */
    double result = calculate(num1, num2, operation);
    printf("The result is: %lf\n", result);

    return 0;
}