//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// function to generate Fibonacci sequence up to n terms
void generateFibonacciSequence(int n) {
    int i, j, k;
    long long int fib[50]; // array to store sequence

    // initial values
    fib[0] = 0;
    fib[1] = 1;

    // generate sequence
    for (i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // print sequence
     printf("Fibonacci Sequence:\n");
    for (j = 0; j < n; j++) {
        printf("%lld ", fib[j]);
    }
    printf("\n\n");

    // visualize sequence as bar graph
    printf("Fibonacci Sequence Visualizer:\n");
    for (k = 0; k < n; k++) {
        printf("[%lld]\t", fib[k]);

        // print asterisks to represent value
        int m;
        for (m = 0; m < fib[k]; m++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;

    // prompt user to input number of terms
    printf("Enter number of terms in Fibonacci sequence (up to 50): ");
    scanf("%d", &n);

    // check for valid input
    if (n < 1 || n > 50) {
        printf("Invalid input. Number of terms must be between 1 and 50.\n");
        exit(1);
    }

    // generate sequence and visualize it
    generateFibonacciSequence(n);

    return 0;
}