//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define function prototypes
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main() {
    int num1, num2, result;
    char operation;

    // Prompt user for input
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Prompt user for operation
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform arithmetic operation based on user input
    switch(operation) {
        case '+':
            result = add(num1, num2);
            printf("Result: %d\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("Result: %d\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("Result: %d\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }

    return 0;
}

// Function to add two integers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to subtract two integers
int subtract(int num1, int num2) {
    return num1 - num2;
}

// Function to multiply two integers
int multiply(int num1, int num2) {
    return num1 * num2;
}

// Function to divide two integers with error handling for division by zero
int divide(int num1, int num2) {
    if(num2 == 0) {
        printf("Error: Division by zero.\n");
        return 0;
    }
    return num1 / num2;
}