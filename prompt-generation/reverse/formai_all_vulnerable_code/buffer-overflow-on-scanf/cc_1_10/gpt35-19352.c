//FormAI DATASET v1.0 Category: Matrix operations ; Style: surrealist
/* Welcome to the Surreal Matrix Operations Program! */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printMatrix(int *matrix, int numRows, int numCols) {
    printf("\n");
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols; j++) {
            printf("%d ", *(matrix + i*numCols + j));
        }
        printf("\n");
    }
}

void fillMatrix(int *matrix, int numRows, int numCols) {
    srand(time(NULL));
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols; j++) {
            *(matrix + i*numCols + j) = rand()%101; //fill matrix with random numbers between 0 and 100
        }
    }
}

void addMatrix(int *matrix1, int *matrix2, int *resultMatrix, int numRows, int numCols) {
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols; j++) {
            *(resultMatrix + i*numCols + j) = *(matrix1 + i*numCols + j) + *(matrix2 + i*numCols + j); //add corresponding elements of matrix1 and matrix2 and put result in resultMatrix
        }
    }
    printf("\n\nThe matrices have been added. Here is the result:\n");
    printMatrix(resultMatrix, numRows, numCols);
}

void multiplyMatrix(int *matrix1, int *matrix2, int *resultMatrix, int numRows1, int numCols1, int numRows2, int numCols2) {
    int newNumRows = numRows1; //newNumRows of resultMatrix is the same as numRows of matrix1
    int newNumCols = numCols2; //newNumCols of resultMatrix is the same as numCols of matrix2
    for(int i=0; i<newNumRows; i++) {
        for(int j=0; j<newNumCols; j++) {
            *(resultMatrix + i*newNumCols + j) = 0; //initialize to 0
            for(int k=0; k<numCols1; k++) {
                *(resultMatrix + i*newNumCols + j) += *(matrix1 + i*numCols1 + k) * *(matrix2 + k*numCols2 + j); //multiply corresponding elements of a row in matrix1 with a column in matrix2, sum them up, and put result in corresponding element in resultMatrix
            }
        }
    }
    printf("\n\nThe matrices have been multiplied. Here is the result:\n");
    printMatrix(resultMatrix, newNumRows, newNumCols);
}

int main() {
    printf("Welcome to the Surreal Matrix Operations Program!\n\n");
    int numRows1, numCols1, numRows2, numCols2;
    printf("Enter the number of rows in the first matrix: ");
    scanf("%d", &numRows1);
    printf("Enter the number of columns in the first matrix: ");
    scanf("%d", &numCols1);
    printf("Enter the number of rows in the second matrix: ");
    scanf("%d", &numRows2);
    printf("Enter the number of columns in the second matrix: ");
    scanf("%d", &numCols2);
    if(numCols1 != numRows2) {
        printf("\nSorry, matrix multiplication cannot be performed as the number of columns in the first matrix is not equal to the number of rows in the second matrix. Please try again with appropriate dimensions.\n");
        return -1;
    }
    int *matrix1 = (int*)malloc(numRows1*numCols1*sizeof(int)); //dynamically allocate memory for matrix1
    int *matrix2 = (int*)malloc(numRows2*numCols2*sizeof(int)); //dynamically allocate memory for matrix2
    int *resultMatrix = (int*)malloc(numRows1*numCols2*sizeof(int)); //dynamically allocate memory for resultMatrix
    printf("\nMatrix 1:\n");
    fillMatrix(matrix1, numRows1, numCols1);
    printMatrix(matrix1, numRows1, numCols1);
    printf("\nMatrix 2:\n");
    fillMatrix(matrix2, numRows2, numCols2);
    printMatrix(matrix2, numRows2, numCols2);
    addMatrix(matrix1, matrix2, resultMatrix, numRows1, numCols1);
    multiplyMatrix(matrix1, matrix2, resultMatrix, numRows1, numCols1, numRows2, numCols2);
    free(matrix1); //free memory allocated for matrix1
    free(matrix2); //free memory allocated for matrix2
    free(resultMatrix); //free memory allocated for resultMatrix
    return 0;
}