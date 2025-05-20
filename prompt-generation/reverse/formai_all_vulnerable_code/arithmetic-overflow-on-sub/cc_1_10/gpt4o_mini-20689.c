//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void displayMenu();
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();
int getIntegerInput(char *prompt);

int main() {
    int choice;
    while (1) {
        displayMenu();
        choice = getIntegerInput("Enter your choice (1-5 or 0 to exit): ");

        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 0:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Basic Arithmetic Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("0. Exit\n");
}

int getIntegerInput(char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        printf("Invalid input! Please enter an integer: ");
        while(getchar() != '\n'); // clear the input buffer
    }
    return value;
}

void performAddition() {
    int num1 = getIntegerInput("Enter the first number: ");
    int num2 = getIntegerInput("Enter the second number: ");
    printf("Result: %d + %d = %d\n", num1, num2, num1 + num2);
}

void performSubtraction() {
    int num1 = getIntegerInput("Enter the first number: ");
    int num2 = getIntegerInput("Enter the second number: ");
    printf("Result: %d - %d = %d\n", num1, num2, num1 - num2);
}

void performMultiplication() {
    int num1 = getIntegerInput("Enter the first number: ");
    int num2 = getIntegerInput("Enter the second number: ");
    printf("Result: %d * %d = %d\n", num1, num2, num1 * num2);
}

void performDivision() {
    int num1 = getIntegerInput("Enter the numerator (first number): ");
    int num2 = getIntegerInput("Enter the denominator (second number): ");
    
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %d / %d = %.2f\n", num1, num2, (float)num1 / num2);
    }
}