//FormAI DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

// function to randomly populate matrix
void populateMatrix(int **mat, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            mat[i][j] = rand() % 10;
        }
    }
}

// function to print the matrix
void printMatrix(int **mat, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
void addMatrix(int **mat1, int **mat2, int **result, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// function to multiply two matrices
void multiplyMatrix(int **mat1, int **mat2, int **result, int row1, int col1, int col2){
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col2; j++){
            result[i][j] = 0;
            for(int k = 0; k < col1; k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main(){
    int row1, col1, row2, col2;

    // take input for dimensions of matrix 1
    printf("Enter number of rows and columns for Matrix 1: ");
    scanf("%d %d", &row1, &col1);

    // allocate memory for matrix 1
    int **mat1 = (int**)malloc(row1 * sizeof(int*));
    for(int i = 0; i < row1; i++){
        mat1[i] = (int*)malloc(col1 * sizeof(int));
    }

    // populate matrix 1
    populateMatrix(mat1, row1, col1);

    // print matrix 1
    printf("Matrix 1:\n");
    printMatrix(mat1, row1, col1);

    // take input for dimensions of matrix 2
    printf("\nEnter number of rows and columns for Matrix 2: ");
    scanf("%d %d", &row2, &col2);

    // allocate memory for matrix 2
    int **mat2 = (int**)malloc(row2 * sizeof(int*));
    for(int i = 0; i < row2; i++){
        mat2[i] = (int*)malloc(col2 * sizeof(int));
    }

    // populate matrix 2
    populateMatrix(mat2, row2, col2);

    // print matrix 2
    printf("Matrix 2:\n");
    printMatrix(mat2, row2, col2);

    // add matrices
    if(row1 == row2 && col1 == col2){
        int **sum = (int**)malloc(row1 * sizeof(int*));
        for(int i = 0; i < row1; i++){
            sum[i] = (int*)malloc(col1 * sizeof(int));
        }

        addMatrix(mat1, mat2, sum, row1, col1);

        // print sum
        printf("\nSum of matrix 1 and matrix 2:\n");
        printMatrix(sum, row1, col1);

        // free sum matrix memory
        for(int i = 0; i < row1; i++){
            free(sum[i]);
        }
        free(sum);
    }
    else{
        printf("\nMatrices cannot be added because dimensions do not match.\n");
    }

    // multiply matrices
    if(col1 == row2){
        int **result = (int**)malloc(row1 * sizeof(int*));
        for(int i = 0; i < row1; i++){
            result[i] = (int*)malloc(col2 * sizeof(int));
        }

        multiplyMatrix(mat1, mat2, result, row1, col1, col2);

        // print product
        printf("\nProduct of matrix 1 and matrix 2:\n");
        printMatrix(result, row1, col2);

        // free result matrix memory
        for(int i = 0; i < row1; i++){
            free(result[i]);
        }
        free(result);
    }
    else{
        printf("\nMatrices cannot be multiplied because dimensions do not match.\n");
    }

    // free matrix 1 memory
    for(int i = 0; i < row1; i++){
        free(mat1[i]);
    }
    free(mat1);

    // free matrix 2 memory
    for(int i = 0; i < row2; i++){
        free(mat2[i]);
    }
    free(mat2);

    return 0;
}