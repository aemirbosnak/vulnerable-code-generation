//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
void displayMenu();
void clearInputBuffer();

int main() {
    int choice, num1, num2;
    float result;

    // Display a welcome message
    printf("Welcome to the C Arithmetic Application!\n");
    printf("This program allows you to perform basic arithmetic operations.\n\n");

    while (1) {
        displayMenu();
        // Prompt the user to enter a choice
        printf("Enter your choice (1-5, or 0 to quit): ");
        scanf("%d", &choice);
        
        // To exit the loop, check if the user inputs 0
        if (choice == 0) {
            printf("Exiting the program. Thank you!\n");
            break;
        }

        // Check if the user input is valid
        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        // Prompt the user to enter two numbers
        printf("Enter the first number: ");
        scanf("%d", &num1);
        printf("Enter the second number: ");
        scanf("%d", &num2);

        // Perform the arithmetic operation based on the user's choice
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result of addition: %d + %d = %.2f\n\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result of subtraction: %d - %d = %.2f\n\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result of multiplication: %d * %d = %.2f\n\n", num1, num2, result);
                break;
            case 4:
                // Check for division by zero
                if (num2 == 0) {
                    printf("Error: Division by zero is undefined.\n\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result of division: %d / %d = %.2f\n\n", num1, num2, result);
                }
                break;
            case 5:
                printf("Exiting to the main menu...\n\n");
                break;
            default:
                printf("Unexpected error occurred!\n\n");
        }

        // Clear input buffer for any unintended input
        clearInputBuffer();
    }

    return 0;
}

// Function implementations

// Addition function
int add(int a, int b) {
    return a + b;
}

// Subtraction function
int subtract(int a, int b) {
    return a - b;
}

// Multiplication function
int multiply(int a, int b) {
    return a * b;
}

// Division function
float divide(int a, int b) {
    return (float)a / (float)b;
}

// Display menu options
void displayMenu() {
    printf("Arithmetic Operations Menu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Back to Main Menu\n");
    printf("0. Exit Program\n");
}

// Clear input buffer function
void clearInputBuffer() {
    while (getchar() != '\n'); // clear the buffer
}