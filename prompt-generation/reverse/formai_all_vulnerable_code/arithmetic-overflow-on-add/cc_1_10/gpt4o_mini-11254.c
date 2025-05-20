//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);
int factorial(int n);

int main() {
    int choice, num1, num2;
    double result;
    char continueChoice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two integers for addition: ");
                scanf("%d %d", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %d + %d = %.0f\n", num1, num2, result);
                break;
                
            case 2:
                printf("Enter two integers for subtraction: ");
                scanf("%d %d", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %d - %d = %.0f\n", num1, num2, result);
                break;

            case 3:
                printf("Enter two integers for multiplication: ");
                scanf("%d %d", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %d * %d = %.0f\n", num1, num2, result);
                break;

            case 4:
                printf("Enter two integers for division (numerator and denominator): ");
                scanf("%d %d", &num1, &num2);
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result: %d / %d = %.2f\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;

            case 5:
                printf("Enter a number to calculate its factorial: ");
                scanf("%d", &num1);
                if (num1 < 0) {
                    printf("Error: Factorial of a negative number is not defined.\n");
                } else {
                    result = factorial(num1);
                    printf("Factorial of %d = %.0f\n", num1, result);
                }
                break;
                
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &continueChoice);

    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Simple Calculator ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Factorial\n");
    printf("6. Exit\n");
}

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
double divide(int a, int b) {
    return (double)a / b;
}

// Function to calculate factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}