//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    if (n < 0) {
        return 0; // Negative numbers do not have factorials
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the power of a number
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < abs(exponent); i++) {
        result *= base;
    }
    return (exponent < 0) ? 1.0 / result : result;
}

// Function to calculate combinations C(n, r)
unsigned long long combinations(int n, int r) {
    if (r > n || n < 0 || r < 0) {
        return 0;
    }
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate the sine of an angle in degrees
double sine(double angle) {
    double radians = angle * (M_PI / 180.0); // Convert to radians
    return sin(radians);
}

// Function to calculate the cosine of an angle in degrees
double cosine(double angle) {
    double radians = angle * (M_PI / 180.0); // Convert to radians
    return cos(radians);
}

// Function to calculate and display the Fibonacci sequence
void fibonacci(int n) {
    unsigned long long a = 0, b = 1, c;
    if (n <= 0) {
        printf("Fibonacci sequence for %d terms:\n", n);
        return;
    }
    printf("Fibonacci sequence for %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            printf("%llu ", i);
        } else {
            c = a + b;
            printf("%llu ", c);
            a = b;
            b = c;
        }
    }
    printf("\n");
}

// Main function for running the math program
int main() {
    int choice, n, r;
    double base;
    int exponent, angle, terms;

    do {
        printf("\nMath Exercise Program Options:\n");
        printf("1. Calculate Factorial\n");
        printf("2. Calculate Power\n");
        printf("3. Calculate Combinations (C(n, r))\n");
        printf("4. Calculate Sine of an Angle\n");
        printf("5. Calculate Cosine of an Angle\n");
        printf("6. Generate Fibonacci Sequence\n");
        printf("0. Exit\n");
        printf("Please select an option (0-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to find the factorial: ");
                scanf("%d", &n);
                printf("Factorial of %d is %llu\n", n, factorial(n));
                break;
            case 2:
                printf("Enter base and exponent (base exponent): ");
                scanf("%lf %d", &base, &exponent);
                printf("%lf to the power of %d is %lf\n", base, exponent, power(base, exponent));
                break;
            case 3:
                printf("Enter values for n and r (n r): ");
                scanf("%d %d", &n, &r);
                printf("C(%d, %d) is %llu\n", n, r, combinations(n, r));
                break;
            case 4:
                printf("Enter an angle in degrees to calculate sine: ");
                scanf("%d", &angle);
                printf("Sine of %d degrees is %lf\n", angle, sine(angle));
                break;
            case 5:
                printf("Enter an angle in degrees to calculate cosine: ");
                scanf("%d", &angle);
                printf("Cosine of %d degrees is %lf\n", angle, cosine(angle));
                break;
            case 6:
                printf("Enter the number of terms to generate the Fibonacci sequence: ");
                scanf("%d", &terms);
                fibonacci(terms);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}