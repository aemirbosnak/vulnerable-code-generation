//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2, result;

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square root\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers to add:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 2:
            printf("Enter two numbers to subtract:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 3:
            printf("Enter two numbers to multiply:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case 4:
            printf("Enter two numbers to divide:\n");
            scanf("%lf %lf", &num1, &num2);
            if(num2 == 0) {
                printf("Cannot divide by zero.\n");
            } else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            break;
        case 5:
            printf("Enter a number to find the square root:\n");
            scanf("%lf", &num1);
            result = sqrt(num1);
            printf("Square root of %.2lf = %.2lf\n", num1, result);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}