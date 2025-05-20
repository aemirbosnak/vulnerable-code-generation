//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayMenu();
int getValidInteger(const char *prompt);
float getValidFloat(const char *prompt);
void performArithmetic(int choice, float num1, float num2);

int main() {
    int choice;
    float num1, num2;

    while (1) {
        displayMenu();

        // Get valid input for option
        choice = getValidInteger("Select an option (1-5): ");

        if (choice == 5) {
            printf("Exiting the program... Goodbye!\n");
            break;
        }

        // Get valid inputs for the two numbers
        num1 = getValidFloat("Enter the first number: ");
        num2 = getValidFloat("Enter the second number: ");

        performArithmetic(choice, num1, num2);
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Simple Calculator ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}

int getValidInteger(const char *prompt) {
    int value;
    char terminator;

    while (1) {
        printf("%s", prompt);
        if (scanf("%d%c", &value, &terminator) != 2 || terminator != '\n') {
            printf("Invalid input. Please enter an integer value.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    }
    return value;
}

float getValidFloat(const char *prompt) {
    float value;
    char terminator;

    while (1) {
        printf("%s", prompt);
        if (scanf("%f%c", &value, &terminator) != 2 || terminator != '\n') {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    }
    return value;
}

void performArithmetic(int choice, float num1, float num2) {
    switch (choice) {
        case 1:
            printf("Result: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
            break;
        case 2:
            printf("Result: %.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
            break;
        case 3:
            printf("Result: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
            break;
        case 4:
            if (num2 != 0) {
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
            } else {
                printf("Error: Division by zero is undefined.\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}