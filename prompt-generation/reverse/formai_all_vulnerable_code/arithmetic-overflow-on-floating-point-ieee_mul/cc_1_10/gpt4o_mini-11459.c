//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayMenu() {
    printf("\n--- Scientific Calculator ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Sine\n");
    printf("6. Cosine\n");
    printf("7. Tangent\n");
    printf("8. Logarithm (base 10)\n");
    printf("9. Square Root\n");
    printf("0. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an operation: ");
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
        printf("Error: Division by zero!\n");
        return NAN;
    }
}

double sine(double angle) {
    return sin(angle * M_PI / 180.0); // Convert to radians
}

double cosine(double angle) {
    return cos(angle * M_PI / 180.0); // Convert to radians
}

double tangent(double angle) {
    return tan(angle * M_PI / 180.0); // Convert to radians
}

double logarithm(double value) {
    if (value > 0) {
        return log10(value);
    } else {
        printf("Error: Logarithm of non-positive number!\n");
        return NAN;
    }
}

double squareRoot(double value) {
    if (value < 0) {
        printf("Error: Cannot take square root of negative number!\n");
        return NAN;
    }
    return sqrt(value);
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

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
                result = divide(num1, num2);
                if (!isnan(result)) {
                    printf("Result: %.2lf\n", result);
                }
                break;

            case 5:
                printf("Enter angle (in degrees): ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: %.2lf\n", result);
                break;

            case 6:
                printf("Enter angle (in degrees): ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: %.2lf\n", result);
                break;

            case 7:
                printf("Enter angle (in degrees): ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Result: %.2lf\n", result);
                break;

            case 8:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = logarithm(num1);
                if (!isnan(result)) {
                    printf("Result: %.2lf\n", result);
                }
                break;

            case 9:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = squareRoot(num1);
                if (!isnan(result)) {
                    printf("Result: %.2lf\n", result);
                }
                break;

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}