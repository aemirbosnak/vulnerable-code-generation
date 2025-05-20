//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TERMS 1000
#define MAX_DIGITS 1000

int main() {
    int num_terms;
    int i;
    int *fib_seq;
    int fib_index;
    int term_count;
    char input[MAX_DIGITS];
    double start_time, end_time, elapsed_time;

    // Get number of terms from user
    printf("Enter the number of terms to generate: ");
    scanf("%d", &num_terms);

    // Validate input
    if (num_terms <= 0) {
        printf("Invalid input.\n");
        exit(1);
    }

    // Allocate memory for Fibonacci sequence
    fib_seq = (int *)malloc(num_terms * sizeof(int));
    if (fib_seq == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Generate Fibonacci sequence
    fib_index = 0;
    fib_seq[0] = 0;
    fib_seq[1] = 1;
    for (i = 2; i < num_terms; i++) {
        fib_seq[i] = fib_seq[i-1] + fib_seq[i-2];
        if (fib_seq[i] < 0) {
            printf("Fibonacci sequence exceeds maximum value.\n");
            exit(1);
        }
        fib_index++;
    }

    // Display Fibonacci sequence
    printf("Fibonacci sequence:\n");
    for (i = 0; i < num_terms; i++) {
        printf("%d ", fib_seq[i]);
    }
    printf("\n");

    // Get number of terms to visualize
    printf("Enter the number of terms to visualize: ");
    scanf("%d", &term_count);

    // Validate input
    if (term_count < 1 || term_count > num_terms) {
        printf("Invalid input.\n");
        exit(1);
    }

    // Visualize Fibonacci sequence
    printf("Visualizing Fibonacci sequence...\n");
    start_time = clock();
    for (i = 0; i < term_count; i++) {
        printf("%d ", fib_seq[i]);
    }
    end_time = clock();
    elapsed_time = ((double)end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nElapsed time: %lf seconds\n", elapsed_time);

    // Free memory
    free(fib_seq);

    return 0;
}