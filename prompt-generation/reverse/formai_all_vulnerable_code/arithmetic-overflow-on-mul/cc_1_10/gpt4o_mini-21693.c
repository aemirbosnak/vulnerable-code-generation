//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
void displayMenu();
void performArithmetic(int choice);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);
void handleDivisonByZero(int b);
void clearBuffer();

// Structure to hold arithmetic data
typedef struct {
    int operand1;
    int operand2;
} ArithmeticData;

// Main function
int main() {
    int choice;

    // Introduction
    printf("Welcome to the C Arithmetic Program!\n");
    printf("This program performs various arithmetic operations.\n");
    
    do {
        displayMenu();
        printf("Select an option (1-5) or 0 to exit: ");
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 5) {
            performArithmetic(choice);
        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 0);

    printf("Thank you for using the program! Goodbye!\n");
    return 0;
}

// Display the arithmetic menu
void displayMenu() {
    printf("\n--- Arithmetic Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Complex Operation (Add then Multiply)\n");
    printf("-----------------------------------\n");
}

// Perform the selected arithmetic operation
void performArithmetic(int choice) {
    ArithmeticData data;
    printf("Enter first operand: ");
    scanf("%d", &data.operand1);
    printf("Enter second operand: ");
    scanf("%d", &data.operand2);
    
    switch (choice) {
        case 1:
            printf("Result of Addition: %d\n", add(data.operand1, data.operand2));
            break;
        case 2:
            printf("Result of Subtraction: %d\n", subtract(data.operand1, data.operand2));
            break;
        case 3:
            printf("Result of Multiplication: %d\n", multiply(data.operand1, data.operand2));
            break;
        case 4:
            handleDivisonByZero(data.operand2);
            printf("Result of Division: %.2f\n", divide(data.operand1, data.operand2));
            break;
        case 5:
            {
                int sum = add(data.operand1, data.operand2);
                printf("Intermediate Addition Result: %d\n", sum);
                printf("Result of Adding and then Multiplying: %d\n", multiply(sum, data.operand2));
                break;
            }
        default:
            // Should never reach here due to previous checks
            break;
    }
}

// Add two integers
int add(int a, int b) {
    return a + b;
}

// Subtract second integer from first
int subtract(int a, int b) {
    return a - b;
}

// Multiply two integers
int multiply(int a, int b) {
    return a * b;
}

// Divide first integer by second
double divide(int a, int b) {
    return (double)a / b; // Cast to double for decimal precision
}

// Handle division by zero logic
void handleDivisonByZero(int b) {
    if (b == 0) {
        printf("Error: Division by zero encountered! Please provide a valid divisor.\n");
        exit(EXIT_FAILURE);
    }
}

// Clear input buffer
void clearBuffer() {
    while (getchar() != '\n');
}