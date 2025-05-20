//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000
#define MAX_WIDTH 80

int main(void) {
    int n, i, j;
    long long int term1 = 0, term2 = 1, next_term;
    char **sequence;
    time_t start_time, end_time;

    printf("Enter the number of terms you want to visualize: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_TERMS) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    sequence = (char **)malloc(n * sizeof(char *));
    if (sequence == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        sequence[i] = (char *)malloc(MAX_WIDTH * sizeof(char));
        if (sequence[i] == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    printf("Generating Fibonacci sequence...\n");
    fflush(stdout);

    start_time = time(NULL);

    for (i = 0; i < n; i++) {
        term1 = term2;
        term2 = next_term;
        next_term = term1 + term2;

        sprintf(sequence[i], "%*llu", MAX_WIDTH - 2, term2);
    }

    end_time = time(NULL);

    printf("\nFibonacci sequence:\n");

    for (i = 0; i < n; i++) {
        printf("%s\n", sequence[i]);
    }

    printf("\nExecution time: %ld seconds\n", end_time - start_time);

    for (i = 0; i < n; i++) {
        free(sequence[i]);
    }

    free(sequence);

    return 0;
}