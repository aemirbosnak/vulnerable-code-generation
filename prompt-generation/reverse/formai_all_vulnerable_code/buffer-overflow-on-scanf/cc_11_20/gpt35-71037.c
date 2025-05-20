//FormAI DATASET v1.0 Category: Matrix operations ; Style: content
#include <stdio.h>

int main() {
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int row1, col1, row2, col2, i, j, k;
    
    printf("Enter the rows and columns of matrix 1: ");
    scanf("%d %d", &row1, &col1);
    
    printf("\nEnter the elements of matrix 1:\n");
    for(i=0; i<row1; i++){
        for(j=0; j<col1; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("\nEnter the rows and columns of matrix 2: ");
    scanf("%d %d", &row2, &col2);
    
    if (col1 != row2){
        printf("Error: Matrix multiplication not possible.");
        return 0;
    }
    
    printf("\nEnter the elements of matrix 2:\n");
    for(i=0; i<row2; i++){
        for(j=0; j<col2; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Multiplying matrix 1 and matrix 2
    for(i=0; i<row1; i++){
        for(j=0; j<col2; j++){
            result[i][j] = 0;
            for(k=0; k<col1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    // Displaying the result of matrix multiplication
    printf("\nThe result of matrix multiplication of matrix 1 and matrix 2:\n");
    for(i=0; i<row1; i++){
        for(j=0; j<col2; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // Subtracting matrix 1 from matrix 2
    if (row1 == row2 && col1 == col2){
        printf("\nSubtracting matrix 1 from matrix 2:\n");
        for(i=0; i<row1; i++){
            for(j=0; j<col1; j++){
                result[i][j] = matrix2[i][j] - matrix1[i][j];
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
    
    // Transposing matrix 1
    printf("\nTransposing matrix 1:\n");
    for(i=0; i<col1; i++){
        for(j=0; j<row1; j++){
            printf("%d ", matrix1[j][i]);
        }
        printf("\n");
    }
    
    return 0;
}