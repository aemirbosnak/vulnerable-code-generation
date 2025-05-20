//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of cases
#define NUM_CASES 10

// Define the function to calculate the square root using the Newton-Raphson method
double sqrt_newton(double x, double eps) {
    double guess = x / 2.0;
    while (abs(guess * guess - x) > eps) {
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

// Define the function to calculate the square root using the binary search method
double sqrt_binary(double x) {
    double low = 0.0;
    double high = x;
    while (low <= high) {
        double mid = (low + high) / 2.0;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid < x) {
            low = mid + 0.0001;
        } else {
            high = mid - 0.0001;
        }
    }
    return -1.0; // Square root not found
}

int main() {
    int i;
    double x, result;

    // Prompt the user to enter the number of cases
    printf("Enter the number of cases: ");
    scanf("%d", &i);

    // Check if the number of cases is within the valid range
    if (i < 1 || i > NUM_CASES) {
        printf("Invalid number of cases.\n");
        return 1;
    }

    // Loop through the cases
    for (int j = 1; j <= i; j++) {
        // Prompt the user to enter the number
        printf("Enter case %d:\n", j);
        scanf("%lf", &x);

        // Calculate the square root using the Newton-Raphson method
        result = sqrt_newton(x, 0.0001);

        // Print the result
        printf("The square root of %g using the Newton-Raphson method is %g.\n", x, result);

        // Calculate the square root using the binary search method
        result = sqrt_binary(x);

        // Print the result
        if (result == -1.0) {
            printf("The square root of %g using the binary search method is not found.\n", x);
        } else {
            printf("The square root of %g using the binary search method is %g.\n", x, result);
        }
    }

    return 0;
}