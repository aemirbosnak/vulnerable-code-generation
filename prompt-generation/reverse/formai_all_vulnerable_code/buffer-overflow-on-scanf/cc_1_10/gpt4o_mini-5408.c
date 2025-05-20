//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
void displayInstructions();
double calculateFactorial(int n);
double calculateExponential(double x, int terms);
double calculateSine(double x, int terms);
double calculateCosine(double x, int terms);
void displayResults(int n, double value, double sineResult, double cosineResult, double expResult);

int main() {
    int n;
    double value, sineResult, cosineResult, expResult;

    // Display instructions to the user
    displayInstructions();

    // Input value for calculations
    printf("Please enter a non-negative integer (n) for factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative integers.\n");
        return 1;
    }

    printf("Please enter a value (x) in radians for sine and cosine calculations: ");
    scanf("%lf", &value);

    // Perform calculations
    double factorialResult = calculateFactorial(n);
    sineResult = calculateSine(value, 10);
    cosineResult = calculateCosine(value, 10);
    expResult = calculateExponential(value, 10);
    
    // Display results
    displayResults(n, value, sineResult, cosineResult, expResult);
    
    return 0;
}

// Function Definitions

void displayInstructions() {
    printf("This program calculates the factorial of a non-negative integer,\n");
    printf("the sine and cosine of a given angle in radians, and the exponential of the value.\n");
    printf("It uses Taylor series expansions for sine, cosine, and exponential calculations.\n");
}

double calculateFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    }
    
    double result = 1.0;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

double calculateExponential(double x, int terms) {
    double result = 1.0; // e^0 = 1
    double term = 1.0; // Initial term x^0 / 0!

    for (int n = 1; n <= terms; n++) {
        term *= x / n; // Calculate the next term
        result += term; // Add the term to result
    }
    return result;
}

double calculateSine(double x, int terms) {
    double result = 0.0;
    double term = x; // First term is x

    for (int n = 0; n < terms; n++) {
        if (n != 0) {
            // Using the formula: (-1)^n * x^(2n+1) / (2n+1)!
            term *= -x * x / ((2 * n) * (2 * n + 1)); 
        }
        result += term; // Add the current term to the result
    }
    return result;
}

double calculateCosine(double x, int terms) {
    double result = 0.0;
    double term = 1.0; // First term is 1

    for (int n = 0; n < terms; n++) {
        if (n != 0) {
            // Using the formula: (-1)^n * x^(2n) / (2n)!
            term *= -x * x / ((2 * n - 1) * (2 * n));
        }
        result += term; // Add the current term to the result
    }
    return result;
}

void displayResults(int n, double value, double sineResult, double cosineResult, double expResult) {
    printf("\n--- Results ---\n");
    printf("Factorial of %d: %.0f\n", n, calculateFactorial(n));
    printf("Sine of %.2f: %.5f\n", value, sineResult);
    printf("Cosine of %.2f: %.5f\n", value, cosineResult);
    printf("Exponential of %.2f: %.5f\n", value, expResult);
    printf("----------------\n");
}