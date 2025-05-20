//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void printWelcomeMessage();
void printMenu();
int getChoice();
int performOperation(int choice, int a, int b);
void printResult(int result);

// The visionary arithmetic program
int main() {
    printWelcomeMessage();

    int a, b, result, choice;

    // Infinite loop for continuous execution
    while (1) {
        printMenu();
        choice = getChoice();

        // Exit condition
        if (choice == 0) {
            printf("Thank you for using the visionary arithmetic program. Exiting...\n");
            break;
        }
        
        printf("Enter the first number: ");
        scanf("%d", &a);
        printf("Enter the second number: ");
        scanf("%d", &b);

        result = performOperation(choice, a, b);
        printResult(result);
    }

    return 0;
}

void printWelcomeMessage() {
    printf("=============================================\n");
    printf("   Welcome to the Visionary Arithmetic Program\n");
    printf("=============================================\n\n");
    printf("This program allows you to perform basic arithmetic operations.\n");
    printf("You can choose from addition, subtraction, multiplication, and division.\n\n");
}

void printMenu() {
    printf("Choose an operation from the following menu:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int getChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

int performOperation(int choice, int a, int b) {
    int result = 0;
    
    switch (choice) {
        case 1:
            result = a + b;
            break;
        case 2:
            result = a - b;
            break;
        case 3:
            result = a * b;
            break;
        case 4:
            if (b != 0) {
                result = a / b;
            } else {
                printf("Error: Division by zero is not allowed!\n");
                result = 0; // indicating an error
            }
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            result = 0; // indicating an error
            break;
    }

    return result;
}

void printResult(int result) {
    if (result != 0) {
        printf("The result is: %d\n\n", result);
    }
}