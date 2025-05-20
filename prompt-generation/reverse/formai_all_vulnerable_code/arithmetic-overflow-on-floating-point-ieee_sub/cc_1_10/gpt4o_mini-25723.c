//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\nSimple Calculator\n");
    printf("------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("------------------\n");
    printf("Choose an operation (1-5): ");
}

void addition() {
    double num1, num2, result;
    printf("Enter two numbers to add: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 + num2;
    printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
}

void subtraction() {
    double num1, num2, result;
    printf("Enter two numbers to subtract: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 - num2;
    printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
}

void multiplication() {
    double num1, num2, result;
    printf("Enter two numbers to multiply: ");
    scanf("%lf %lf", &num1, &num2);
    result = num1 * num2;
    printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
}

void division() {
    double num1, num2, result;
    printf("Enter two numbers to divide (numerator and denominator): ");
    scanf("%lf %lf", &num1, &num2);
    if (num2 != 0) {
        result = num1 / num2;
        printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
    } else {
        printf("Error: Division by zero is not allowed.\n");
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                printf("Exiting the calculator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}