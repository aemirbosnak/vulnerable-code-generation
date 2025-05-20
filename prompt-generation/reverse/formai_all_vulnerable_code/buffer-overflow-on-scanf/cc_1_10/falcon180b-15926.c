//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, l;
    int **matrix;
    int *seq;
    int n, m;

    // Get sequence length from user
    printf("Enter sequence length: ");
    scanf("%d", &n);

    // Generate random sequence
    seq = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        seq[i] = rand() % 4;
    }

    // Print initial sequence
    printf("Initial sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");

    // Get number of mutations from user
    printf("Enter number of mutations: ");
    scanf("%d", &m);

    // Generate mutation matrix
    matrix = (int **)malloc(4 * sizeof(int *));
    for (i = 0; i < 4; i++) {
        matrix[i] = (int *)malloc(4 * sizeof(int));
        for (j = 0; j < 4; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Apply mutations
    for (i = 0; i < m; i++) {
        k = rand() % n;
        l = rand() % 4;
        seq[k] = (seq[k] + l) % 4;
    }

    // Print final sequence
    printf("Final sequence:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");

    // Free memory
    free(seq);
    for (i = 0; i < 4; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}