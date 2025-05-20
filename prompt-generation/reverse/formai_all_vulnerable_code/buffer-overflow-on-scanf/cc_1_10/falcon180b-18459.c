//Falcon-180B DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function to print a 2D array
void print2DArray(int **arr, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", (*(arr + i))[j]);
        }
        printf("\n");
    }
}

// Function to transpose a 2D array
void transposeMatrix(int **arr, int rows, int cols) {
    int i, j;
    int **transposedArr;
    transposedArr = (int **)malloc(cols * sizeof(int *));
    for (i = 0; i < cols; i++) {
        transposedArr[i] = (int *)malloc(rows * sizeof(int));
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            (*(transposedArr + j))[i] = (*(arr + i))[j];
        }
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            (*(arr + i))[j] = (*(transposedArr + j))[i];
        }
    }
    for (i = 0; i < cols; i++) {
        free(transposedArr[i]);
    }
    free(transposedArr);
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*(arr + i)) = (int *)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &(*(arr + i))[j]);
        }
    }

    printf("The original matrix:\n");
    print2DArray(arr, rows, cols);

    transposeMatrix(arr, rows, cols);

    printf("The transposed matrix:\n");
    print2DArray(arr, cols, rows);

    for (int i = 0; i < rows; i++) {
        free((*(arr + i)));
    }
    free(arr);

    return 0;
}