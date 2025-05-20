//Falcon-180B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to add two numbers
int addNumbers(int a, int b) {
    int result = a + b;
    return result;
}

// Function to subtract two numbers
int subtractNumbers(int a, int b) {
    int result = a - b;
    return result;
}

// Function to multiply two numbers
int multiplyNumbers(int a, int b) {
    int result = a * b;
    return result;
}

// Function to divide two numbers
int divideNumbers(int a, int b) {
    int result;
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    result = a / b;
    return result;
}

int main() {
    int num1, num2, operation, result;
    char input[MAX_SIZE];
    printf("Welcome to the Calculator!\n");

    // Get input from user
    printf("Enter the first number: ");
    scanf("%s", input);
    num1 = atoi(input);

    printf("Enter the second number: ");
    scanf("%s", input);
    num2 = atoi(input);

    printf("Enter the operation (+, -, *, /): ");
    scanf("%s", input);
    operation = input[0];

    // Perform the operation
    switch (operation) {
        case '+':
            result = addNumbers(num1, num2);
            break;
        case '-':
            result = subtractNumbers(num1, num2);
            break;
        case '*':
            result = multiplyNumbers(num1, num2);
            break;
        case '/':
            result = divideNumbers(num1, num2);
            break;
        default:
            printf("Error: Invalid operation.\n");
            exit(1);
    }

    // Print the result
    printf("The result is: %d\n", result);

    return 0;
}