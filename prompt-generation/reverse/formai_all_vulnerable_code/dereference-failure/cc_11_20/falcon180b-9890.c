//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int size;
    int **matrix1, **matrix2, **result;
    int i, j, k;
    int choice;
    int sum = 0;
    int count = 0;
    int start_time, end_time;
    double cpu_time_used;

    printf("Enter the size of the matrices (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    matrix1 = (int **)malloc(size * sizeof(int *));
    matrix2 = (int **)malloc(size * sizeof(int *));
    result = (int **)malloc(size * sizeof(int *));

    for (i = 0; i < size; i++) {
        matrix1[i] = (int *)malloc(size * sizeof(int));
        matrix2[i] = (int *)malloc(size * sizeof(int));
        result[i] = (int *)malloc(size * sizeof(int));
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    start_time = clock();

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (matrix1[i][j] > matrix2[i][j]) {
                result[i][j] = matrix1[i][j];
            } else {
                result[i][j] = matrix2[i][j];
            }
        }
    }

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Result:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("CPU time used: %lf seconds\n", cpu_time_used);

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