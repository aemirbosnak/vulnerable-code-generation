//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

// Function to calculate GCD of two integers using recursion
int gcd(int a, int b) {
    // Base case
    if (b == 0) {
        return a;
    }
    // Recursive case
    return gcd(b, a % b);
}

// Function to find factorial of a number using recursion
long long factorial(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

// Function to calculate power of a number using recursion
double power(double base, int exponent) {
    // Base case
    if (exponent == 0) {
        return 1.0;
    }
    // Recursive case for positive exponent
    if (exponent > 0) {
        return base * power(base, exponent - 1);
    }
    // Recursive case for negative exponent
    return 1.0 / power(base, -exponent);
}

// Main program to interactively use the recursive functions
int main() {
    int choice, num1, num2, factInput;
    double base;
    int exp;
    
    while (1) {
        printf("\n----- Recursive Function Menu -----\n");
        printf("1. Calculate GCD\n");
        printf("2. Calculate Factorial\n");
        printf("3. Calculate Power\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two integers (a b): ");
                scanf("%d %d", &num1, &num2);
                printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));
                break;
            case 2:
                printf("Enter a non-negative integer to calculate factorial: ");
                scanf("%d", &factInput);
                if (factInput < 0) {
                    printf("Factorial is not defined for negative numbers!\n");
                } else {
                    printf("Factorial of %d is: %lld\n", factInput, factorial(factInput));
                }
                break;
            case 3:
                printf("Enter base and exponent: ");
                scanf("%lf %d", &base, &exp);
                printf("%lf raised to the power of %d is: %lf\n", base, exp, power(base, exp));
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}