//FormAI DATASET v1.0 Category: Educational ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Decentralized calculator program
// This program allows users to perform simple arithmetic operations without relying on a centralized server or internet connection.

// Function declarations
void add(float a, float b);
void subtract(float a, float b);
void multiply(float a, float b);
void divide(float a, float b);

// Main function
int main()
{
    int choice;
    float num1, num2;

    do {
        printf("Choose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting calculator program.\n");
            exit(0);
        }

        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);

        switch (choice) {
            case 1:
                add(num1, num2);
                break;
            case 2:
                subtract(num1, num2);
                break;
            case 3:
                multiply(num1, num2);
                break;
            case 4:
                divide(num1, num2);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void add(float a, float b) {
    printf("%.2f + %.2f = %.2f\n", a, b, a + b);
}

void subtract(float a, float b) {
    printf("%.2f - %.2f = %.2f\n", a, b, a - b);
}

void multiply(float a, float b) {
    printf("%.2f * %.2f = %.2f\n", a, b, a * b);
}

void divide(float a, float b) {
    if (b == 0) {
        printf("Cannot divide by zero. Please try again.\n");
        return;
    }
    printf("%.2f / %.2f = %.2f\n", a, b, a / b);
}