//FormAI DATASET v1.0 Category: Data mining ; Style: brave
#include<stdio.h>
#include<stdlib.h>

int main() {
    // Declare and Initialize variables
    int i, j, rows, cols;
    float **matrix, *mean, *variance;

    // Get number of rows and columns of a matrix
    printf("Enter the number of rows and columns of a matrix: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for matrix
    matrix = (float **) malloc(rows * sizeof(float *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (float *) malloc(cols * sizeof(float));
    }

    // Get input values for matrix
    printf("\nEnter the values for the matrix: \n");
    for (i = 0; i < rows; i++) {
        printf("\nEnter the values of row %d separated by spaces: ", i+1);
        for (j = 0; j < cols; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Compute the mean of each column
    mean = (float *) calloc(cols, sizeof(float));
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            mean[i] += matrix[j][i];
        }
        mean[i] /= rows;
    }

    // Compute the variance of each column
    variance = (float *) calloc(cols, sizeof(float));
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            variance[i] += (matrix[j][i] - mean[i]) * (matrix[j][i] - mean[i]);
        }
        variance[i] /= rows;
    }

    // Display the output
    printf("\nThe mean of each column is:\n");
    for (i = 0; i < cols; i++) {
        printf("%8.2f", mean[i]);
    }

    printf("\n\nThe variance of each column is:\n");
    for (i = 0; i < cols; i++) {
        printf("%8.2f", variance[i]);
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);
    free(mean);
    free(variance);
    
    return 0;
}