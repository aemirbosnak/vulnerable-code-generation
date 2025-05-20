//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
int modulus(int a, int b);
void clearInputBuffer();

int main() {
    int choice;
    int num1, num2;
    char continueChoice;

    do {
        displayMenu();
        
        // Read the user's choice
        printf("Enter your choice (1-5): ");
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5: ");
            clearInputBuffer();
        }

        // Only continue if choice is within valid range
        if (choice < 1 || choice > 5) {
            printf("Choice must be between 1 and 5. Please try again.\n");
            continue;
        }

        // Read numbers from the user
        printf("Enter first integer: ");
        while (scanf("%d", &num1) != 1) {
            printf("Invalid input. Please enter an integer: ");
            clearInputBuffer();
        }
        
        printf("Enter second integer: ");
        while (scanf("%d", &num2) != 1) {
            printf("Invalid input. Please enter an integer: ");
            clearInputBuffer();
        }

        // Perform operation based on user's choice
        switch (choice) {
            case 1:
                printf("Result of %d + %d = %d\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("Result of %d - %d = %d\n", num1, num2, subtract(num1, num2));
                break;
            case 3:
                printf("Result of %d * %d = %d\n", num1, num2, multiply(num1, num2));
                break;
            case 4:
                if (num2 != 0) {
                    printf("Result of %d / %d = %.2f\n", num1, num2, divide(num1, num2));
                } else {
                    printf("Error: Division by zero is not defined.\n");
                }
                break;
            case 5:
                if (num2 != 0) {
                    printf("Result of %d %% %d = %d\n", num1, num2, modulus(num1, num2));
                } else {
                    printf("Error: Division by zero is not defined for modulus.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        // Ask user if they want to continue
        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &continueChoice);
        
    } while (continueChoice == 'y' || continueChoice == 'Y');

    printf("Thank you for using the arithmetic calculator! Goodbye!\n");
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n==== Arithmetic Operations ====\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
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
float divide(int a, int b) {
    return (float)a / b;
}

// Function to calculate modulus of two numbers
int modulus(int a, int b) {
    return a % b;
}

// Function to clear the input buffer to prevent infinite loop on invalid input
void clearInputBuffer() {
    while (getchar() != '\n') {
        // Clear the input buffer
    }
}