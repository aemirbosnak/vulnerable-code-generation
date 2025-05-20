//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int size, i, j, k;
    int **matrix1, **matrix2, **result;
    double start, end;

    printf("Enter the size of the matrices: ");
    scanf("%d", &size);

    matrix1 = (int **)malloc(size * sizeof(int *));
    matrix2 = (int **)malloc(size * sizeof(int *));
    result = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        matrix1[i] = (int *)malloc(size * sizeof(int));
        matrix2[i] = (int *)malloc(size * sizeof(int));
        result[i] = (int *)malloc(size * sizeof(int));
    }

    srand(time(NULL));
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    start = clock();
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    end = clock();

    printf("Matrix 1:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix 2:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("Result:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("Time taken: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (i = 0; i < size; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}