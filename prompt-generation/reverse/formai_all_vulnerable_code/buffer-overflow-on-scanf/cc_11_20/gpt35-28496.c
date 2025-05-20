//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i, j, k, sum;
    int **matrix1, **matrix2, **result;

    printf("Enter the size of square matrices: ");
    scanf("%d", &size);

    // dynamically allocate memory for matrix1
    matrix1 = (int **) malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        matrix1[i] = (int *) malloc(size * sizeof(int));
    }

    // dynamically allocate memory for matrix2
    matrix2 = (int **) malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        matrix2[i] = (int *) malloc(size * sizeof(int));
    }

    // dynamically allocate memory for result
    result = (int **) malloc(size * sizeof(int *));
    for (i = 0; i < size; i++) {
        result[i] = (int *) malloc(size * sizeof(int));
    }

    printf("\nEnter the values of matrix 1:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter the values of matrix 2:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // perform matrix multiplication
    for (i = 0; i < size; i++) { 
        for (j = 0; j < size; j++) {
            sum = 0;
            for (k = 0; k < size; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    printf("\nThe product of the matrices is:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // free dynamically allocated memory
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