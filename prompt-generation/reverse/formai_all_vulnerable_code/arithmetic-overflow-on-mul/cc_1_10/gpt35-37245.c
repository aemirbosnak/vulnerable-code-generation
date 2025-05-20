//FormAI DATASET v1.0 Category: Arithmetic ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {
    int opt, a, b, result;
    char cont;

    do {
        // Display Menu
        printf("\nSelect an arithmetic operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");

        // Get user input
        printf("Enter your choice (1-4): ");
        scanf("%d", &opt);

        // Get operands
        printf("Enter the first operand: ");
        scanf("%d", &a);
        printf("Enter the second operand: ");
        scanf("%d", &b);

        // Perform selected arithmetic operation
        switch (opt) {
            case 1: // Addition
                result = add(a, b);
                printf("%d + %d = %d\n", a, b, result);
                break;
            case 2: // Subtraction
                result = subtract(a, b);
                printf("%d - %d = %d\n", a, b, result);
                break;
            case 3: // Multiplication
                result = multiply(a, b);
                printf("%d * %d = %d\n", a, b, result);
                break;
            case 4: // Division
                result = divide(a, b);
                printf("%d / %d = %d\n", a, b, result);
                break;
            default:
                printf("Invalid option!\n");
                break;
        }

        // Ask if user wants to continue
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &cont); // space before %c to ignore whitespace

    } while (cont == 'y' || cont == 'Y');

    return 0;
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

int divide(int a, int b) {
    if (b == 0) {
        printf("Cannot divide by zero!\n");
        exit(1); // terminate program
    }
    return a / b;
}