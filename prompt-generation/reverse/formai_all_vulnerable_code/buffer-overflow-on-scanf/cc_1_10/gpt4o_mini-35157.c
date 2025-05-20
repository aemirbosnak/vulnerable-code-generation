//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
long long factorial(int n) {
    if (n < 0) return -1; // Factorial not defined for negative numbers
    if (n == 0) return 1;
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the power of a base raised to an exponent
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < abs(exponent); i++) {
        result *= base;
    }
    return (exponent < 0) ? 1.0 / result : result;
}

// Function to calculate the n-th term of the Taylor series for e^x
double taylor_series_exp(double x, int terms) {
    double result = 0.0;
    for (int n = 0; n < terms; n++) {
        result += power(x, n) / factorial(n);
    }
    return result;
}

// Function to calculate sine using Taylor series
double taylor_series_sin(double x, int terms) {
    double result = 0.0;
    for (int n = 0; n < terms; n++) {
        int sign = (n % 2 == 0) ? 1 : -1;
        result += sign * (power(x, 2 * n + 1) / factorial(2 * n + 1));
    }
    return result;
}

// Function to calculate cosine using Taylor series
double taylor_series_cos(double x, int terms) {
    double result = 0.0;
    for (int n = 0; n < terms; n++) {
        int sign = (n % 2 == 0) ? 1 : -1;
        result += sign * (power(x, 2 * n) / factorial(2 * n));
    }
    return result;
}

// Main function
int main() {
    double x;
    int terms;

    printf("Welcome to the Mathematical Functions Program!\n");
    printf("Please enter the value of x (in radians) for calculations: ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid input. Exiting program.\n");
        return 1;
    }

    printf("Please enter the number of terms for the Taylor series: ");
    if (scanf("%d", &terms) != 1 || terms < 1) {
        printf("Invalid input. Number of terms should be a positive integer. Exiting program.\n");
        return 1;
    }

    double e_to_x = taylor_series_exp(x, terms);
    double sine_x = taylor_series_sin(x, terms);
    double cosine_x = taylor_series_cos(x, terms);

    printf("\nResults using Taylor series expansion:\n");
    printf("e^%lf ≈ %.10lf\n", x, e_to_x);
    printf("sin(%lf) ≈ %.10lf\n", x, sine_x);
    printf("cos(%lf) ≈ %.10lf\n", x, cosine_x);

    // Validating results using math.h library functions
    printf("\nValidation using math.h library:\n");
    printf("e^%lf = %.10lf\n", x, exp(x));
    printf("sin(%lf) = %.10lf\n", x, sin(x));
    printf("cos(%lf) = %.10lf\n", x, cos(x));

    printf("\nThank you for using the Mathematical Functions Program!\n");

    return 0;
}