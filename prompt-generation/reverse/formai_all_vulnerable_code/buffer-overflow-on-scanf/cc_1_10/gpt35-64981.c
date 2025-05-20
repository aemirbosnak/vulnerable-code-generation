//FormAI DATASET v1.0 Category: Matrix operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Function to print matrix
void printMatrix(int m, int n, int matrix[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to add two matrices
void addMatrix(int m, int n, int matrix1[m][n],int matrix2[m][n],int result[m][n]){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int m, int n, int p, int q, int matrix1[m][n], int matrix2[p][q], int result[m][q]){
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            result[i][j] = 0;
            for(int k=0;k<n;k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void main(){
    int m,n,p,q;
    printf("Enter dimensions of first matrix:\n");
    scanf("%d %d",&m,&n);
    int matrix1[m][n];
    
    printf("Enter elements of matrix 1:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }
  
    printf("Enter dimensions of second matrix:\n");
    scanf("%d %d",&p,&q);
    int matrix2[p][q];
    
    printf("Enter elements of matrix 2:\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }
    
    // Perform matrix operations
    if(n == p){
        int result1[m][q];
        multiplyMatrix(m,n,p,q,matrix1,matrix2,result1);
        printf("Result of multiplication of matrices:\n");
        printMatrix(m,q,result1);
    }
    else{
        printf("Matrices cannot be multiplied!\n");
    }
        
    if(m == p && n == q){
        int result2[m][n];
        addMatrix(m,n,matrix1,matrix2,result2);
        printf("Result of addition of matrices:\n");
        printMatrix(m,n,result2);
    }
    else{
        printf("Matrices cannot be added!\n");
    }   
}