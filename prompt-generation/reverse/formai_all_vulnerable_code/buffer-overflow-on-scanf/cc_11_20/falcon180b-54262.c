//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define SIZE 100

int main() {
    int **matrix;
    int i, j, n;
    double sum;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    matrix = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; ++i) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the matrix elements:\n");
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The original matrix is:\n");
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            sum = 0;
            for(int k = 0; k < n; ++k) {
                sum += matrix[i][k] * matrix[k][j];
            }
            matrix[i][j] = (int)sum;
        }
    }

    printf("The product matrix is:\n");
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}