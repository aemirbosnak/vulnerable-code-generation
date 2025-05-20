//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a given integer
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the value of PI using the Gauss-Legendre algorithm
double gaussLegendre(int n) {
    double x, y, z;
    x = 0.5 * (1 + sqrt(5));
    y = 0.5 * (1 - sqrt(5));
    z = 2 * x * y;
    for (int i = 0; i < n; i++) {
        x = x * z;
        y = y * z;
        z = x + y;
    }
    return z;
}

int main() {
    int n;
    double pi, x, y, z;

    // Ask the user for the value of n
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Calculate the factorial of n using the recursive formula
    pi = factorial(n);

    // Calculate the value of PI using the Gauss-Legendre algorithm
    x = 1;
    y = 1;
    z = 1;
    for (int i = 0; i < n; i++) {
        x = x * z;
        y = y * z;
        z = x + y;
    }
    pi = z;

    // Print the results
    printf("The factorial of %d is %d.\n", n, pi);

    return 0;
}