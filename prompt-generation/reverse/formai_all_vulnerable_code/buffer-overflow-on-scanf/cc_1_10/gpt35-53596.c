//FormAI DATASET v1.0 Category: Matrix operations ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void matrixAddition(int rows, int cols, int matrix1[10][10], int matrix2[10][10], int result[10][10]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void matrixMultiplication(int rows1, int cols1, int rows2, int cols2, int matrix1[10][10], int matrix2[10][10], int result[10][10]){
    if(cols1!=rows2){
        printf("Matrix multiplication not possible!\n");
        return;
    }
    else{
        for(int i=0;i<rows1;i++){
            for(int j=0;j<cols2;j++){
                result[i][j]=0;
                for(int k=0;k<cols1;k++){
                    result[i][j]+=matrix1[i][k]*matrix2[k][j];
                }
            }
        }
    }
}

// Driver function
int main(){
    int rows1, cols1, matrix1[10][10];
    int rows2, cols2, matrix2[10][10];
    int addResult[10][10], multResult[10][10];
    
    // Reading input for matrix 1
    printf("Enter number of rows and columns for matrix 1 (max 10): ");
    scanf("%d %d",&rows1,&cols1);
    printf("Enter elements for matrix 1:\n");
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }
    
    // Reading input for matrix 2
    printf("Enter number of rows and columns for matrix 2 (max 10): ");
    scanf("%d %d",&rows2,&cols2);
    printf("Enter elements for matrix 2:\n");
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }
    
    // Performing matrix addition
    matrixAddition(rows1,cols1,matrix1,matrix2,addResult);
    printf("Matrix Addition:\n");
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            printf("%d ",addResult[i][j]);
        }
        printf("\n");
    }
    
    // Performing matrix multiplication
    matrixMultiplication(rows1,cols1,rows2,cols2,matrix1,matrix2,multResult);
    printf("Matrix Multiplication:\n");
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols2;j++){
            printf("%d ",multResult[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}