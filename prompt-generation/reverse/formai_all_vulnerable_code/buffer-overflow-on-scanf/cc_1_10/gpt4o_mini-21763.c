//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n) {
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }

    long long *fibo = (long long *)malloc(n * sizeof(long long));
    if (fibo == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    fibo[0] = 0;
    if (n > 1) {
        fibo[1] = 1;
    }

    for (int i = 2; i < n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibo[i]);
    }
    printf("\n");

    int maxTerm = fibo[n - 1];
    int maxStars = 50; // Maximum length of visual representation

    printf("\nVisualization of the Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        int numStars = (fibo[i] * maxStars) / maxTerm; // Scale to maxStars
        printf("%lld: ", fibo[i]);
        for (int j = 0; j < numStars; j++) {
            printf("*");
        }
        printf("\n");
    }

    free(fibo); // Free allocated memory
}

int main() {
    int n;

    printf("Enter the number of Fibonacci terms to generate: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    printFibonacci(n);
    return 0;
}