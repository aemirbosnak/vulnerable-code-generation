//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display_menu() {
    printf("Welcome to the Math Exercise Program!\n");
    printf("Select an option:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
}

void addition() {
    double a, b;
    printf("Enter two numbers for addition:\n");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2lf + %.2lf = %.2lf\n", a, b, a + b);
}

void subtraction() {
    double a, b;
    printf("Enter two numbers for subtraction:\n");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2lf - %.2lf = %.2lf\n", a, b, a - b);
}

void multiplication() {
    double a, b;
    printf("Enter two numbers for multiplication:\n");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2lf * %.2lf = %.2lf\n", a, b, a * b);
}

void division() {
    double a, b;
    printf("Enter two numbers for division:\n");
    scanf("%lf %lf", &a, &b);
    if (b == 0) {
        printf("Error: Division by zero is not allowed.\n");
    } else {
        printf("Result: %.2lf / %.2lf = %.2lf\n", a, b, a / b);
    }
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                running = false;
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("\n");
    }

    return 0;
}