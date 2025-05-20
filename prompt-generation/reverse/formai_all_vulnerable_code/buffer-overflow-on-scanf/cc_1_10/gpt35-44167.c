//FormAI DATASET v1.0 Category: Matrix operations ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

//function to print a matrix
void printMatrix(int **mat, int rows, int cols){
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices
int** addMatrix(int **mat1,int **mat2,int rows,int cols){
    int **result;
    int i,j;
    result = (int**)malloc(sizeof(int*)*rows);
    for(i=0;i<rows;i++){
        result[i] = (int*)malloc(sizeof(int)*cols);
        for(j=0;j<cols;j++){
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

//function to subtract two matrices
int** subtractMatrix(int **mat1,int **mat2,int rows,int cols){
    int **result;
    int i,j;
    result = (int**)malloc(sizeof(int*)*rows);
    for(i=0;i<rows;i++){
        result[i] = (int*)malloc(sizeof(int)*cols);
        for(j=0;j<cols;j++){
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return result;
}

//function to multiply two matrices
int** multiplyMatrix(int **mat1,int **mat2,int rows1,int cols1,int cols2){
    int **result;
    int i,j,k;
    result = (int**)malloc(sizeof(int*)*rows1);
    for(i=0;i<rows1;i++){
        result[i] = (int*)malloc(sizeof(int)*cols2);
        for(j=0;j<cols2;j++){
            result[i][j] = 0;
            for(k=0;k<cols1;k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

//function to transpose a matrix
int** transposeMatrix(int **mat,int rows,int cols){
    int **result;
    int i,j;
    result = (int**)malloc(sizeof(int*)*cols);
    for(i=0;i<cols;i++){
        result[i] = (int*)malloc(sizeof(int)*rows);
        for(j=0;j<rows;j++){
            result[i][j] = mat[j][i];
        }
    }
    return result;
}

int main(){
    int rows1,cols1,rows2,cols2,i,j;
    int **mat1,**mat2,**result;

    //Getting input for matrix 1
    printf("Enter the number of rows and columns of matrix 1:\n");
    scanf("%d %d",&rows1,&cols1);
    mat1 = (int**)malloc(sizeof(int*)*rows1);
    printf("Enter the elements of matrix 1:\n");
    for(i=0;i<rows1;i++){
        mat1[i] = (int*)malloc(sizeof(int)*cols1);
        for(j=0;j<cols1;j++){
            scanf("%d",&mat1[i][j]);
        }
    }

    //Getting input for matrix 2
    printf("Enter the number of rows and columns of matrix 2:\n");
    scanf("%d %d",&rows2,&cols2);
    mat2 = (int**)malloc(sizeof(int*)*rows2);
    printf("Enter the elements of matrix 2:\n");
    for(i=0;i<rows2;i++){
        mat2[i] = (int*)malloc(sizeof(int)*cols2);
        for(j=0;j<cols2;j++){
            scanf("%d",&mat2[i][j]);
        }
    }

    //printing matrices
    printf("\nMatrix 1:\n");
    printMatrix(mat1,rows1,cols1);
    printf("\nMatrix 2:\n");
    printMatrix(mat2,rows2,cols2);

    //adding matrices
    if(rows1==rows2 && cols1==cols2){
        result = addMatrix(mat1,mat2,rows1,cols1);
        printf("\nAddition of matrix 1 and matrix 2:\n");
        printMatrix(result,rows1,cols1);
        for(i=0;i<rows1;i++){
            free(result[i]);
        }
        free(result);
    }
    else{
        printf("\nTwo matrices cannot be added as they have different dimensions.\n");
    }

    //subtracting matrices
    if(rows1==rows2 && cols1==cols2){
        result = subtractMatrix(mat1,mat2,rows1,cols1);
        printf("\nSubtraction of matrix 1 and matrix 2:\n");
        printMatrix(result,rows1,cols1);
        for(i=0;i<rows1;i++){
            free(result[i]);
        }
        free(result);
    }
    else{
        printf("\nTwo matrices cannot be subtracted as they have different dimensions.\n");
    }

    //multiplying matrices
    if(cols1==rows2){
        result = multiplyMatrix(mat1,mat2,rows1,cols1,cols2);
        printf("\nMultiplication of matrix 1 and matrix 2:\n");
        printMatrix(result,rows1,cols2);
        for(i=0;i<rows1;i++){
            free(result[i]);
        }
        free(result);
    }
    else{
        printf("\nTwo matrices cannot be multiplied as the number of columns of first matrix is not equal to the number of rows of second matrix.\n");
    }

    //transposing matrices
    printf("\nTranspose of matrix 1:\n");
    result = transposeMatrix(mat1,rows1,cols1);
    printMatrix(result,cols1,rows1);
    for(i=0;i<cols1;i++){
        free(result[i]);
    }
    free(result);

    printf("\nTranspose of matrix 2:\n");
    result = transposeMatrix(mat2,rows2,cols2);
    printMatrix(result,cols2,rows2);
    for(i=0;i<cols2;i++){
        free(result[i]);
    }
    free(result);

    //freeing memory
    for(i=0;i<rows1;i++){
        free(mat1[i]);
    }
    free(mat1);
    for(i=0;i<rows2;i++){
        free(mat2[i]);
    }
    free(mat2);

    return 0;
}