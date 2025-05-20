//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int choice, i, j, n;
    double num1, num2, result;
    char again;

    do {
        printf("Welcome to the Arithmetic Calculator 3000!\n");
        printf("Please select an operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square root\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers to add:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result: %lf\n", result);
                break;
            case 2:
                printf("Enter two numbers to subtract:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result: %lf\n", result);
                break;
            case 3:
                printf("Enter two numbers to multiply:\n");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result: %lf\n", result);
                break;
            case 4:
                printf("Enter two numbers to divide:\n");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %lf\n", result);
                }
                break;
            case 5:
                printf("Enter a number to find the square root:\n");
                scanf("%lf", &num1);
                result = sqrt(num1);
                printf("Result: %lf\n", result);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    return 0;
}