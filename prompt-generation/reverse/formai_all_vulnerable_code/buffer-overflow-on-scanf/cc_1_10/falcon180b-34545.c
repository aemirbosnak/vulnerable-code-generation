//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000
#define TERM_WIDTH 10

int main() {
    int num_terms = 0;
    int terms[MAX_TERMS];
    int i, j, n;
    int width = TERM_WIDTH;
    int max_width = 0;
    char fmt[50];

    // Get user input for number of terms
    printf("Enter the number of terms to generate (1-%d): ", MAX_TERMS);
    scanf("%d", &num_terms);

    // Generate Fibonacci sequence
    terms[0] = 0;
    terms[1] = 1;
    for (i = 2; i < num_terms; i++) {
        terms[i] = terms[i-1] + terms[i-2];
    }

    // Calculate maximum width of terms
    for (i = 0; i < num_terms; i++) {
        n = (int)log10(terms[i]) + 1;
        if (n > max_width) {
            max_width = n;
        }
    }

    // Print header
    printf("\nFibonacci Sequence:\n");
    printf("%s", " ");
    for (i = 0; i < max_width; i++) {
        printf("-");
    }
    printf("\n");

    // Print sequence
    for (i = 0; i < num_terms; i++) {
        n = (int)log10(terms[i]) + 1;
        sprintf(fmt, "%%%dd", width);
        printf(fmt, terms[i]);
        printf(" ");
        for (j = 0; j < max_width - n; j++) {
            printf(" ");
        }
    }

    // Print footer
    printf("\n");
    for (i = 0; i < max_width; i++) {
        printf("-");
    }
    printf("\n");

    return 0;
}