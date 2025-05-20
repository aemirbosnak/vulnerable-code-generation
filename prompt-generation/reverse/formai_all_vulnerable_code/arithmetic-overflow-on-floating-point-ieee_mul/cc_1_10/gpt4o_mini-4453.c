//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: careful
#include <stdio.h>

// Function prototypes
void add(double a, double b);
void subtract(double a, double b);
void multiply(double a, double b);
void divide(double a, double b);
void displayMenu();
void performOperation(int choice, double a, double b);

int main() {
    double num1, num2;
    int choice;

    printf("Welcome to the Simple Arithmetic Calculator!\n");
    printf("Please enter the first number: ");
    scanf("%lf", &num1);
    printf("Please enter the second number: ");
    scanf("%lf", &num2);

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5) {
            performOperation(choice, num1, num2);
        } else if (choice != 6) {
            printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 6);

    printf("Thank you for using the calculator. Goodbye!\n");
    return 0;
}

void add(double a, double b) {
    printf("Result: %.2lf + %.2lf = %.2lf\n", a, b, a + b);
}

void subtract(double a, double b) {
    printf("Result: %.2lf - %.2lf = %.2lf\n", a, b, a - b);
}

void multiply(double a, double b) {
    printf("Result: %.2lf * %.2lf = %.2lf\n", a, b, a * b);
}

void divide(double a, double b) {
    if (b != 0) {
        printf("Result: %.2lf / %.2lf = %.2lf\n", a, b, a / b);
    } else {
        printf("Error: Division by zero is not allowed!\n");
    }
}

void displayMenu() {
    printf("\n----- Arithmetic Operations -----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Perform all operations\n");
    printf("6. Exit\n");
}

void performOperation(int choice, double a, double b) {
    switch (choice) {
        case 1:
            add(a, b);
            break;
        case 2:
            subtract(a, b);
            break;
        case 3:
            multiply(a, b);
            break;
        case 4:
            divide(a, b);
            break;
        case 5:
            add(a, b);
            subtract(a, b);
            multiply(a, b);
            divide(a, b);
            break;
        default:
            printf("This case should never be reached!\n");
            break;
    }
}