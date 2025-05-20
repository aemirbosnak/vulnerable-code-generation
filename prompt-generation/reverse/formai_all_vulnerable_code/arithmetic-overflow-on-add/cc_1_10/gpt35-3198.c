//FormAI DATASET v1.0 Category: Calculator ; Style: lively
#include <stdio.h>

int main() {
    printf("Welcome to the Lively Calculator!\n");
    printf("This calculator can add, subtract, multiply and divide two numbers.\n");

    int choice;

    do {
        printf("\nPlease select an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int a, b;
                printf("Enter two numbers to add:\n");
                scanf("%d %d", &a, &b);
                int result = a + b;
                printf("%d + %d = %d\n", a, b, result);
                break;
            }
            case 2: {
                int a, b;
                printf("Enter two numbers to subtract:\n");
                scanf("%d %d", &a, &b);
                int result = a - b;
                printf("%d - %d = %d\n", a, b, result);
                break;
            }
            case 3: {
                int a, b;
                printf("Enter two numbers to multiply:\n");
                scanf("%d %d", &a, &b);
                int result = a * b;
                printf("%d * %d = %d\n", a, b, result);
                break;
            }
            case 4: {
                int a, b;
                printf("Enter two numbers to divide:\n");
                scanf("%d %d", &a, &b);
                if (b == 0) {
                    printf("Cannot divide by zero\n");
                } else {
                    float result = (float) a / b;
                    printf("%d / %d = %.2f\n", a, b, result);
                }
                break;
            }
            case 5: {
                printf("Thank you for using the Lively Calculator!\n");
                break;
            }
            default: {
                printf("Invalid choice");
                break;
            }
        }
    } while (choice != 5);

    return 0;
}