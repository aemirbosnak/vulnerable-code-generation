//FormAI DATASET v1.0 Category: Matrix operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, i, j;
    int **matrix, **transposed_matrix, **multiplied_matrix;
    
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d", &m, &n);
    
    // Allocate memory for the original matrix
    matrix = (int **) malloc(m * sizeof(int *));
    for(i = 0; i < m; i++) {
        matrix[i] = (int *) malloc(n * sizeof(int));
    }
    
    // Populate the matrix with user input
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Allocate memory for the transposed matrix
    transposed_matrix = (int **) malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) {
        transposed_matrix[i] = (int *) malloc(m * sizeof(int));
    }
    
    // Transpose the original matrix
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            transposed_matrix[j][i] = matrix[i][j];
        }
    }
    
    // Print the transposed matrix
    printf("\nTransposed Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", transposed_matrix[i][j]);
        }
        printf("\n");
    }
    
    // Allocate memory for the multiplied matrix
    multiplied_matrix = (int **) malloc(m * sizeof(int *));
    for(i = 0; i < m; i++) {
        multiplied_matrix[i] = (int *) malloc(m * sizeof(int));
    }
    
    // Multiply the original matrix with its transpose
    for(i = 0; i < m; i++) {
        for(j = 0; j < m; j++) {
            multiplied_matrix[i][j] = 0;
            for(int k = 0; k < n; k++) {
                multiplied_matrix[i][j] += matrix[i][k] * transposed_matrix[k][j];
            }
        }
    }
    
    // Print the multiplied matrix
    printf("\nMultiplied Matrix:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", multiplied_matrix[i][j]);
        }
        printf("\n");
    }
    
    // Deallocate memory for all matrices
    for(i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    for(i = 0; i < n; i++) {
        free(transposed_matrix[i]);
    }
    free(transposed_matrix);
    
    for(i = 0; i < m; i++) {
        free(multiplied_matrix[i]);
    }
    free(multiplied_matrix);
    
    return 0;
}