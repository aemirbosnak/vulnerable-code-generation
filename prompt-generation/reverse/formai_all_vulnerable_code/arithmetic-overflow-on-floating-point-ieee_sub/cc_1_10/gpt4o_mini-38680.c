//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>

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
        printf("Error: Division by zero is undefined.\n");
        return 0; // Return 0 when division by zero occurs
    }
    return a / b;
}

// Function to display the menu
void displayMenu() {
    printf("Welcome to Simple Calculator!\n");
    printf("Please select an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (x)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Exit if the user selects option 5
        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        // Get the numbers from the user
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        // Perform the selected operation
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
                result = divide(num1, num2);
                if (num2 != 0) { // Only print if division was valid
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}