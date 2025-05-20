//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

typedef struct{
    int rows;
    int cols;
    int **matrix;
}Matrix;

void create_matrix(Matrix* mat, int rows, int cols){
    mat->rows = rows;
    mat->cols = cols;
    mat->matrix = (int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++){
        mat->matrix[i] = (int*)malloc(cols*sizeof(int));
        for(int j=0;j<cols;j++){
            mat->matrix[i][j] = 0;
        }
    }
}

void print_matrix(Matrix mat){
    for(int i=0;i<mat.rows;i++){
        for(int j=0;j<mat.cols;j++){
            printf("%d ",mat.matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(Matrix mat1, Matrix mat2, Matrix* result){
    if(mat1.rows!=mat2.rows || mat1.cols!=mat2.cols){
        printf("Cannot add matrices of different sizes\n");
        return;
    }
    create_matrix(result,mat1.rows,mat1.cols);
    for(int i=0;i<mat1.rows;i++){
        for(int j=0;j<mat1.cols;j++){
            result->matrix[i][j] = mat1.matrix[i][j] + mat2.matrix[i][j];
        }
    }
}

void multiply_matrices(Matrix mat1, Matrix mat2, Matrix* result){
    if(mat1.cols!=mat2.rows){
        printf("Cannot multiply matrices of different sizes\n");
        return;
    }
    create_matrix(result,mat1.rows,mat2.cols);
    for(int i=0;i<mat1.rows;i++){
        for(int j=0;j<mat2.cols;j++){
            int sum=0;
            for(int k=0;k<mat1.cols;k++){
                sum += mat1.matrix[i][k]*mat2.matrix[k][j];
            }
            result->matrix[i][j] = sum;
        }
    }
}

void transpose_matrix(Matrix mat, Matrix* result){
    create_matrix(result,mat.cols,mat.rows);
    for(int i=0;i<mat.rows;i++){
        for(int j=0;j<mat.cols;j++){
            result->matrix[j][i] = mat.matrix[i][j];
        }
    }
}

int main(){
    Matrix mat1, mat2, result;
    create_matrix(&mat1,3,3);
    create_matrix(&mat2,3,3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            mat1.matrix[i][j] = i+j;
            mat2.matrix[i][j] = i-j;
        }
    }
    add_matrices(mat1,mat2,&result);
    print_matrix(result);
    multiply_matrices(mat1,mat2,&result);
    print_matrix(result);
    transpose_matrix(mat1,&result);
    print_matrix(result);
    return 0;
}