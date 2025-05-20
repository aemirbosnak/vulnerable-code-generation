//Falcon-180B DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Function to check if a number is even or not
bool isEven(int num) {
    if (num % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

// Function to add two numbers
int add(int num1, int num2) {
    int result;
    if (num1 == 0 || num2 == 0) {
        printf("Error: Cannot add zero to another number.\n");
        exit(1);
    } else {
        result = num1 + num2;
        return result;
    }
}

// Function to multiply two numbers
int multiply(int num1, int num2) {
    int result;
    if (num1 == 0 || num2 == 0) {
        printf("Error: Cannot multiply zero to another number.\n");
        exit(1);
    } else {
        result = num1 * num2;
        return result;
    }
}

// Function to divide two numbers
int divide(int num1, int num2) {
    int result;
    if (num2 == 0) {
        printf("Error: Cannot divide by zero.\n");
        exit(1);
    } else {
        result = num1 / num2;
        return result;
    }
}

// Function to calculate the factorial of a number
int factorial(int num) {
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num1, num2, choice;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Display menu options
    printf("\nMenu:\n");
    printf("1. Add\n2. Multiply\n3. Divide\n4. Factorial\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Result: %d\n", add(num1, num2));
            break;
        case 2:
            printf("Result: %d\n", multiply(num1, num2));
            break;
        case 3:
            printf("Result: %d\n", divide(num1, num2));
            break;
        case 4:
            printf("Result: %d\n", factorial(num1));
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}