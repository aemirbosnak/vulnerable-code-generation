//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void displayMenu();
void performArithmeticOperation(int choice);
void add();
void subtract();
void multiply();
void divide();
void modulus();
void exponentiation();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-6) or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 6) {
            printf("Invalid choice! Please try again.\n\n");
        } else {
            performArithmeticOperation(choice);
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Simple Arithmetic Operations Menu ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Exponentiation\n");
    printf("------------------------------------------\n");
}

void performArithmeticOperation(int choice) {
    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            multiply();
            break;
        case 4:
            divide();
            break;
        case 5:
            modulus();
            break;
        case 6:
            exponentiation();
            break;
        default:
            printf("Error in choice selection.\n");
            break;
    }
}

void add() {
    double num1, num2, result;

    printf("Enter two numbers for addition:\n");
    printf("Number 1: ");
    scanf("%lf", &num1);
    printf("Number 2: ");
    scanf("%lf", &num2);

    result = num1 + num2;
    printf("Result of %.2lf + %.2lf = %.2lf\n\n", num1, num2, result);
}

void subtract() {
    double num1, num2, result;

    printf("Enter two numbers for subtraction:\n");
    printf("Number 1: ");
    scanf("%lf", &num1);
    printf("Number 2: ");
    scanf("%lf", &num2);

    result = num1 - num2;
    printf("Result of %.2lf - %.2lf = %.2lf\n\n", num1, num2, result);
}

void multiply() {
    double num1, num2, result;

    printf("Enter two numbers for multiplication:\n");
    printf("Number 1: ");
    scanf("%lf", &num1);
    printf("Number 2: ");
    scanf("%lf", &num2);

    result = num1 * num2;
    printf("Result of %.2lf * %.2lf = %.2lf\n\n", num1, num2, result);
}

void divide() {
    double num1, num2, result;

    printf("Enter two numbers for division:\n");
    printf("Number 1: ");
    scanf("%lf", &num1);
    printf("Number 2: ");
    scanf("%lf", &num2);

    if (num2 != 0) {
        result = num1 / num2;
        printf("Result of %.2lf / %.2lf = %.2lf\n\n", num1, num2, result);
    } else {
        printf("Error: Division by zero is not allowed!\n\n");
    }
}

void modulus() {
    int num1, num2, result;

    printf("Enter two integers for modulus:\n");
    printf("Number 1: ");
    scanf("%d", &num1);
    printf("Number 2: ");
    scanf("%d", &num2);

    if (num2 != 0) {
        result = num1 % num2;
        printf("Result of %d %% %d = %d\n\n", num1, num2, result);
    } else {
        printf("Error: Modulo by zero is not allowed!\n\n");
    }
}

void exponentiation() {
    double base, exponent, result = 1.0;
    
    printf("Enter the base and exponent for exponentiation:\n");
    printf("Base: ");
    scanf("%lf", &base);
    printf("Exponent: ");
    scanf("%lf", &exponent);

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    printf("Result of %.2lf ^ %.2lf = %.2lf\n\n", base, exponent, result);
}