//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
long long int factorial(int n) {
    long long int result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

// Function to calculate the power of a number
double power(double base, int exponent) {
    double result = 1.0;

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int main() {
    int n;

    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate the factorial of the input number
    long long int fact = factorial(n);

    // Calculate the sum of the digits of the factorial
    int sum = 0;
    while (fact > 0) {
        sum += fact % 10;
        fact /= 10;
    }

    // Calculate the power of the input number
    double powerResult = power(n, sum);

    // Print the result
    printf("The power of %d to the sum of its digits (%d) is %.2f\n", n, sum, powerResult);

    return 0;
}