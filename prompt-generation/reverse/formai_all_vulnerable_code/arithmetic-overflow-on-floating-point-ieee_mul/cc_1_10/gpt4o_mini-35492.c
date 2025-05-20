//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void add(double a, double b) {
    printf("Result: %.2f\n", a + b);
}

void subtract(double a, double b) {
    printf("Result: %.2f\n", a - b);
}

void multiply(double a, double b) {
    printf("Result: %.2f\n", a * b);
}

void divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero is not allowed!\n");
    } else {
        printf("Result: %.2f\n", a / b);
    }
}

void displayMenu() {
    printf("Welcome to the Simple Calculator!\n");
    printf("Choose an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    double num1, num2;

    while (1) {
        displayMenu();
        
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 5.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input! Please enter valid numbers.\n");
                    while(getchar() != '\n'); // clear input buffer
                    continue;
                }
                add(num1, num2);
                break;

            case 2:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input! Please enter valid numbers.\n");
                    while(getchar() != '\n'); // clear input buffer
                    continue;
                }
                subtract(num1, num2);
                break;

            case 3:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input! Please enter valid numbers.\n");
                    while(getchar() != '\n'); // clear input buffer
                    continue;
                }
                multiply(num1, num2);
                break;

            case 4:
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input! Please enter valid numbers.\n");
                    while(getchar() != '\n'); // clear input buffer
                    continue;
                }
                divide(num1, num2);
                break;

            case 5:
                printf("Exiting the calculator. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please choose an option between 1 and 5.\n");
        }
        printf("\n");
    }
    return 0;
}