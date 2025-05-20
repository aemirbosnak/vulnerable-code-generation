//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TERMS 1000

int main() {
    int n, i, j, terms = 0;
    double fibonacci[MAX_TERMS];
    time_t start_time, end_time;

    // Prompt user for number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Initialize Fibonacci sequence
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // Calculate remaining terms
    for (i = 2; i < n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        terms++;
    }

    // Print Fibonacci sequence
    printf("\nFibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");

    // Visualize Fibonacci sequence
    printf("\nVisualizing Fibonacci sequence...\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < fibonacci[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Measure execution time
    time(&start_time);
    for (i = 0; i < n; i++) {
        fibonacci[i] = pow(2, fibonacci[i]);
    }
    time(&end_time);
    printf("\nExecution time: %.2f seconds\n", difftime(end_time, start_time));

    return 0;
}