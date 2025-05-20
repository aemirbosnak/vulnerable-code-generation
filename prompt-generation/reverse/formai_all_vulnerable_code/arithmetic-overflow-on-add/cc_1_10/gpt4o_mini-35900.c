//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main() {
    int choice, num1, num2;
    float result;

    // Displaying a welcoming message
    printf("************************************************\n");
    printf("*          Welcome to Retro Arithmetic!         *\n");
    printf("************************************************\n");
    printf("*         Enter two integers to begin.         *\n");
    printf("************************************************\n");

    // Input integers
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    do {
        displayMenu();
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %d + %d = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %d - %d = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %d * %d = %.2f\n", num1, num2, result);
                break;
            case 4:
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result: %d / %d = %.2f\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero is not allowed!\n");
                }
                break;
            case 5:
                printf("Exiting the program... Thank you for using Retro Arithmetic!\n");
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("************************************************\n");
    printf("Menu Options: \n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("************************************************\n");
}

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two integers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two integers
float divide(int a, int b) {
    return (float)a / b;
}