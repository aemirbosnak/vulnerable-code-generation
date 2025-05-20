//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
int getChoice();
void performOperation(int choice, double num1, double num2);
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void clearInputBuffer();

int main() {
    double num1, num2;
    int choice;

    printf("Welcome to the Invasive Math Calculator!\n");

    while (1) {
        printf("Enter the first number: ");
        while (scanf("%lf", &num1) != 1) {
            printf("Invalid input. Please enter a valid number: ");
            clearInputBuffer(); // Clear invalid input
        }

        printf("Enter the second number: ");
        while (scanf("%lf", &num2) != 1) {
            printf("Invalid input. Please enter a valid number: ");
            clearInputBuffer(); // Clear invalid input
        }

        displayMenu();
        choice = getChoice();
        
        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        } else {
            performOperation(choice, num1, num2);
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nSelect an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*))\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
}

int getChoice() {
    int choice;
    
    printf("Enter your choice (1-5): ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
        printf("Invalid choice. Please select a valid option (1-5): ");
        clearInputBuffer(); // Clear invalid input
    }

    return choice;
}

void performOperation(int choice, double num1, double num2) {
    double result;

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 4:
            if (num2 != 0) {
                result = divide(num1, num2);
                printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            } else {
                printf("Error: Division by zero is undefined.\n");
            }
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}