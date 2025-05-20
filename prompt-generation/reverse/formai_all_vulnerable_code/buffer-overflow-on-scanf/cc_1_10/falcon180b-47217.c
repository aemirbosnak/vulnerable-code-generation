//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000

int main() {
    int num_terms;
    int *terms;
    int i, j;
    struct timespec start, end;

    printf("Enter the number of terms to generate: ");
    scanf("%d", &num_terms);

    terms = malloc(num_terms * sizeof(int));

    if (terms == NULL) {
        printf("Error: unable to allocate memory.\n");
        exit(1);
    }

    for (i = 0; i < num_terms; i++) {
        terms[i] = 0;
    }

    terms[0] = 1;
    terms[1] = 1;

    clock_gettime(CLOCK_REALTIME, &start);

    for (i = 2; i < num_terms; i++) {
        for (j = 0; j < i; j++) {
            terms[i] += terms[j];
        }
    }

    clock_gettime(CLOCK_REALTIME, &end);

    printf("Fibonacci sequence with %d terms:\n", num_terms);
    for (i = 0; i < num_terms; i++) {
        printf("%d ", terms[i]);
    }
    printf("\n");

    printf("Time taken: %lu.%09lu seconds.\n", end.tv_sec - start.tv_sec, end.tv_nsec - start.tv_nsec);

    free(terms);
    return 0;
}