//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_TERMS 100000

int main() {
    int num_terms = 0;
    int i, j, k;
    int terms[MAX_TERMS];
    int last_term = 0;
    int current_term = 0;
    int max_term = 0;
    int min_term = 0;
    int total_terms = 0;
    double start_time = 0.0;
    double end_time = 0.0;
    double elapsed_time = 0.0;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &num_terms);

    srand(time(NULL));

    for (i = 0; i < num_terms; i++) {
        terms[i] = rand() % 1000;
        total_terms += terms[i];
        if (i == 0) {
            last_term = terms[i];
        } else {
            current_term = terms[i];
            if (current_term > last_term) {
                if (current_term > max_term) {
                    max_term = current_term;
                }
            } else {
                if (current_term < min_term) {
                    min_term = current_term;
                }
            }
            last_term = current_term;
        }
    }

    printf("Generating %d random numbers between 0 and 999...\n", num_terms);

    start_time = clock();

    for (i = 0; i < num_terms; i++) {
        for (j = 0; j < terms[i]; j++) {
            printf("%d ", rand() % 1000);
        }
        printf("\n");
    }

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nExecution time: %.2f seconds\n", elapsed_time);

    return 0;
}