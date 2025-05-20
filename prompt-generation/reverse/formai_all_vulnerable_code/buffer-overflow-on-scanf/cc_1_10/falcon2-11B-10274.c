//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j, k, l;

    // Get input from user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Initialize array to store Fibonacci numbers
    int fib[n];
    for (i = 0; i < n; i++) {
        fib[i] = 0;
    }

    // Calculate Fibonacci numbers up to nth term
    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print Fibonacci sequence
    printf("Fibonacci sequence up to %dth term:\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Calculate x-coordinate of each term
    int x_coordinate[n];
    for (i = 0; i < n; i++) {
        x_coordinate[i] = i;
    }

    // Calculate y-coordinate of each term
    int y_coordinate[n];
    for (i = 0; i < n; i++) {
        y_coordinate[i] = (int)((-1 + sqrt(1 + 8 * fib[i])) / 2);
    }

    // Print visual representation of Fibonacci sequence
    printf("Visual representation of Fibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d %d\n", x_coordinate[i], y_coordinate[i]);
    }

    return 0;
}