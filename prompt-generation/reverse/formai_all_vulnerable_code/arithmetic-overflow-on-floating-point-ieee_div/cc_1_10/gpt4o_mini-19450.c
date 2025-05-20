//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants for operation
#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4

// Function declarations
void displayMenu();
int getOperation();
double performOperation(double a, double b, int operation);
void clearBuffer();

// Main function
int main() {
    double num1, num2, result;
    int operation;

    while (1) {
        displayMenu();
        operation = getOperation();

        if (operation == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter the first number: ");
        scanf("%lf", &num1);
        clearBuffer();
        printf("Enter the second number: ");
        scanf("%lf", &num2);
        clearBuffer();

        result = performOperation(num1, num2, operation);
        if (operation == DIVIDE && num2 == 0) {
            printf("Error: Division by zero is not allowed.\n");
        } else {
            printf("The result is: %.2lf\n", result);
        }
    }

    return 0;
}

// Function to display the menu options
void displayMenu() {
    printf("\n------ Mathematical Operations ------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Select an operation (1-5): ");
}

// Function to get the user's operation choice
int getOperation() {
    int operation;
    scanf("%d", &operation);
    clearBuffer();
    return operation;
}

// Function to perform the selected operation
double performOperation(double a, double b, int operation) {
    switch (operation) {
        case ADD:
            return a + b;
        case SUBTRACT:
            return a - b;
        case MULTIPLY:
            return a * b;
        case DIVIDE:
            return a / b;
        default:
            printf("Invalid operation selected.\n");
            return 0.0;
    }
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n');
}