//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int size, i, j, k;
    int **matrix1, **matrix2, **result;
    int choice;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the matrices (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    matrix1 = (int **)malloc(size * sizeof(int *));
    matrix2 = (int **)malloc(size * sizeof(int *));
    result = (int **)malloc(size * sizeof(int *));

    for (i = 0; i < size; i++) {
        matrix1[i] = (int *)malloc(size * sizeof(int));
        matrix2[i] = (int *)malloc(size * sizeof(int));
        result[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    start = clock();
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

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

    printf("CPU time used: %lf seconds\n", cpu_time_used);

    return 0;
}