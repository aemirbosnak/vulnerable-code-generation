//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void displayMenu();
char getOperation();
void performCalculation(char operation);
int isValidNumber(double number);
void clearInputBuffer();

int main() {
    char operation;
    do {
        displayMenu();
        operation = getOperation();

        // Process the operation unless the user decides to exit
        if (operation != '5') {
            performCalculation(operation);
        }
    } while (operation != '5');

    printf("Thank you for using the calculator. Goodbye!\n");
    return 0;
}

// Function to display the options menu
void displayMenu() {
    printf("\n---------- Simple Arithmetic Calculator ----------\n");
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

// Function to get the user's desired operation
char getOperation() {
    char operation;
    scanf(" %c", &operation);
    clearInputBuffer();
    return operation;
}

// Function to perform the arithmetic calculation
void performCalculation(char operation) {
    double num1, num2, result;

    printf("Enter first number: ");
    while (scanf("%lf", &num1) != 1 || !isValidNumber(num1)) {
        printf("Invalid input. Please enter a valid number: ");
        clearInputBuffer();
    }

    printf("Enter second number: ");
    while (scanf("%lf", &num2) != 1 || !isValidNumber(num2)) {
        printf("Invalid input. Please enter a valid number: ");
        clearInputBuffer();
    }

    switch (operation) {
        case '1':
            result = num1 + num2;
            printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '2':
            result = num1 - num2;
            printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '3':
            result = num1 * num2;
            printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '4':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid operation selected.\n");
    }
}

// Function to check if a number is valid (not NaN or Infinity)
int isValidNumber(double number) {
    return !(number != number || number == 1.0 / 0.0 || number == -1.0 / 0.0);
}

// Function to clear the input buffer
void clearInputBuffer() {
    while(getchar() != '\n');
}