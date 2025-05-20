//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    clock_t start, end;

    // Get user input
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Initialize matrix
    int **matrix = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *) malloc(n * sizeof(int));
    }

    // Fill matrix with random values
    srand(time(0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Print matrix
    printf("\nMatrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Start timer
    start = clock();

    // Calculate sum of matrix
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }

    // Stop timer
    end = clock();

    // Print sum and execution time
    printf("\nSum of matrix: %d\n", sum);
    printf("Execution time: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}