//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {
    int num1, num2, result;
    char operation;

    // Prompt the user to enter two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Prompt the user to select an arithmetic operation
    printf("Select an arithmetic operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the selected arithmetic operation
    switch (operation) {
        case '+':
            result = add(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("The result is: %d\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("The result is: %d\n", result);
            break;
        default:
            printf("Invalid operation selected.\n");
            exit(1);
    }

    return 0;
}

// Function to perform addition
int add(int a, int b) {
    return a + b;
}

// Function to perform subtraction
int subtract(int a, int b) {
    return a - b;
}

// Function to perform multiplication
int multiply(int a, int b) {
    return a * b;
}

// Function to perform division
int divide(int a, int b) {
    if (b == 0) {
        printf("Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}