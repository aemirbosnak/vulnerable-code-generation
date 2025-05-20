//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>

// Function declarations
void performArithmeticOperations(int choice, int a, int b);
void displayMenu();
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);
void modulus(int a, int b);
void handleExit();

// Main function
int main() {
    int choice, a, b;
    char again;

    printf("Welcome to the Introspective Arithmetic Program!\n");
    printf("This program will help you explore different arithmetic operations interactively.\n");
    
    do {
        displayMenu();
        printf("Please choose an operation (1-5): ");
        scanf("%d", &choice);

        // Input Validation for choice
        if (choice < 1 || choice > 5) {
            printf("Invalid choice! Please select a number between 1 and 5.\n");
            continue;
        }

        printf("Enter two integers for the operation: ");
        scanf("%d %d", &a, &b);

        // Perform the chosen arithmetic operation
        performArithmeticOperations(choice, a, b);

        // Ask user if they want to perform another operation
        printf("Would you like to perform another operation? (y/n): ");
        scanf(" %c", &again); // Note the space before %c to consume the newline character

    } while (again == 'y' || again == 'Y');
    
    handleExit();
    return 0;
}

// Function to display available operations
void displayMenu() {
    printf("\nAvailable Arithmetic Operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
}

// Function to perform the arithmetic operations based on the user's choice
void performArithmeticOperations(int choice, int a, int b) {
    switch (choice) {
        case 1:
            add(a, b);
            break;
        case 2:
            subtract(a, b);
            break;
        case 3:
            multiply(a, b);
            break;
        case 4:
            if (b != 0) {
                divide(a, b);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            if (b != 0) {
                modulus(a, b);
            } else {
                printf("Error: Modulus by zero is not allowed.\n");
            }
            break;
    }
}

// Function to add two integers
void add(int a, int b) {
    printf("The result of %d + %d = %d\n", a, b, a + b);
}

// Function to subtract two integers
void subtract(int a, int b) {
    printf("The result of %d - %d = %d\n", a, b, a - b);
}

// Function to multiply two integers
void multiply(int a, int b) {
    printf("The result of %d * %d = %d\n", a, b, a * b);
}

// Function to divide two integers
void divide(int a, int b) {
    printf("The result of %d / %d = %.2f\n", a, b, (float)a / b);
}

// Function to calculate modulus of two integers
void modulus(int a, int b) {
    printf("The result of %d %% %d = %d\n", a, b, a % b);
}

// Function to handle program termination gracefully
void handleExit() {
    printf("Thank you for using the Introspective Arithmetic Program! Goodbye!\n");
}