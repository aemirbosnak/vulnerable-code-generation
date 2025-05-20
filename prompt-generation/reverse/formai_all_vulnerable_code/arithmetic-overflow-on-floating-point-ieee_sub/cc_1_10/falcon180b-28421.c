//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, choice;
    double num1, num2, result;

    printf("Enter the number of problems you want to solve: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProblem %d:\n", i+1);
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);

        printf("Enter the operation you want to perform:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Square root\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                }
                break;
            case 5:
                if (num1 < 0) {
                    printf("Error: Square root of negative number is not allowed.\n");
                } else {
                    result = sqrt(num1);
                    printf("Result: %.2lf\n", result);
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}