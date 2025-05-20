//FormAI DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main() {
    int m, n, i, j;

    printf("Enter number of rows in matrix: ");
    scanf("%d", &m);

    printf("Enter number of columns in matrix: ");
    scanf("%d", &n);

    int** matrix = (int**)malloc(m * sizeof(int*));  // Allocate memory for the matrix

    for(i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));

        for(j = 0; j < n; j++) {
            printf("Enter value for row %d, column %d: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix
    printf("\nEntered Matrix is: \n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate the transpose of the matrix
    int** transpose = (int**)malloc(n * sizeof(int*));  // Allocate memory for the transpose matrix
    for(i = 0; i < n; i++) {
        transpose[i] = (int*)malloc(m * sizeof(int));

        for(j = 0; j < m; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    // Display the transpose matrix
    printf("\nTranspose of the matrix is: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d  ", transpose[i][j]);
        }
        printf("\n");
    }

    // Calculate and display the product of the matrix and its transpose
    printf("\nProduct of the matrix and its transpose is: \n");
    int** product = (int**)malloc(m * sizeof(int*));  // Allocate memory for the product matrix
    int sum;

    for(i = 0; i < m; i++) {
        product[i] = (int*)malloc(m * sizeof(int));

        for(j = 0; j < m; j++) {
            sum = 0;

            for(int k = 0; k < n; k++) {
                sum += matrix[i][k] * transpose[k][j];
            }
            product[i][j] = sum;
            printf("%d  ", product[i][j]);
        }
        printf("\n");
    }

    // Free memory allocated to the matrices
    for(i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for(i = 0; i < n; i++) {
        free(transpose[i]);
    }
    free(transpose);

    for(i = 0; i < m; i++) {
        free(product[i]);
    }
    free(product);

    return 0;
}