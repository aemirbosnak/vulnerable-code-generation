//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

void display_menu() {
    printf("Welcome to the C Arithmetic Program!\n");
    printf("1. Add two numbers\n");
    printf("2. Subtract two numbers\n");
    printf("3. Multiply two numbers\n");
    printf("4. Divide two numbers\n");
    printf("5. Calculate factorial\n");
    printf("6. Calculate power (a^b)\n");
    printf("7. Exit\n");
    printf("Please choose an option (1-7): ");
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
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return NAN;
    }
    return (float)a / b;
}

long long factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial of a negative number doesn't exist!\n");
        return -1;
    }
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < abs(exp); i++) {
        result *= base;
    }
    return (exp < 0) ? (1.0 / result) : result;
}

int main() {
    int choice, a, b;
    double base;
    int exp;

    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid choice.\n");
            // Clear invalid input from stdin
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers to add: ");
                scanf("%d %d", &a, &b);
                printf("Result: %d\n", add(a, b));
                break;

            case 2:
                printf("Enter two numbers to subtract: ");
                scanf("%d %d", &a, &b);
                printf("Result: %d\n", subtract(a, b));
                break;

            case 3:
                printf("Enter two numbers to multiply: ");
                scanf("%d %d", &a, &b);
                printf("Result: %d\n", multiply(a, b));
                break;

            case 4:
                printf("Enter two numbers to divide: ");
                scanf("%d %d", &a, &b);
                float result = divide(a, b);
                if (!isnan(result)) {
                    printf("Result: %.2f\n", result);
                }
                break;

            case 5:
                printf("Enter a number to calculate its factorial: ");
                scanf("%d", &a);
                long long fact = factorial(a);
                if (fact != -1) {
                    printf("Factorial of %d is %lld\n", a, fact);
                }
                break;

            case 6:
                printf("Enter base and exponent (a^b): ");
                scanf("%lf %d", &base, &exp);
                printf("%.2f ^ %d = %.2f\n", base, exp, power(base, exp));
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a number between 1 and 7.\n");
        }
    }
    return 0;
}