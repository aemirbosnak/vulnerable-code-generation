//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Configuration macros
#define MAX_NUM 100
#define MIN_NUM 1
#define MAX_OPERATIONS 5

// Function prototypes
void welcomeMessage();
void displayMenu();
int getUserChoice();
void performOperation(int choice, double num1, double num2);
void addition(double num1, double num2);
void subtraction(double num1, double num2);
void multiplication(double num1, double num2);
void division(double num1, double num2);
void squareRoot(double num);
void randomOperations(int count);

int main() {
    srand(time(NULL)); // Seed for random number generation
    welcomeMessage();
    
    int choice;
    double num1, num2;
    
    do {
        displayMenu();
        choice = getUserChoice();
        
        if (choice >= 1 && choice <= 5) {
            num1 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
            num2 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
            performOperation(choice, num1, num2);
        } else if (choice == 6) {
            int opCount;
            printf("How many random operations would you like to perform? ");
            scanf("%d", &opCount);
            if (opCount > 0) {
                randomOperations(opCount);
            } else {
                printf("Invalid count! Please enter a positive number.\n");
            }
        } else if (choice != 7) {
            printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 7);
    
    printf("Thank you for using the math program! Goodbye!\n");
    return 0;
}

// Welcome message
void welcomeMessage() {
    printf("*********************************\n");
    printf("Welcome to the Math Exercise Program!\n");
    printf("*********************************\n");
}

// Displaying menu options
void displayMenu() {
    printf("\nChoose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square Root\n");
    printf("6. Perform random operations\n");
    printf("7. Quit\n");
}

// Getting user choice
int getUserChoice() {
    int choice;
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);
    return choice;
}

// Perform chosen operation
void performOperation(int choice, double num1, double num2) {
    switch (choice) {
        case 1:
            addition(num1, num2);
            break;
        case 2:
            subtraction(num1, num2);
            break;
        case 3:
            multiplication(num1, num2);
            break;
        case 4:
            division(num1, num2);
            break;
        case 5:
            printf("Square root of %.2f is: %.2f\n", num1, sqrt(num1));
            break;
        default:
            printf("Unhandled operation.\n");
            break;
    }
}

// Addition function
void addition(double num1, double num2) {
    double result = num1 + num2;
    printf("%.2f + %.2f = %.2f\n", num1, num2, result);
}

// Subtraction function
void subtraction(double num1, double num2) {
    double result = num1 - num2;
    printf("%.2f - %.2f = %.2f\n", num1, num2, result);
}

// Multiplication function
void multiplication(double num1, double num2) {
    double result = num1 * num2;
    printf("%.2f * %.2f = %.2f\n", num1, num2, result);
}

// Division function
void division(double num1, double num2) {
    if (num2 != 0) {
        double result = num1 / num2;
        printf("%.2f / %.2f = %.2f\n", num1, num2, result);
    } else {
        printf("Error: Division by zero is undefined!\n");
    }
}

// Performing random operations
void randomOperations(int count) {
    for (int i = 0; i < count; i++) {
        int randomChoice = (rand() % MAX_OPERATIONS) + 1;
        double num1 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
        double num2 = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
        
        printf("\nRandom operation %d:\n", i + 1);
        performOperation(randomChoice, num1, num2);
    }
}