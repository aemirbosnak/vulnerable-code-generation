//FormAI DATASET v1.0 Category: Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to Brave Calculations!\n");

    int choice;
    float num1, num2, result;

    do {
        printf("\nChoose an operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter two numbers separated by space: ");
                scanf("%f %f", &num1, &num2);
                result = num1 + num2;
                printf("The result is %.2f\n", result);
                break;
            case 2:
                printf("\nEnter two numbers separated by space: ");
                scanf("%f %f", &num1, &num2);
                result = num1 - num2;
                printf("The result is %.2f\n", result);
                break;
            case 3:
                printf("\nEnter two numbers separated by space: ");
                scanf("%f %f", &num1, &num2);
                result = num1 * num2;
                printf("The result is %.2f\n", result);
                break;
            case 4:
                printf("\nEnter two numbers separated by space: ");
                scanf("%f %f", &num1, &num2);
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("The result is %.2f\n", result);
                } else {
                    printf("Cannot divide by zero!\n");
                }
                break;
            case 5:
                printf("\nThank you for using Brave Calculations!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}