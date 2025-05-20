//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 100000
#define MAX_VALUE 1000000

int main() {
    int n, i;
    int fibonacci[MAX_TERMS];
    int max_fibonacci = 0;
    int max_index = 0;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_TERMS) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    srand(time(NULL));

    // Generate random Fibonacci sequence
    for (i = 0; i < n; i++) {
        fibonacci[i] = rand() % MAX_VALUE;
        max_fibonacci = max_fibonacci > fibonacci[i]? max_fibonacci : fibonacci[i];
        max_index = max_index > i? max_index : i;
    }

    printf("\nFibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n\n");

    printf("The largest Fibonacci term is %d at index %d.\n", max_fibonacci, max_index);

    start_time = clock();
    for (i = 0; i < n; i++) {
        if (fibonacci[i] == max_fibonacci) {
            break;
        }
    }
    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("The largest Fibonacci term was found in %.6f seconds.\n", elapsed_time);

    return 0;
}