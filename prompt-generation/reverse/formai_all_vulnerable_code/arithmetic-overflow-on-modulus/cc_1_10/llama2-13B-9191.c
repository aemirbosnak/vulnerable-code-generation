//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define N 10

// Function to calculate the greatest common divisor of two integers
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to calculate the Euclidean algorithm
int euclidean(int a, int b) {
    int r = a % b;
    return r == 0 ? b : euclidean(b, r);
}

// Function to calculate the extended Euclidean algorithm
int euclidean_ext(int a, int b, int *x, int *y) {
    int r = a % b;
    *x = r == 0 ? 1 : *x;
    *y = r == 0 ? 0 : *y - (*x * (b / r));
    return r;
}

int main() {
    int a, b, x, y;
    scanf("%d%d", &a, &b);

    // Calculate the greatest common divisor
    int gcd_a = gcd(a, b);
    int gcd_b = gcd(b, a);

    // Calculate the Euclidean algorithm
    int euclidean_a = euclidean(a, b);
    int euclidean_b = euclidean(b, a);

    // Calculate the extended Euclidean algorithm
    int x_a, y_a;
    euclidean_ext(a, b, &x_a, &y_a);
    int x_b, y_b;
    euclidean_ext(b, a, &x_b, &y_b);

    // Print the results
    printf("Greatest common divisor: %d\n", gcd_a);
    printf("Euclidean algorithm: a = %d, b = %d, x = %d, y = %d\n",
           a, b, x_a, y_a);
    printf("Euclidean algorithm: b = %d, a = %d, x = %d, y = %d\n",
           b, a, x_b, y_b);

    return 0;
}