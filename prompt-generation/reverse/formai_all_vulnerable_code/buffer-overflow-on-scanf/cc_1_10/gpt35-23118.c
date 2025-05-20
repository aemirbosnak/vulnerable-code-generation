//FormAI DATASET v1.0 Category: Matrix operations ; Style: automated
#include<stdio.h>
#include<stdlib.h>

void input_matrix(int m, int n, int matrix[m][n]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("Enter element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_matrix(int m, int n, int matrix[m][n]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(int m, int n, int matrix1[m][n], int matrix2[m][n], int result[m][n]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtract_matrix(int m, int n, int matrix1[m][n], int matrix2[m][n], int result[m][n]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiply_matrix(int m1, int n1, int matrix1[m1][n1], int m2, int n2, int matrix2[m2][n2], int result[m1][n2]){
    for(int i=0; i<m1; i++){
        for(int j=0; j<n2; j++){
            result[i][j] = 0;
            for(int k=0; k<n1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main(){
    int m1, n1, m2, n2;
    printf("Enter dimensions of matrix 1: ");
    scanf("%d %d", &m1, &n1);
    int matrix1[m1][n1];
    printf("Enter elements of matrix 1:\n");
    input_matrix(m1, n1, matrix1);
    printf("Matrix 1 is:\n");
    display_matrix(m1, n1, matrix1);
    printf("\n");
    
    printf("Enter dimensions of matrix 2: ");
    scanf("%d %d", &m2, &n2);
    int matrix2[m2][n2];
    printf("Enter elements of matrix 2:\n");
    input_matrix(m2, n2, matrix2);
    printf("Matrix 2 is:\n");
    display_matrix(m2, n2, matrix2);
    printf("\n");
    
    if(n1 != m2){
        printf("ERROR: The number of columns in Matrix 1 should be equal to the number of rows in Matrix 2 for multiplication.\n");
        exit(0);
    }
    
    int result[m1][n2];
    
    add_matrix(m1, n1, matrix1, matrix2, result);
    printf("Matrix 1 + Matrix 2 is:\n");
    display_matrix(m1, n1, result);
    printf("\n");
    
    subtract_matrix(m1, n1, matrix1, matrix2, result);
    printf("Matrix 1 - Matrix 2 is:\n");
    display_matrix(m1, n1, result);
    printf("\n");
    
    multiply_matrix(m1, n1, matrix1, m2, n2, matrix2, result);
    printf("Matrix 1 * Matrix 2 is:\n");
    display_matrix(m1, n2, result);
    printf("\n");
    
    return 0;
}