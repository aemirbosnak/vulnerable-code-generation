//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: interoperable
#include <stdio.h>

// Function to perform basic arithmetic operations
void performArithmetic(float num1, float num2) {
    float addition, subtraction, multiplication, division;

    addition = num1 + num2;
    subtraction = num1 - num2;
    multiplication = num1 * num2;

    if (num2 != 0) {
        division = num1 / num2;
        printf("Division: %.2f / %.2f = %.2f\n", num1, num2, division);
    } else {
        printf("Division by zero is not allowed.\n");
    }

    printf("Results:\n");
    printf("Addition: %.2f + %.2f = %.2f\n", num1, num2, addition);
    printf("Subtraction: %.2f - %.2f = %.2f\n", num1, num2, subtraction);
    printf("Multiplication: %.2f * %.2f = %.2f\n", num1, num2, multiplication);
}

// Function to get user input for numbers
void getNumbers(float *num1, float *num2) {
    printf("Enter first number: ");
    scanf("%f", num1);
    printf("Enter second number: ");
    scanf("%f", num2);
}

// Function to display menu and get user choice
int displayMenu() {
    int choice;
    printf("\n--- Arithmetic Operations Menu ---\n");
    printf("1. Perform Arithmetic Operations\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    return choice;
}

// Function to handle operations based on user choices
void handleOperations() {
    float num1, num2;
    int choice;

    while (1) {
        choice = displayMenu();
        switch (choice) {
            case 1:
                getNumbers(&num1, &num2);
                performArithmetic(num1, num2);
                break;
            case 2:
                printf("Exiting program. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the C Arithmetic Example Program!\n");
    handleOperations();
    return 0;
}