//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Romeo and Juliet
#include <stdio.h>

// Function to calculate the sum of two numbers
int add(int a, int b) {
    return a + b;
}

// Function to calculate the difference between two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to calculate the product of two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to calculate the quotient of two numbers
int divide(int a, int b) {
    if (b == 0) {
        printf("Error! Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

int main() {
    int num1, num2, choice;

    // Input two numbers from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Display a menu of arithmetic operations
    printf("\nArithmetic Operations Menu:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the chosen arithmetic operation
    switch (choice) {
        case 1:
            printf("\nThe sum of %d and %d is %d.\n", num1, num2, add(num1, num2));
            break;
        case 2:
            printf("\nThe difference between %d and %d is %d.\n", num1, num2, subtract(num1, num2));
            break;
        case 3:
            printf("\nThe product of %d and %d is %d.\n", num1, num2, multiply(num1, num2));
            break;
        case 4:
            printf("\nThe quotient of %d and %d is %d.\n", num1, num2, divide(num1, num2));
            break;
        default:
            printf("\nInvalid choice! Please choose a valid option.\n");
            break;
    }

    return 0;
}