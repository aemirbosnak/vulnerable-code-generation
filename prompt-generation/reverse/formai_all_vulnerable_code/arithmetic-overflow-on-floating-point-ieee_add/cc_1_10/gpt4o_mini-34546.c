//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayMenu();
void performBasicOperations();
void performTrigonometricOperations();
void performLogarithmicOperations();
void handleInvalidInput();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                performBasicOperations();
                break;
            case 2:
                performTrigonometricOperations();
                break;
            case 3:
                performLogarithmicOperations();
                break;
            case 4:
                printf("Exiting the calculator. Goodbye!\n");
                break;
            default:
                handleInvalidInput();
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("=== Scientific Calculator ===\n");
    printf("1. Basic Operations\n");
    printf("2. Trigonometric Functions\n");
    printf("3. Logarithmic Functions\n");
    printf("4. Exit\n");
}

void performBasicOperations() {
    double num1, num2;
    char operator;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (operator) {
        case '+':
            printf("Result: %lf\n", num1 + num2);
            break;
        case '-':
            printf("Result: %lf\n", num1 - num2);
            break;
        case '*':
            printf("Result: %lf\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Result: %lf\n", num1 / num2);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        default:
            printf("Invalid operator!\n");
    }
}

void performTrigonometricOperations() {
    double angle, result;
    int choice;

    printf("Choose a trigonometric function:\n");
    printf("1. Sine\n");
    printf("2. Cosine\n");
    printf("3. Tangent\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the angle in degrees: ");
    scanf("%lf", &angle);
    angle = angle * (M_PI / 180.0); // Convert to radians

    switch (choice) {
        case 1:
            result = sin(angle);
            printf("Sine(%lf degrees) = %lf\n", angle * (180.0 / M_PI), result);
            break;
        case 2:
            result = cos(angle);
            printf("Cosine(%lf degrees) = %lf\n", angle * (180.0 / M_PI), result);
            break;
        case 3:
            result = tan(angle);
            printf("Tangent(%lf degrees) = %lf\n", angle * (180.0 / M_PI), result);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void performLogarithmicOperations() {
    double num;
    int choice;

    printf("Choose a logarithmic function:\n");
    printf("1. Natural Log (ln)\n");
    printf("2. Logarithm Base 10 (log10)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter a number: ");
    scanf("%lf", &num);

    switch (choice) {
        case 1:
            if (num > 0) {
                printf("ln(%lf) = %lf\n", num, log(num));
            } else {
                printf("Error: Natural log of non-positive numbers is invalid.\n");
            }
            break;
        case 2:
            if (num > 0) {
                printf("log10(%lf) = %lf\n", num, log10(num));
            } else {
                printf("Error: Logarithm base 10 of non-positive numbers is invalid.\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void handleInvalidInput() {
    printf("Invalid input! Please try again.\n");
}