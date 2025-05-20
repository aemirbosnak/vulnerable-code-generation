//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 100
#define MAX_DIGITS 1000

int main() {
    int n, i, j, k;
    int fib[MAX_TERMS];
    char str[MAX_DIGITS];
    time_t start_time, end_time;
    double elapsed_time;

    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    printf("Generating Fibonacci sequence...\n");
    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("\nFibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        sprintf(str, "%d", fib[i]);
        printf("%s ", str);
    }

    printf("\n");

    start_time = clock();

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            k = fib[i] + fib[j];
            if (k > n) {
                break;
            }
            if (k == fib[n-1]) {
                printf("%d + %d = %d\n", fib[i], fib[j], fib[n-1]);
            }
        }
    }

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTotal time taken: %.2f seconds\n", elapsed_time);

    return 0;
}