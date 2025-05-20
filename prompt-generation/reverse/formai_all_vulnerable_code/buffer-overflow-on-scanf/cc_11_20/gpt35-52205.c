//FormAI DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include <stdio.h>

int main() {
    int matrix[10][10], transpose[10][10], sum[10][10], product[10][10];
    int rows, cols, i, j, k;
    
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);
    
    printf("Enter the elements of the matrix: \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("\nOriginal matrix: \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Transpose matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
    
    printf("\nTransposed matrix: \n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    // Sum of matrix elements
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum[i][j] = matrix[i][j] + transpose[i][j];
        }
    }
    
    printf("\nSum of matrix and transposed matrix: \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    
    // Matrix multiplication
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            product[i][j] = 0;
            for (k = 0; k < cols; k++) {
                product[i][j] += matrix[i][k] * transpose[k][j];
            }
        }
    }
    
    printf("\nMatrix multiplication: \n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}