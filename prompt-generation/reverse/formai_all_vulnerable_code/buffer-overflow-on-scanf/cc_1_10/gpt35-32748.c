//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include<stdio.h>
#include<stdlib.h>

void printMatrix(int **matrix, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int **createMatrix(int row, int col){
    int **matrix = (int **) malloc(row * sizeof(int *));
    for(int i=0; i<row; i++){
        matrix[i] = (int *) malloc(col * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int row){
    for(int i=0; i<row; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int main(){
    int row1, col1, row2, col2;

    printf("Enter rows and columns for the 1st matrix: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter rows and columns for the 2nd matrix: ");
    scanf("%d %d", &row2, &col2);

    if(col1 != row2){
        printf("Error: Column of first matrix not equal to row of second");
        return 0;
    }

    int **matrix1 = createMatrix(row1, col1);
    int **matrix2 = createMatrix(row2, col2);
    int **resultMatrix = createMatrix(row1, col2);

    printf("Enter values for the 1st matrix:\n");
    for(int i=0; i<row1; i++){
        for(int j=0; j<col1; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter values for the 2nd matrix:\n");
    for(int i=0; i<row2; i++){
        for(int j=0; j<col2; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    // multiplication operation
    for(int i=0; i<row1; i++){
        for(int j=0; j<col2; j++){
            resultMatrix[i][j] = 0;
            for(int k=0; k<row2; k++){
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("The first matrix is:\n");
    printMatrix(matrix1, row1, col1);

    printf("The second matrix is:\n");
    printMatrix(matrix2, row2, col2);

    printf("The result of matrix multiplication is:\n");
    printMatrix(resultMatrix, row1, col2);

    freeMatrix(matrix1, row1);
    freeMatrix(matrix2, row2);
    freeMatrix(resultMatrix, row1);

    return 0;
}