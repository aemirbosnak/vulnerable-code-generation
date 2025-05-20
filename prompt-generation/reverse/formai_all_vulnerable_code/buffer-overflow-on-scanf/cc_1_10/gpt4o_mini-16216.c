//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayMenu();
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();
void performModulus();
void performArithmeticOperations(int a, int b, char operator);

// Main function
int main() {
    int choice;
    srand(time(0));  // Seed for random number generation

    do {
        displayMenu();
        printf("Enter your choice (1-6, or 0 to exit): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6) {
            int a = rand() % 100;  // Random number between 0 - 99
            int b = rand() % 100;  // Random number between 0 - 99

            switch (choice) {
                case 1:
                    performAddition(a, b);
                    break;
                case 2:
                    performSubtraction(a, b);
                    break;
                case 3:
                    performMultiplication(a, b);
                    break;
                case 4:
                    performDivision(a, b);
                    break;
                case 5:
                    performModulus(a, b);
                    break;
                case 6:
                    printf("Both Operations: (Addition and Subtraction) between %d and %d:\n", a, b);
                    performArithmeticOperations(a, b, '+');
                    performArithmeticOperations(a, b, '-');
                    break;
                default:
                    break;
            }

            printf("\n");  // Blank line for better readability
        } else if (choice != 0) {
            printf("Invalid choice, please try again.\n\n");
        }

    } while (choice != 0);

    printf("Exiting the program. Goodbye!\n");
    return 0;
}

// Function to display menu
void displayMenu() {
    printf("********** Arithmetic Operations Menu **********\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Both Operations: Display Addition and Subtraction Results\n");
    printf("0. Exit\n");
    printf("***********************************************\n");
}

// Function to perform addition
void performAddition(int a, int b) {
    int result = a + b;
    printf("Addition: %d + %d = %d\n", a, b, result);
}

// Function to perform subtraction
void performSubtraction(int a, int b) {
    int result = a - b;
    printf("Subtraction: %d - %d = %d\n", a, b, result);
}

// Function to perform multiplication
void performMultiplication(int a, int b) {
    int result = a * b;
    printf("Multiplication: %d * %d = %d\n", a, b, result);
}

// Function to perform division
void performDivision(int a, int b) {
    if (b != 0) {
        float result = (float)a / (float)b;
        printf("Division: %d / %d = %.2f\n", a, b, result);
    } else {
        printf("Division: Division by zero is undefined!\n");
    }
}

// Function to perform modulus
void performModulus(int a, int b) {
    if (b != 0) {
        int result = a % b;
        printf("Modulus: %d %% %d = %d\n", a, b, result);
    } else {
        printf("Modulus: Modulus by zero is undefined!\n");
    }
}

// Function to perform arithmetic operations
void performArithmeticOperations(int a, int b, char operator) {
    if (operator == '+') {
        performAddition(a, b);
    } else if (operator == '-') {
        performSubtraction(a, b);
    }
}