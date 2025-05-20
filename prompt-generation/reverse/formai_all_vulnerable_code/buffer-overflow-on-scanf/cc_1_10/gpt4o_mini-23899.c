//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
void showMenu();
void performAddition();
void performSubtraction();
void performMultiplication();
void performDivision();
double safeDivision(double a, double b);

int main() {
    int choice;
    bool exit = false;

    while (!exit) {
        showMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                performAddition();
                break;
            case 2:
                performSubtraction();
                break;
            case 3:
                performMultiplication();
                break;
            case 4:
                performDivision();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit = true;
                break;
            default:
                printf("Invalid choice! Please select a valid option (1-5).\n");
                break;
        }
    }

    return 0;
}

void showMenu() {
    printf("\n=== Arithmetic Operations Menu ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}

void performAddition() {
    double a, b;
    printf("Enter two numbers to add: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        fprintf(stderr, "Invalid input! Please enter two numbers.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf + %.2lf = %.2lf\n", a, b, a + b);
}

void performSubtraction() {
    double a, b;
    printf("Enter two numbers to subtract: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        fprintf(stderr, "Invalid input! Please enter two numbers.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf - %.2lf = %.2lf\n", a, b, a - b);
}

void performMultiplication() {
    double a, b;
    printf("Enter two numbers to multiply: ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        fprintf(stderr, "Invalid input! Please enter two numbers.\n");
        while (getchar() != '\n');
        return;
    }
    printf("Result: %.2lf * %.2lf = %.2lf\n", a, b, a * b);
}

void performDivision() {
    double a, b;
    printf("Enter two numbers to divide (numerator and denominator): ");
    if (scanf("%lf %lf", &a, &b) != 2) {
        fprintf(stderr, "Invalid input! Please enter two numbers.\n");
        while (getchar() != '\n');
        return;
    }
    
    double result = safeDivision(a, b);
    if (b != 0) {
        printf("Result: %.2lf / %.2lf = %.2lf\n", a, b, result);
    }
}

double safeDivision(double a, double b) {
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero is undefined!\n");
        return 0;  // Return a default value; real applications might handle this differently.
    }
    return a / b;
}