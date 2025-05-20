//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("\n=== Arithmetic Operations Menu ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Exit\n");
    printf("Choose an operation (1-7): ");
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
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int modulus(int a, int b) {
    if (b == 0) {
        printf("Error: Modulus by zero!\n");
        return 0;
    }
    return a % b;
}

double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < abs(exponent); i++) {
        result *= base;
    }
    return (exponent < 0) ? 1.0 / result : result;
}

void performOperation(int choice) {
    double num1, num2;
    int intNum1, intNum2, exponent;

    switch (choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf\n", add(num1, num2));
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf\n", subtract(num1, num2));
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf\n", multiply(num1, num2));
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            printf("Result: %.2lf\n", divide(num1, num2));
            break;
        case 5:
            printf("Enter two integers: ");
            scanf("%d %d", &intNum1, &intNum2);
            printf("Result: %d\n", modulus(intNum1, intNum2));
            break;
        case 6:
            printf("Enter base and exponent: ");
            scanf("%lf %d", &num1, &exponent);
            printf("Result: %.2lf\n", power(num1, exponent));
            break;
        case 7:
            printf("Exiting program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice! Please choose between 1-7.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Arithmetic Operations Program!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        performOperation(choice);
    }

    return 0;
}