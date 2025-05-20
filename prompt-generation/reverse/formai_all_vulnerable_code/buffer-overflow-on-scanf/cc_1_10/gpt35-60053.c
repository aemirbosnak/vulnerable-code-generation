//FormAI DATASET v1.0 Category: Matrix operations ; Style: innovative
#include<stdio.h>

//function to print a matrix
void printMatrix(int matrix[10][10], int rows, int columns){
    printf("\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int rows1, columns1, rows2, columns2;
    int matrix1[10][10], matrix2[10][10], result[10][10];

    printf("Enter the number of rows of matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns of matrix 1: ");
    scanf("%d", &columns1);

    printf("\nEnter the elements of matrix 1: ");
    for(int i=0; i<rows1; i++){
        for(int j=0; j<columns1; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nThe first matrix is:\n");
    printMatrix(matrix1, rows1, columns1);

    printf("\nEnter the number of rows of matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns of matrix 2: ");
    scanf("%d", &columns2);

    printf("\nEnter the elements of matrix 2: ");
    for(int i=0; i<rows2; i++){
        for(int j=0; j<columns2; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nThe second matrix is:\n");
    printMatrix(matrix2, rows2, columns2);

    //matrix addition
    if(rows1 == rows2 && columns1 == columns2){
        printf("\nAddition of the two matrices is:\n");
        for(int i=0; i<rows1; i++){
            for(int j=0; j<columns1; j++){
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        printMatrix(result, rows1, columns1);
    }else{
        printf("\nAddition cannot be performed as the matrices are of different size!\n");
    }

    //matrix subtraction
    if(rows1 == rows2 && columns1 == columns2){
        printf("\nSubtraction of the two matrices is:\n");
        for(int i=0; i<rows1; i++){
            for(int j=0; j<columns1; j++){
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            }
        }
        printMatrix(result, rows1, columns1);
    }else{
        printf("\nSubtraction cannot be performed as the matrices are of different size!\n");
    }

    //matrix multiplication
    if(columns1 == rows2){
        printf("\nMultiplication of the two matrices is:\n");
        for(int i=0; i<rows1; i++){
            for(int j=0; j<columns2; j++){
                result[i][j] = 0;
                for(int k=0; k<columns1; k++){
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        printMatrix(result, rows1, columns2);
    }else{
        printf("\nMultiplication cannot be performed as the number of columns of matrix 1 is not equal to the number of rows of matrix 2!\n");
    }

    return 0;
}