//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
int divide(int a, int b) {
    if(b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }
    return a / b;
}

int main() {
    int num1, num2, result;
    char choice;

    // Initializing variables
    num1 = 0;
    num2 = 0;
    result = 0;

    // Taking user input for the operation to be performed
    printf("Enter the operation to be performed:\n");
    printf("A - Addition\n");
    printf("S - Subtraction\n");
    printf("M - Multiplication\n");
    printf("D - Division\n");
    scanf("%c", &choice);

    // Taking user input for the two numbers
    printf("Enter the first number:\n");
    scanf("%d", &num1);

    printf("Enter the second number:\n");
    scanf("%d", &num2);

    // Performing the operation based on user input
    switch(choice) {
        case 'A':
            result = add(num1, num2);
            printf("The result is: %d\n", result);
            break;

        case 'S':
            result = subtract(num1, num2);
            printf("The result is: %d\n", result);
            break;

        case 'M':
            result = multiply(num1, num2);
            printf("The result is: %d\n", result);
            break;

        case 'D':
            result = divide(num1, num2);
            printf("The result is: %d\n", result);
            break;

        default:
            printf("Invalid choice! Please enter a valid choice.\n");
            exit(1);
            break;
    }

    return 0;
}