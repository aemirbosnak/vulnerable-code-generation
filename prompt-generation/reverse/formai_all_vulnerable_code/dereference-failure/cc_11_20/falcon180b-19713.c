//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

int main() {
    int i, j;
    int **matrix;
    int *sum_matrix;
    double avg;
    double min, max;
    double sum = 0;
    srand(time(NULL));
    matrix = (int **)malloc(SIZE * sizeof(int *));
    for (i = 0; i < SIZE; i++) {
        matrix[i] = (int *)malloc(SIZE * sizeof(int));
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 100;
            sum += matrix[i][j];
        }
    }
    printf("Matrix:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    sum_matrix = (int *)malloc(SIZE * sizeof(int));
    for (i = 0; i < SIZE; i++) {
        sum_matrix[i] = rand() % 100;
        sum += sum_matrix[i];
    }
    printf("Sum of matrix:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", sum_matrix[i]);
    }
    printf("\n");
    avg = sum / (SIZE * SIZE);
    printf("Average of matrix: %.2lf\n", avg);
    min = matrix[0][0];
    max = matrix[0][0];
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    printf("Minimum of matrix: %d\n", min);
    printf("Maximum of matrix: %d\n", max);
    free(matrix);
    free(sum_matrix);
    return 0;
}