//FormAI DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int num1, num2, choice;
    float result;

    printf("Welcome to Torvalds Calculator!\n");
    printf("Choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (choice) {
        case 1:
            // Addition
            result = num1 + num2;
            printf("%d + %d = %.2f\n", num1, num2, result);
            break;

        case 2:
            // Subtraction
            result = num1 - num2;
            printf("%d - %d = %.2f\n", num1, num2, result);
            break;

        case 3:
            // Multiplication
            result = num1 * num2;
            printf("%d * %d = %.2f\n", num1, num2, result);
            break;

        case 4:
            // Division
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
            } else {
                result = (float) num1 / num2;
                printf("%d / %d = %.2f\n", num1, num2, result);
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    printf("Thank you for using Torvalds Calculator!\n");

    return 0;
}