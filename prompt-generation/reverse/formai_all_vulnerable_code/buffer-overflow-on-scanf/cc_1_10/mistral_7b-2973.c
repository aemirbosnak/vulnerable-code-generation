//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 10

void transpose(int matrix[][MAX_DIM], int row, int col) {
    int temp;

    for (int i = 0; i < row; ++i) {
        for (int j = i + 1; j < col; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix[MAX_DIM][MAX_DIM];
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_DIM || cols > MAX_DIM) {
        printf("Error: Matrix dimensions exceed maximum limit.\n");
        return 1;
    }

    printf("Enter elements of the matrix (%d x %d): \n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    transpose(matrix, rows, cols);

    printf("\nTranspose of the given matrix: \n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}