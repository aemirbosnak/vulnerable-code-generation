//FormAI DATASET v1.0 Category: Matrix operations ; Style: systematic
#include<stdio.h>

void matrix_addition(int row, int col, int matrix1[row][col], int matrix2[row][col], int result[row][col]){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_subtraction(int row, int col, int matrix1[row][col], int matrix2[row][col], int result[row][col]){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrix_multiplication(int row1, int col1, int matrix1[row1][col1], int row2, int col2, int matrix2[row2][col2], int result[row1][col2]){
    int i,j,k,sum;
    for(i=0;i<row1;i++){
        for(j=0;j<col2;j++){
            sum = 0;
            for(k=0;k<col1;k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
}

void matrix_transpose(int row, int col, int matrix[row][col], int result[col][row]){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            result[j][i] = matrix[i][j];
        }
    }
}

int main(){
    int row1, col1, row2, col2, i, j;
    printf("Enter number of rows and columns for matrix1: ");
    scanf("%d %d",&row1,&col1);
    int matrix1[row1][col1];
    printf("Enter elements for matrix1: \n");
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Enter number of rows and columns for matrix2: ");
    scanf("%d %d",&row2,&col2);
    int matrix2[row2][col2];
    printf("Enter elements for matrix2: \n");
    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }
    if(row1==row2 && col1==col2){
        int result[row1][col1];
        matrix_addition(row1,col1,matrix1,matrix2,result);
        printf("\nResult of matrix addition:\n");
        for(i=0;i<row1;i++){
            for(j=0;j<col1;j++){
                printf("%d ",result[i][j]);
            }
            printf("\n");
        }
        matrix_subtraction(row1,col1,matrix1,matrix2,result);
        printf("\nResult of matrix subtraction:\n");
        for(i=0;i<row1;i++){
            for(j=0;j<col1;j++){
                printf("%d ",result[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("\nMatrix addition and subtraction are not possible as dimensions are not same.\n");
    }
    if(col1==row2){
        int result[row1][col2];
        matrix_multiplication(row1,col1,matrix1,row2,col2,matrix2,result);
        printf("\nResult of matrix multiplication:\n");
        for(i=0;i<row1;i++){
            for(j=0;j<col2;j++){
                printf("%d ",result[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("\nMatrix Multiplication is not possible as number of columns of first matrix is not equal to number of rows of second matrix.\n");
    }
    int result_transpose[col1][row1];
    matrix_transpose(row1,col1,matrix1,result_transpose);
    printf("\nTranspose of matrix1:\n");
    for(i=0;i<col1;i++){
        for(j=0;j<row1;j++){
            printf("%d ",result_transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}