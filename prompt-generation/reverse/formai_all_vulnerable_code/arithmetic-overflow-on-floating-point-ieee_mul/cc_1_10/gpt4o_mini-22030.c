//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("Welcome to the Simple Arithmetic Calculator!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}

int get_choice() {
    int choice;
    printf("Enter your choice (1-5): ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
        printf("Invalid choice! Please enter a number between 1 and 5: ");
        while(getchar() != '\n'); // clear the input buffer
    }
    return choice;
}

double get_number(const char *prompt) {
    double number;
    printf("%s", prompt);
    while (scanf("%lf", &number) != 1) {
        printf("Invalid input! Please enter a valid number: ");
        while(getchar() != '\n'); // clear the input buffer
    }
    return number;
}

void perform_addition() {
    double num1 = get_number("Enter first number: ");
    double num2 = get_number("Enter second number: ");
    printf("Result: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
}

void perform_subtraction() {
    double num1 = get_number("Enter first number: ");
    double num2 = get_number("Enter second number: ");
    printf("Result: %.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
}

void perform_multiplication() {
    double num1 = get_number("Enter first number: ");
    double num2 = get_number("Enter second number: ");
    printf("Result: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
}

void perform_division() {
    double num1 = get_number("Enter numerator: ");
    double num2;
    do {
        num2 = get_number("Enter denominator (cannot be zero): ");
        if (num2 == 0) {
            printf("Error! Denominator cannot be zero.\n");
        }
    } while (num2 == 0);
    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
}

int main() {
    int choice;
    while (1) {
        display_menu();
        choice = get_choice();
        switch (choice) {
            case 1:
                perform_addition();
                break;
            case 2:
                perform_subtraction();
                break;
            case 3:
                perform_multiplication();
                break;
            case 4:
                perform_division();
                break;
            case 5:
                printf("Exiting the calculator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}