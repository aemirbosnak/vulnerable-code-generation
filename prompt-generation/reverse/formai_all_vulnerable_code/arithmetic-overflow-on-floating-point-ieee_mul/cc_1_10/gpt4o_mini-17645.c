//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
long long factorial(int n);
double power(double base, int exp);

int main() {
    int choice, num;
    double num1, num2, result;

    // Display menu to the user
    while (1) {
        printf("\n=== Simple Calculator ===\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Factorial\n");
        printf("6. Power\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if(num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result: %.2lf\n", result);
                } else {
                    printf("Error! Division by zero is undefined.\n");
                }
                break;
            case 5:
                printf("Enter a non-negative integer: ");
                scanf("%d", &num);
                if (num >= 0) {
                    result = factorial(num);
                    printf("Factorial of %d is %lld\n", num, result);
                } else {
                    printf("Error! Factorial is not defined for negative numbers.\n");
                }
                break;
            case 6:
                printf("Enter base and exponent (base exp): ");
                scanf("%lf %d", &num1, &num);
                result = power(num1, num);
                printf("%.2lf raised to the power %d is %.2lf\n", num1, num, result);
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please select a correct option.\n");
        }
    }

    return 0;
}

// Function implementations
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
    return a / b;
}

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double power(double base, int exp) {
    double result = 1.0;
    for (int i = 0; i < abs(exp); i++) {
        result *= base;
    }
    return (exp < 0) ? 1 / result : result;
}