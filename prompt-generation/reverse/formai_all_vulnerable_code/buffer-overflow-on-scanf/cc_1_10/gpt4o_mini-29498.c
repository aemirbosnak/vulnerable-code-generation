//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayFibonacci(int n) {
    int a = 0, b = 1, next;
    printf("\nFibonacci Sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // The first two Fibonacci numbers are 0 and 1
        } else {
            next = a + b; // The next number is the sum of the last two
            a = b;  // Update a and b for the next iteration
            b = next;
        }
        printf("%d ", next); // Print the current Fibonacci number
    }
    printf("\n");
}

void visualizeFibonacci(int n) {
    int a = 0, b = 1, next;
    printf("\nVisual Representation of Fibonacci Sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = a + b;
            a = b;
            b = next;
        }
        // Visualization: Print asterisks corresponding to each Fibonacci number
        for (int j = 0; j < next; j++) {
            printf("*");
        }
        printf(" (%d)\n", next); // Print the Fibonacci number
    }
}

double calculateGoldenRatio(int n) {
    double phi = (1 + sqrt(5)) / 2; // Golden Ratio
    return phi;
}

void displayGoldenRatio(int n) {
    printf("\nCalculating Golden Ratio:\n");
    double ratio;
    for (int i = 2; i < n; i++) {
        double fib_i = (i <= 1) ? i : (fib_i = (pow(calculateGoldenRatio(i - 1), i) - pow(-calculateGoldenRatio(i - 1), -i)) / sqrt(5));
        double fib_i_minus_1 = (i - 1 <= 1) ? (i - 1) : (fib_i_minus_1 = (pow(calculateGoldenRatio(i - 2), i - 1) - pow(-calculateGoldenRatio(i - 2), -(i - 1))) / sqrt(5));
        ratio = fib_i / fib_i_minus_1;
        printf("F(%d) / F(%d) ≈ %.5f\n", i, i - 1, ratio);
    }
}

int main() {
    int n;
    printf("Enter the number of terms for Fibonacci Sequence visualization: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer greater than zero.\n");
        return 1;
    }

    displayFibonacci(n);
    visualizeFibonacci(n);
    displayGoldenRatio(n);

    return 0;
}