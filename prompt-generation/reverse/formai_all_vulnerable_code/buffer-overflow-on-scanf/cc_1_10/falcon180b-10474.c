//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TERMS 100
#define MAX_DIGITS 1000

int main() {
    int num_terms = 0;
    int num_digits = 0;
    int i, j;
    long long int fib[MAX_TERMS];

    // Prompt user for number of terms
    printf("Enter the number of terms to generate: ");
    scanf("%d", &num_terms);

    // Prompt user for number of digits
    printf("Enter the number of digits to display: ");
    scanf("%d", &num_digits);

    // Initialize the first two terms of the Fibonacci sequence
    fib[0] = 0;
    fib[1] = 1;

    // Calculate the remaining terms of the sequence
    for (i = 2; i < num_terms; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Print the sequence
    printf("Fibonacci sequence:\n");
    for (i = 0; i < num_terms; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");

    // Print the sequence in a visual format
    printf("Visual representation of the Fibonacci sequence:\n");
    for (i = 0; i < num_terms; i++) {
        printf("|");
        for (j = 0; j < fib[i]; j++) {
            printf("#");
        }
        printf("|\n");
    }

    return 0;
}