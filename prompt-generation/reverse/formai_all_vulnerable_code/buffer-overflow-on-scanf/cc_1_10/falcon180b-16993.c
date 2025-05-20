//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the power of a number
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to calculate the square root of a number
double sqrt(double number) {
    return sqrt(number);
}

// Function to calculate the sum of a series using the power function
double sumOfSeries(double base, int exponent, int terms) {
    double result = 0.0;
    for (int i = 0; i < terms; i++) {
        result += power(base, i);
    }
    return result;
}

int main() {
    double base, exponent, sum;

    // Get user input for base and exponent
    printf("Enter the base number: ");
    scanf("%lf", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    // Calculate the power of the base number
    double result = power(base, exponent);

    // Print the result
    printf("The power of %.2lf to %d is %.2lf\n", base, exponent, result);

    // Get user input for number of terms
    printf("Enter the number of terms for the series: ");
    scanf("%d", &sum);

    // Calculate the sum of the series
    result = sumOfSeries(base, exponent, sum);

    // Print the result
    printf("The sum of the series %.2lf^0 to %.2lf^%d is %.2lf\n", base, base, exponent, result);

    return 0;
}