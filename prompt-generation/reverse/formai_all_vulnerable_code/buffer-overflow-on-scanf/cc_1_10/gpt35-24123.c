//FormAI DATASET v1.0 Category: Matrix operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **mat, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int** matrixAddition(int **mat1,int **mat2,int n){
    int **res = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        res[i] = (int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return res;
}

int** matrixSubtraction(int **mat1,int **mat2,int n){
    int **res = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        res[i] = (int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return res;
}

int** matrixMultiplication(int **mat1,int **mat2,int n){
    int **res = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        res[i] = (int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            res[i][j] = 0;
            for(int k=0;k<n;k++){
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return res;
}

int** matrixTranspose(int **mat,int n){
    int **res = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        res[i] = (int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            res[i][j] = mat[j][i];
        }
    }
    return res;
}

int main(){
    int n;
    printf("Enter the dimension of the square matrix: ");
    scanf("%d",&n);

    int **mat1 = (int **)malloc(n*sizeof(int *));
    int **mat2 = (int **)malloc(n*sizeof(int *));

    printf("Enter the elements of matrix 1:\n");
    for(int i=0;i<n;i++){
        mat1[i] = (int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("Enter the elements of matrix 2:\n");
    for(int i=0;i<n;i++){
        mat2[i] = (int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            scanf("%d",&mat2[i][j]);
        }
    }

    printf("Matrix 1:\n");
    printMatrix(mat1,n);

    printf("Matrix 2:\n");
    printMatrix(mat2,n);

    int **res = matrixAddition(mat1,mat2,n);
    printf("Matrix 1 + Matrix 2:\n");
    printMatrix(res,n);

    res = matrixSubtraction(mat1,mat2,n);
    printf("Matrix 1 - Matrix 2:\n");
    printMatrix(res,n);

    res = matrixMultiplication(mat1,mat2,n);
    printf("Matrix 1 * Matrix 2:\n");
    printMatrix(res,n);

    res = matrixTranspose(mat1,n);
    printf("Transpose of Matrix 1:\n");
    printMatrix(res,n);

    res = matrixTranspose(mat2,n);
    printf("Transpose of Matrix 2:\n");
    printMatrix(res,n);

    return 0;
}