//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int rows, cols;
    float* matrix;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    matrix = (float*)malloc(rows * cols * sizeof(float));

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%f", &matrix[i * cols + j]);
        }
    }

    // Example matrix operations
    printf("Original matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i * cols + j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    float* transposed = (float*)malloc(cols * rows * sizeof(float));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j * rows + i] = matrix[i * cols + j];
        }
    }

    printf("Transposed matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%f ", transposed[i * rows + j]);
        }
        printf("\n");
    }

    // Multiply the transposed matrix with the original matrix
    float* result = (float*)malloc(rows * rows * sizeof(float));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                result[i * rows + j] += matrix[i * cols + k] * transposed[k * rows + j];
            }
        }
    }

    printf("Result of multiplication:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%f ", result[i * rows + j]);
        }
        printf("\n");
    }

    // Free allocated memory
    free(matrix);
    free(transposed);
    free(result);

    return 0;
}