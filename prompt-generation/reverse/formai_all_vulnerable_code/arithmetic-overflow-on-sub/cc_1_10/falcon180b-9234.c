//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000

int main() {
    int n, i, j, count = 0;
    int fib_seq[MAX_TERMS];
    int start_time, end_time;
    double elapsed_time;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Get user input for number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Generate the Fibonacci sequence
    printf("Generating Fibonacci sequence...\n");
    fib_seq[0] = 0;
    fib_seq[1] = 1;
    for (i = 2; i < n; i++) {
        fib_seq[i] = rand() % 100;
    }

    // Print the sequence
    printf("Fibonacci sequence: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fib_seq[i]);
    }
    printf("\n");

    // Visualize the sequence using ASCII art
    printf("\nVisualizing the sequence...\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < fib_seq[i]; j++) {
            printf("#");
        }
        printf("\n");
    }

    // Measure execution time
    start_time = clock();
    for (i = 0; i < n; i++) {
        count += fib_seq[i];
    }
    end_time = clock();
    elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Print execution time
    printf("\nExecution time: %.2f seconds\n", elapsed_time);

    return 0;
}