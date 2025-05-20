//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, k, l, m, n, sum;
    int matrix1[100][100], matrix2[100][100], result[100][100];
    float avg;
    struct timespec start_time, end_time;
    double elapsed_time;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Multiplying matrices...\n");
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum = 0;
            for (k = 0; k < cols; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (double) (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) * 1e-9;
    avg = elapsed_time / (double) CLOCKS_PER_SEC;
    printf("Multiplication completed in %.2f seconds.\n", avg);

    printf("Result matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}