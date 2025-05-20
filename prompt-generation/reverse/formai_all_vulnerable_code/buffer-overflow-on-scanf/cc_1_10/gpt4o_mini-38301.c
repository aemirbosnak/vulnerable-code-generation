//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: modular
#include <stdio.h>

// Function prototypes
void displayMenu();
int getChoice();
void performOperation(int choice);
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void clearBuffer();

int main() {
    int choice;

    do {
        displayMenu();
        choice = getChoice();
        if (choice != 5) {
            performOperation(choice);
        }
    } while (choice != 5);

    printf("Exiting the calculator. Goodbye!\n");
    return 0;
}

// Function to display the calculator menu
void displayMenu() {
    printf("\n--- Simple Calculator ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

// Function to get user choice
int getChoice() {
    int choice;
    scanf("%d", &choice);
    clearBuffer(); // Clear the input buffer
    return choice;
}

// Function to perform operation based on user choice
void performOperation(int choice) {
    double num1, num2, result;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            if (num2 != 0) {
                result = divide(num1, num2);
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }
}

// Function to add two numbers
double add(double a, double b) {
    return a + b;
}

// Function to subtract two numbers
double subtract(double a, double b) {
    return a - b;
}

// Function to multiply two numbers
double multiply(double a, double b) {
    return a * b;
}

// Function to divide two numbers
double divide(double a, double b) {
    return a / b;
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n');
}