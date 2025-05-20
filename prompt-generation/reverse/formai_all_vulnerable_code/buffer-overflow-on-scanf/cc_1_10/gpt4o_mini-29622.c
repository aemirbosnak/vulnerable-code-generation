//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0; // Returning 0 here but it should simply handle the error
    }
    return a / b;
}

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial of negative numbers does not exist.\n");
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void displayMenu() {
    printf("\nSimple Calculator Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Factorial\n");
    printf("6. Exit\n");
}

int main() {
    int choice, num;
    double firstNumber, secondNumber;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear invalid input
            printf("Invalid input! Please enter a number between 1 and 6.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &firstNumber, &secondNumber) == 2) {
                    printf("Result: %.2lf\n", add(firstNumber, secondNumber));
                } else {
                    while (getchar() != '\n'); // clear invalid input
                    printf("Invalid input! Please enter valid numbers.\n");
                }
                break;
            case 2:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &firstNumber, &secondNumber) == 2) {
                    printf("Result: %.2lf\n", subtract(firstNumber, secondNumber));
                } else {
                    while (getchar() != '\n'); // clear invalid input
                    printf("Invalid input! Please enter valid numbers.\n");
                }
                break;
            case 3:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &firstNumber, &secondNumber) == 2) {
                    printf("Result: %.2lf\n", multiply(firstNumber, secondNumber));
                } else {
                    while (getchar() != '\n'); // clear invalid input
                    printf("Invalid input! Please enter valid numbers.\n");
                }
                break;
            case 4:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &firstNumber, &secondNumber) == 2) {
                    double result = divide(firstNumber, secondNumber);
                    if (secondNumber != 0) {
                        printf("Result: %.2lf\n", result);
                    }
                } else {
                    while (getchar() != '\n'); // clear invalid input
                    printf("Invalid input! Please enter valid numbers.\n");
                }
                break;
            case 5:
                printf("Enter a positive integer: ");
                if (scanf("%d", &num) == 1) {
                    unsigned long long result = factorial(num);
                    if (num >= 0) {
                        printf("Factorial of %d = %llu\n", num, result);
                    }
                } else {
                    while (getchar() != '\n'); // clear invalid input
                    printf("Invalid input! Please enter a valid number.\n");
                }
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
        }
    }
    
    return 0; // Although this line won't be reached, it's good practice
}