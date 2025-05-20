//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col, i, j;
    
    // input matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    
    // create matrix dynamically
    int** matrix = (int**)malloc(row * sizeof(int*));
    for(i = 0; i < row; i++)
        matrix[i] = (int*)malloc(col * sizeof(int));
        
    // input matrix values
    printf("\nEnter matrix elements:\n");
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
            scanf("%d", &matrix[i][j]);
    
    // print the original matrix
    printf("\nOriginal Matrix:\n");
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // calculate matrix transpose
    int** transpose = (int**)malloc(col * sizeof(int*));
    for(i = 0; i < col; i++)
        transpose[i] = (int*)malloc(row * sizeof(int));
        
    for(i = 0; i < col; i++)
        for(j = 0; j < row; j++)
            transpose[i][j] = matrix[j][i];
            
    // print the transpose matrix
    printf("\nTranspose Matrix:\n");
    for(i = 0; i < col; i++) {
        for(j = 0; j < row; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    
    // calculate matrix determinant
    if(row == col) {
        int det = determinant(matrix, row);
        printf("\nDeterminant of the matrix = %d\n", det);
    }
    else {
        printf("\nCannot calculate determinant of a non-square matrix.\n");
    }
    
    // free matrix and transpose memory
    for(i = 0; i < row; i++)
        free(matrix[i]);
    free(matrix);
    
    for(i = 0; i < col; i++)
        free(transpose[i]);
    free(transpose);
    
    return 0;
}

int determinant(int **mat, int n) { 
    int det = 0, sign = 1, i, j;
    if(n == 1) {
        return mat[0][0];
    }
    int** subMat = (int**)malloc((n-1) * sizeof(int*));
    for(i = 0; i < n-1; i++)
        subMat[i] = (int*)malloc((n-1) * sizeof(int));
    for(int p = 0; p < n; p++) {
        int h = 0, k = 0;
        for(i = 1; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(j == p) {
                    continue;
                }
                subMat[h][k] = mat[i][j];
                k++;
                if(k == n-1) {
                    h++;
                    k = 0;
                }
            }
        }
        det = det + (sign * mat[0][p] * determinant(subMat, n-1));
        sign = -sign;
    }
    for(i = 0; i < n-1; i++)
        free(subMat[i]);
    free(subMat);
    return det;
}