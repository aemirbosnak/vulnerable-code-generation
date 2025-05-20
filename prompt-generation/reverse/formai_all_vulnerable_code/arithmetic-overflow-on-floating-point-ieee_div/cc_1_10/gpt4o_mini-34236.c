//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: genius
#include <stdio.h>

void displayMenu() {
    printf("----- Genius Arithmetic Calculator -----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("----------------------------------------\n");
    printf("Please choose an operation (1-5): ");
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

void performOperation(int choice) {
    double num1, num2, result;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            result = divide(num1, num2);
            if (num2 != 0) {
                printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;
        case 5:
            printf("Exiting the calculator. Goodbye!\n");
            break;
        default:
            printf("Invalid choice! Please select a number between 1 and 5.\n");
    }
}

int main() {
    int userChoice;

    do {
        displayMenu();
        scanf("%d", &userChoice);
        if (userChoice != 5) {
            performOperation(userChoice);
        }
    } while (userChoice != 5);

    return 0;
}