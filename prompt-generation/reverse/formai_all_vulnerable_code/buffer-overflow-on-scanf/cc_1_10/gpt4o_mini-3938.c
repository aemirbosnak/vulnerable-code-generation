//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void generateFibonacci(int terms, long long *fibArray) {
    if (terms >= 1) {
        fibArray[0] = 0; // First term
    }
    if (terms >= 2) {
        fibArray[1] = 1; // Second term
    }
    for (int i = 2; i < terms; i++) {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }
}

void printFibonacciValues(int terms, long long *fibArray) {
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < terms; i++) {
        printf("%lld ", fibArray[i]);
    }
    printf("\n");
}

void visualizeFibonacci(int terms, long long *fibArray) {
    printf("\nFibonacci Visualization:\n");
    for (int i = 0; i < terms; i++) {
        printf("F(%d): ", i);
        for (long long j = 0; j < fibArray[i]; j++) {
            printf("*");
            if ((j + 1) % 50 == 0) { // Limit stars printed per line to 50
                printf("\n       ");
            }
        }
        printf(" (%lld)\n", fibArray[i]);
    }
}

int main() {
    int terms;
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("The number of terms must be a positive integer.\n");
        return 1;
    }

    long long *fibArray = (long long *)malloc(terms * sizeof(long long));
    if (fibArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    generateFibonacci(terms, fibArray);
    printFibonacciValues(terms, fibArray);
    visualizeFibonacci(terms, fibArray);

    free(fibArray);
    return 0;
}