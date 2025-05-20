//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("=== Simple Calculator ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("=========================\n");
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
        printf("Error: Division by zero is not allowed.\n");
        return 0; // Placeholder to indicate an error
    }
    return a / b;
}

void get_input(double* a, double* b) {
    printf("Enter first number: ");
    while (scanf("%lf", a) != 1) {
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n'); // clear invalid input
    }
    printf("Enter second number: ");
    while (scanf("%lf", b) != 1) {
        printf("Invalid input. Please enter a valid number: ");
        while (getchar() != '\n'); // clear invalid input
    }
}

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        display_menu();
        printf("Choose an operation (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            while (getchar() != '\n'); // clear invalid input
            continue;
        }

        if (choice == 5) {
            printf("Exiting the calculator. Thank you!\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please select an option between 1 and 5.\n");
            continue;
        }

        get_input(&num1, &num2);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case 4:
                result = divide(num1, num2);
                if (num2 != 0) {
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;
            default:
                printf("Unexpected error occurred.\n");
                break;
        }
    }
    
    return 0;
}