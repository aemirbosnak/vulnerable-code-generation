//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 100

int main() {
    int num_terms, i, term1, term2, next_term;
    int *fibonacci = NULL;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &num_terms);

    if (num_terms <= 0) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    fibonacci = (int *)malloc(num_terms * sizeof(int));
    if (fibonacci == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    term1 = 0;
    term2 = 1;
    fibonacci[0] = term1;
    fibonacci[1] = term2;

    for (i = 2; i < num_terms; i++) {
        next_term = term1 + term2;
        fibonacci[i] = next_term;
        term1 = term2;
        term2 = next_term;
    }

    printf("Generating %d Fibonacci terms...\n", num_terms);
    fflush(stdout);

    start_time = time(NULL);
    for (i = 0; i < num_terms; i++) {
        printf("%d ", fibonacci[i]);
        if (i % 10 == 9) {
            printf("\n");
        }
    }
    printf("\n");

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Elapsed time: %.6f seconds\n", elapsed_time);

    free(fibonacci);
    return 0;
}