//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the square root of a number using Newton's method
double sqrt_newton(double num) {
    double guess = num / 2;
    while (fabs(guess * guess - num) >= 0.000001) {
        guess = (guess + num / guess) / 2;
    }
    return guess;
}

int main() {
    int choice, num, i;
    double result;

    // Loop until user chooses to exit
    while (1) {
        // Display menu
        printf("\n");
        printf("1. Square root using Newton's method\n");
        printf("2. Fibonacci series\n");
        printf("3. Factorial\n");
        printf("4. Exit\n");
        printf("\n");

        // Get user choice
        scanf("%d", &choice);

        // Perform chosen operation
        switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%lf", &num);
            result = sqrt_newton(num);
            printf("Square root of %.2lf is %.2lf\n", num, result);
            break;

        case 2:
            printf("Enter the number of terms: ");
            scanf("%d", &num);
            printf("Fibonacci series up to %d terms:\n", num);
            for (i = 0; i < num; i++) {
                printf("%d ", fibonacci(i));
            }
            printf("\n");
            break;

        case 3:
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("Factorial of %d is %d\n", num, factorial(num));
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Function to calculate the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}