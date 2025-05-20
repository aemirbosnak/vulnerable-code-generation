//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000
#define MAX_WIDTH 80

int main(void) {
    int num_terms;
    int term_width;
    int i, j, k;
    int *fib_seq;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Enter the number of terms to generate: ");
    scanf("%d", &num_terms);

    if (num_terms < 1 || num_terms > MAX_TERMS) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    printf("Enter the width of each term: ");
    scanf("%d", &term_width);

    if (term_width < 1 || term_width > MAX_WIDTH) {
        printf("Invalid term width.\n");
        return 1;
    }

    fib_seq = malloc(num_terms * sizeof(int));
    if (fib_seq == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    start_time = time(NULL);

    for (i = 0; i < num_terms; i++) {
        fib_seq[i] = 0;
    }

    fib_seq[0] = 1;
    fib_seq[1] = 1;

    for (i = 2; i < num_terms; i++) {
        fib_seq[i] = fib_seq[i - 1] + fib_seq[i - 2];
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Fibonacci sequence of %d terms:\n", num_terms);

    for (i = 0; i < num_terms; i++) {
        for (j = 0; j < term_width; j++) {
            if (fib_seq[i] & (1 << j)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    free(fib_seq);

    printf("\nExecution time: %.6fs\n", elapsed_time);

    return 0;
}