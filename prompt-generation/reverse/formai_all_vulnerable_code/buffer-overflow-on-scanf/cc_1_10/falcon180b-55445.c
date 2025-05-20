//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_TERMS 100000

int main(void) {
    int num_terms = 0;
    int curr_term = 0;
    int prev_term = 0;
    int next_term = 1;
    bool done = false;
    srand(time(NULL));

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many terms would you like to generate? (Max: %d)\n", MAX_TERMS);
    scanf("%d", &num_terms);

    printf("Generating %d Fibonacci numbers...\n", num_terms);

    for (int i = 0; i < num_terms; i++) {
        if (i == 0) {
            curr_term = 0;
        } else if (i == 1) {
            curr_term = 1;
        } else {
            curr_term = prev_term + next_term;
            prev_term = next_term;
            next_term = curr_term;
        }

        if (curr_term % 2 == 0) {
            printf("%d ", curr_term);
        } else {
            printf("%d ", curr_term);
            printf("*\n");
        }

        if (curr_term > MAX_TERMS) {
            done = true;
            break;
        }
    }

    if (!done) {
        printf("All %d terms generated successfully.\n", num_terms);
    }

    return 0;
}