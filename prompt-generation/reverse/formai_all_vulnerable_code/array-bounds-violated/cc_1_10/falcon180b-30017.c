//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TERMS 1000

int main() {
    int num_terms;
    int terms[MAX_TERMS];
    int i;

    srand(time(NULL));

    // get number of terms from user
    printf("Enter the number of terms to generate: ");
    scanf("%d", &num_terms);

    // generate random Fibonacci sequence
    for (i = 0; i < num_terms; i++) {
        int a, b;
        do {
            a = rand() % 1000;
            b = rand() % 1000;
        } while (a == b);
        terms[i] = a;
        terms[num_terms - i - 1] = b;
    }

    // print sequence
    printf("Fibonacci sequence:\n");
    for (i = 0; i < num_terms; i++) {
        printf("%d ", terms[i]);
    }
    printf("\n");

    // visualize sequence
    printf("Visualizing sequence...\n");
    for (i = 0; i < num_terms; i++) {
        int a = terms[i];
        int b = terms[num_terms - i - 1];
        int c = a + b;
        printf("  %d  ", a);
        int j;
        for (j = 1; j < i; j++) {
            printf("   ");
        }
        printf(" %d\n", c);
    }

    return 0;
}