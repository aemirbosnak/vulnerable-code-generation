//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform basic arithmetic operations
void printArithmeticOperations(int a, int b) {
    printf("Performing arithmetic operations on %d and %d:\n", a, b);
    
    printf("1. Addition: %d + %d = %d\n", a, b, a + b);
    printf("2. Subtraction: %d - %d = %d\n", a, b, a - b);
    printf("3. Multiplication: %d * %d = %d\n", a, b, a * b);
    if (b != 0) {
        printf("4. Division: %d / %d = %f\n", a, b, (double)a / b);
    } else {
        printf("4. Division: Division by zero is not allowed!\n");
    }
    printf("5. Modulus: %d %% %d = %d\n", a, b, a % b);
    printf("\n");
}

// Function to generate random numbers
void generateRandomNumbers(int *a, int *b) {
    *a = rand() % 100 + 1; // Random number between 1 and 100
    *b = rand() % 100 + 1; // Random number between 1 and 100
}

// Function to display a menu for the user
void displayMenu() {
    printf("====================================================\n");
    printf("               Welcome to the Arithmetic Wizard!   \n");
    printf("====================================================\n");
    printf("1. Generate new random numbers\n");
    printf("2. Perform arithmetic operations\n");
    printf("3. Exit\n");
    printf("====================================================\n");
}

// Main function
int main() {
    int choice = 0;
    int a = 0, b = 0;
    
    // Initialize random number generator
    srand(time(NULL));
    
    while (choice != 3) {
        displayMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                generateRandomNumbers(&a, &b);
                printf("New random numbers generated: %d and %d\n", a, b);
                break;
            case 2:
                if (a == 0 && b == 0) {
                    printf("Please generate random numbers first!\n\n");
                } else {
                    printArithmeticOperations(a, b);
                }
                break;
            case 3:
                printf("Thank you for using Arithmetic Wizard! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    
    return 0;
}