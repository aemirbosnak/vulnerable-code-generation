//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void generateFibonacci(int n, long long *fibArray) {
    fibArray[0] = 0;
    if (n > 1) {
        fibArray[1] = 1;
        for (int i = 2; i < n; i++) {
            fibArray[i] = fibArray[i-1] + fibArray[i-2];
        }
    }
}

void printFibonacci(long long *fibArray, int n) {
    printf("Fibonacci Sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld ", fibArray[i]);
    }
    printf("\n");
}

void visualizeFibonacci(long long *fibArray, int n) {
    printf("\nFibonacci Visualization (as bars):\n");
    for (int i = 0; i < n; i++) {
        printf("F(%d): ", i);
        int barLength = fibArray[i] < 50 ? fibArray[i] : 50; // limit max bar length
        for (int j = 0; j < barLength; j++) {
            printf("#");
        }
        printf(" (%lld)\n", fibArray[i]);
    }
}

int main() {
    int n;
    
    printf("Enter the number of Fibonacci terms you want to visualize: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    long long *fibArray = (long long *)malloc(n * sizeof(long long));
    if (fibArray == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    generateFibonacci(n, fibArray);
    printFibonacci(fibArray, n);
    visualizeFibonacci(fibArray, n);

    free(fibArray);
    return 0;
}