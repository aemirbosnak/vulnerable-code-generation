//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int **a = NULL;
    int **b = NULL;
    int **c = NULL;
    int i, j, k;

    a = (int**)malloc(5 * sizeof(int*));
    for (i = 0; i < 5; i++) {
        a[i] = (int*)malloc(5 * sizeof(int));
    }

    b = (int**)malloc(5 * sizeof(int*));
    for (i = 0; i < 5; i++) {
        b[i] = (int*)malloc(5 * sizeof(int));
    }

    c = (int**)malloc(5 * sizeof(int*));
    for (i = 0; i < 5; i++) {
        c[i] = (int*)malloc(5 * sizeof(int));
    }

    // Matrix Operations
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                c[i][j] = a[i][k] + b[k][j];
            }
        }
    }

    // Print the Result
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free Memory
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            free(a[i][j]);
        }
        free(a[i]);
    }

    free(a);

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            free(b[i][j]);
        }
        free(b[i]);
    }

    free(b);

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            free(c[i][j]);
        }
        free(c[i]);
    }

    free(c);

    return 0;
}