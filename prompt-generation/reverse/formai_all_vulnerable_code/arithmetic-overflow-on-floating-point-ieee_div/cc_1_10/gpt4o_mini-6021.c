//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    printf("Welcome to the Simple Math Program!\n");
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Factorial\n");
    printf("6. Exit\n");
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
    if (b == 0) {
        printf("Error: Division by zero is undefined.\n");
        return 0;
    }
    return a / b;
}

long long factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int choice;
    do {
        showMenu();
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 6.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: {
                double a, b;
                printf("Enter two numbers for addition: ");
                scanf("%lf %lf", &a, &b);
                printf("Result: %.2lf\n", add(a, b));
                break;
            }
            case 2: {
                double a, b;
                printf("Enter two numbers for subtraction: ");
                scanf("%lf %lf", &a, &b);
                printf("Result: %.2lf\n", subtract(a, b));
                break;
            }
            case 3: {
                double a, b;
                printf("Enter two numbers for multiplication: ");
                scanf("%lf %lf", &a, &b);
                printf("Result: %.2lf\n", multiply(a, b));
                break;
            }
            case 4: {
                double a, b;
                printf("Enter two numbers for division: ");
                scanf("%lf %lf", &a, &b);
                printf("Result: %.2lf\n", divide(a, b));
                break;
            }
            case 5: {
                int n;
                printf("Enter a non-negative integer for factorial: ");
                scanf("%d", &n);
                long long result = factorial(n);
                if (result != -1) {
                    printf("Factorial of %d is %lld\n", n, result);
                }
                break;
            }
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }

        printf("\n");

    } while (choice != 6);
    
    return 0;
}