//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>

// Function prototypes
void displayMenu();
int getChoice();
void getNumbers(double *num1, double *num2);
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    int choice;
    double num1, num2, result;

    printf("Welcome to the Modular Arithmetic Program\n");
    
    do {
        displayMenu();
        choice = getChoice();

        if (choice >= 1 && choice <= 4) {
            getNumbers(&num1, &num2);
        }

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Arithmetic Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

// Function to get user's choice
int getChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to get two numbers from the user
void getNumbers(double *num1, double *num2) {
    printf("Enter the first number: ");
    scanf("%lf", num1);
    printf("Enter the second number: ");
    scanf("%lf", num2);
}

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    return a / b;
}