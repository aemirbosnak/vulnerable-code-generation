//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

void generateFibonacci(int n, long long *fib) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void visualizeFibonacci(int n, long long *fib) {
    printf("\nFibonacci Sequence Visualization (First %d terms):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%-12lld: ", fib[i]);
        for (long long j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void readUserInput(int *n) {
    printf("Enter the number of terms in the Fibonacci sequence to visualize: ");
    while (1) {
        scanf("%d", n);
        if (*n > 0 && *n <= 93) { // Limiting to 93 to avoid overflow of long long
            break;
        } else {
            printf("Please enter a positive integer between 1 and 93: ");
        }
    }
}

int main() {
    int n;
    readUserInput(&n);

    long long *fibonacci = (long long *)malloc(n * sizeof(long long));
    if (fibonacci == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    generateFibonacci(n, fibonacci);
    visualizeFibonacci(n, fibonacci);

    free(fibonacci);
    return 0;
}