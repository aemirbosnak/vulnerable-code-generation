//FormAI DATASET v1.0 Category: Matrix operations ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int rows, columns, i, j;
    printf("Enter the number of rows in your matrix:\n");
    scanf("%d",&rows);
    printf("Enter the number of columns in your matrix:\n");
    scanf("%d",&columns);

    //create the matrix
    int** matrix = (int**) malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++){
        matrix[i] = (int*) malloc(columns * sizeof(int));
    }

    //populate the matrix
    printf("Enter the elements of your matrix:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    //print the matrix
    printf("Your matrix is:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    //transpose the matrix
    printf("The transpose of your matrix is:\n");
    int** transposeMatrix = (int**) malloc(columns * sizeof(int*));
    for(i = 0; i < columns; i++){
        transposeMatrix[i] = (int*) malloc(rows * sizeof(int));
    }

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            transposeMatrix[j][i] = matrix[i][j];
        }
    }

    //print the transpose matrix
    for(i = 0; i < columns; i++) {
        for(j = 0; j < rows; j++) {
            printf("%d\t", transposeMatrix[i][j]);
        }
        printf("\n");
    }

    //multiply the matrix with a scalar value
    int scalar;
    printf("Enter the scalar value to multiply with your matrix:\n");
    scanf("%d", &scalar);

    int** scalarMatrix = (int**) malloc(rows * sizeof(int*));
    for(i = 0; i < rows; i++){
        scalarMatrix[i] = (int*) malloc(columns * sizeof(int));
    }

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            scalarMatrix[i][j] = matrix[i][j] * scalar;
        }
    }

    //print the scalar matrix
    printf("The scalar multiplication of your matrix is:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < columns; j++) {
            printf("%d\t", scalarMatrix[i][j]);
        }
        printf("\n");
    }

    //free memory
    for(i = 0; i < rows; i++){
        free(matrix[i]);
        free(transposeMatrix[i]);
        free(scalarMatrix[i]);
    }
    free(matrix);
    free(transposeMatrix);
    free(scalarMatrix);

    return 0;
}