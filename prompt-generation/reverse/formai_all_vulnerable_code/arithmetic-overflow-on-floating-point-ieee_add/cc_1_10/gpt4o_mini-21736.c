//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("\n--- Arithmetic Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    printf("6. Factorial\n");
    printf("7. Exit\n");
    printf("----------------------------------\n");
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 0; // Returning 0 for safety; can be improved
    }
}

double exponentiate(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

unsigned long long factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 0; // Returning 0 for safety; can be improved
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int choice, exp;
    double num1, num2;
    
    while (1) {
        display_menu();
        printf("Select an option (1-7): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 7.\n");
            // Clearing input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: // Addition
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input. Please enter numerical values.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.2lf\n", add(num1, num2));
                break;

            case 2: // Subtraction
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input. Please enter numerical values.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.2lf\n", subtract(num1, num2));
                break;

            case 3: // Multiplication
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input. Please enter numerical values.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.2lf\n", multiply(num1, num2));
                break;

            case 4: // Division
                printf("Enter two numbers: ");
                if (scanf("%lf %lf", &num1, &num2) != 2) {
                    printf("Invalid input. Please enter numerical values.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.2lf\n", divide(num1, num2));
                break;

            case 5: // Exponentiation
                printf("Enter base and exponent (whole number): ");
                if (scanf("%lf %d", &num1, &exp) != 2) {
                    printf("Invalid input. Please enter a base and an integer exponent.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Result: %.2lf\n", exponentiate(num1, exp));
                break;

            case 6: // Factorial
                printf("Enter a non-negative integer: ");
                int factNum;
                if (scanf("%d", &factNum) != 1) {
                    printf("Invalid input. Please enter a non-negative integer.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Factorial of %d is: %llu\n", factNum, factorial(factNum));
                break;

            case 7: // Exit
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please choose between 1 to 7.\n");
        }
    }
    
    return 0;
}