//FormAI DATASET v1.0 Category: Matrix operations ; Style: Dennis Ritchie
#include<stdio.h>

#define MAX_SIZE 10

void add_matrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                  int sum[MAX_SIZE][MAX_SIZE], int rows, int cols){
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiply_matrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                       int prod[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2){
    int i, j, k;
    for(i=0; i<rows1; i++){
        for(j=0; j<cols2; j++){
            prod[i][j] = 0;
            for(k=0; k<cols1; k++){
                prod[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void print_matrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols){
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    if(cols1 != rows2){
        printf("Error: Multiplication not possible.\n");
        return 0;
    }
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE], 
        prod[MAX_SIZE][MAX_SIZE];
    int i, j;
    printf("Enter the elements of first matrix: \n");
    for(i=0; i<rows1; i++){
        for(j=0; j<cols1; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter the elements of second matrix: \n");
    for(i=0; i<rows2; i++){
        for(j=0; j<cols2; j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    add_matrices(mat1, mat2, sum, rows1, cols1);
    multiply_matrices(mat1, mat2, prod, rows1, cols1, rows2, cols2);
    printf("First Matrix:\n");
    print_matrix(mat1, rows1, cols1);
    printf("Second Matrix:\n");
    print_matrix(mat2, rows2, cols2);
    printf("Sum of matrices:\n");
    print_matrix(sum, rows1, cols1);
    printf("Product of matrices:\n");
    print_matrix(prod, rows1, cols2);
    return 0;
}