//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the square root of a number using Newton's method
double sqrt_newton(double x) {
    double guess = x / 2.0;
    while (fabs(guess * guess - x) >= 0.00001) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

int main() {
    int choice;
    double num1, num2, result;

    printf("Welcome to the Math Exercise Program!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square root using Newton's method\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 + num2;
            printf("The result is: %lf\n", result);
            break;
        case 2:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 - num2;
            printf("The result is: %lf\n", result);
            break;
        case 3:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &num1, &num2);
            result = num1 * num2;
            printf("The result is: %lf\n", result);
            break;
        case 4:
            printf("Enter two numbers:\n");
            scanf("%lf %lf", &num1, &num2);
            if (num2 == 0) {
                printf("Cannot divide by zero!\n");
            } else {
                result = num1 / num2;
                printf("The result is: %lf\n", result);
            }
            break;
        case 5:
            printf("Enter a number:\n");
            scanf("%lf", &num1);
            result = sqrt_newton(num1);
            printf("The square root of %lf is: %lf\n", num1, result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}