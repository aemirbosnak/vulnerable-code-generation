//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int randNum() {
    return rand() % 100;
}

// Function to calculate the sum of two numbers
int sum(int num1, int num2) {
    return num1 + num2;
}

// Function to calculate the difference of two numbers
int diff(int num1, int num2) {
    return num1 - num2;
}

// Function to calculate the product of two numbers
int prod(int num1, int num2) {
    return num1 * num2;
}

// Function to calculate the quotient of two numbers
int quot(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero\n");
        exit(1);
    }
    return num1 / num2;
}

// Function to calculate the remainder of two numbers
int rem(int num1, int num2) {
    return num1 % num2;
}

// Function to display the arithmetic operations
void displayArithmetic() {
    printf("Arithmetic Operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Remainder\n");
}

// Function to perform arithmetic operations
void performArithmetic() {
    int num1, num2, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter your choice of arithmetic operation:\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("The sum of %d and %d is %d\n", num1, num2, sum(num1, num2));
            break;
        case 2:
            printf("The difference of %d and %d is %d\n", num1, num2, diff(num1, num2));
            break;
        case 3:
            printf("The product of %d and %d is %d\n", num1, num2, prod(num1, num2));
            break;
        case 4:
            printf("The quotient of %d and %d is %d\n", num1, num2, quot(num1, num2));
            break;
        case 5:
            printf("The remainder of %d and %d is %d\n", num1, num2, rem(num1, num2));
            break;
        default:
            printf("Invalid choice\n");
    }
}

int main() {
    srand(time(NULL));

    // Display arithmetic operations
    displayArithmetic();

    // Perform arithmetic operations
    performArithmetic();

    return 0;
}