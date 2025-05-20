//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>

void printWelcomeMessage();
void displayMenu();
void performArithmeticOperations(int choice);
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);
void repeatProgram();

int main() {
    printWelcomeMessage();
    displayMenu();
    return 0;
}

void printWelcomeMessage() {
    printf("**********************************************\n");
    printf("Welcome to the Genius Arithmetic Program!\n");
    printf("**********************************************\n");
    printf("Perform various arithmetic operations in a creative way!\n");
    printf("**********************************************\n");
}

void displayMenu() {
    int choice;
    while (1) {
        printf("\nPlease choose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        if (choice == 5) {
            printf("Thank you for using the Genius Arithmetic Program! Goodbye!\n");
            break;
        }

        performArithmeticOperations(choice);
    }
}

void performArithmeticOperations(int choice) {
    int num1, num2;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    switch (choice) {
        case 1:
            printf("Result of Addition (%d + %d): %d\n", num1, num2, add(num1, num2));
            break;
        case 2:
            printf("Result of Subtraction (%d - %d): %d\n", num1, num2, subtract(num1, num2));
            break;
        case 3:
            printf("Result of Multiplication (%d * %d): %d\n", num1, num2, multiply(num1, num2));
            break;
        case 4:
            if (num2 == 0) {
                printf("Error: Division by zero is undefined! Please try again.\n");
            } else {
                printf("Result of Division (%d / %d): %.2f\n", num1, num2, divide(num1, num2));
            }
            break;
        default:
            printf("Something went wrong. Please try again.\n");
            break;
    }
    repeatProgram();
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}

void repeatProgram() {
    char choice;
    printf("Would you like to perform another operation (y/n)? ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        displayMenu();
    } else {
        printf("Thank you for using the Genius Arithmetic Program! Have a great day!\n");
    }
}