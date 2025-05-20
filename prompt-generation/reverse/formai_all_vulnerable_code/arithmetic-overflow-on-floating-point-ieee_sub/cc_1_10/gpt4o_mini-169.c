//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void displayMenu();
void performOperation(int choice);
void addNumbers(double a, double b);
void subtractNumbers(double a, double b);
void multiplyNumbers(double a, double b);
void divideNumbers(double a, double b);

int main() {
    int choice;

    // Main loop for the program
    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Invalid input. Please enter a number between 1 and 5: ");
            while (getchar() != '\n'); // clear the input buffer
        }

        // Perform the corresponding operation based on user choice
        if (choice != 5) {
            performOperation(choice);
        }

    } while (choice != 5);

    printf("Thank you for using the calculator! Goodbye!\n");
    return 0;
}

// Function to display menu options to the user
void displayMenu() {
    printf("\n=== Simple Calculator ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}

// Function to handle operation selection by the user
void performOperation(int choice) {
    double num1, num2;

    // Input two numbers
    printf("Enter two numbers: ");
    while (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("Invalid input. Please enter two valid numbers: ");
        while (getchar() != '\n'); // clear the input buffer
    }

    // Perform the operation based on the user's choice
    switch (choice) {
        case 1:
            addNumbers(num1, num2);
            break;
        case 2:
            subtractNumbers(num1, num2);
            break;
        case 3:
            multiplyNumbers(num1, num2);
            break;
        case 4:
            divideNumbers(num1, num2);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

// Function to add two numbers
void addNumbers(double a, double b) {
    double result = a + b;
    printf("Result: %.2lf + %.2lf = %.2lf\n", a, b, result);
}

// Function to subtract two numbers
void subtractNumbers(double a, double b) {
    double result = a - b;
    printf("Result: %.2lf - %.2lf = %.2lf\n", a, b, result);
}

// Function to multiply two numbers
void multiplyNumbers(double a, double b) {
    double result = a * b;
    printf("Result: %.2lf * %.2lf = %.2lf\n", a, b, result);
}

// Function to divide two numbers
void divideNumbers(double a, double b) {
    if (b != 0) {
        double result = a / b;
        printf("Result: %.2lf / %.2lf = %.2lf\n", a, b, result);
    } else {
        printf("Error: Division by zero is not allowed!\n");
    }
}