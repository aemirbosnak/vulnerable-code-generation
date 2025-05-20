//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include<stdio.h>
#include<stdlib.h>

void matrixAddition(int **matrix1, int **matrix2, int **result, int rows, int columns){
    int i, j;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int **matrix1, int **matrix2, int **result, int rows, int columns){
    int i, j;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrixMultiplication(int **matrix1, int **matrix2, int **result, int rows1, int columns1, int rows2, int columns2){
    int i, j, k;
    for(i=0;i<rows1;i++){
        for(j=0;j<columns2;j++){
            result[i][j] = 0;
            for(k=0;k<columns1;k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main(){

    int rows1, columns1, rows2, columns2, i, j, choice;

    printf("Enter the number of rows and columns of first matrix:\n");
    scanf("%d %d",&rows1,&columns1);

    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for(i=0;i<rows1;i++){
        matrix1[i] = (int *)malloc(columns1 * sizeof(int));
    }

    printf("Enter the elements of first matrix:\n");
    for(i=0;i<rows1;i++){
        for(j=0;j<columns1;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of second matrix:\n");
    scanf("%d %d",&rows2,&columns2);

    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for(i=0;i<rows2;i++){
        matrix2[i] = (int *)malloc(columns2 * sizeof(int));
    }

    printf("Enter the elements of second matrix:\n");
    for(i=0;i<rows2;i++){
        for(j=0;j<columns2;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }

    int **result = (int **)malloc(rows1 * sizeof(int *));
    for(i=0;i<rows1;i++){
        result[i] = (int *)malloc(columns2 * sizeof(int));
    }

    printf("Choose the operation you want to perform:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n");
    scanf("%d",&choice);

    switch(choice){
        case 1: matrixAddition(matrix1, matrix2, result, rows1, columns1);
                printf("The result of addition of the matrices is:\n");
                for(i=0;i<rows1;i++){
                    for(j=0;j<columns1;j++){
                        printf("%d ",result[i][j]);
                    }
                    printf("\n");
                }
                break;
        case 2: matrixSubtraction(matrix1, matrix2, result, rows1, columns1);
                printf("The result of subtraction of the matrices is:\n");
                for(i=0;i<rows1;i++){
                    for(j=0;j<columns1;j++){
                        printf("%d ",result[i][j]);
                    }
                    printf("\n");
                }
                break;
        case 3: if(columns1 == rows2){
                    matrixMultiplication(matrix1, matrix2, result, rows1, columns1, rows2, columns2);
                    printf("The result of multiplication of the matrices is:\n");
                    for(i=0;i<rows1;i++){
                        for(j=0;j<columns2;j++){
                            printf("%d ",result[i][j]);
                        }
                        printf("\n");
                    }
                }
                else{
                    printf("Matrix multiplication is not possible\n");
                }
                break;
        default: printf("Invalid choice\n");
                 break;
    }

    for(i=0;i<rows1;i++){
        free(matrix1[i]);
    }
    free(matrix1);

    for(i=0;i<rows2;i++){
        free(matrix2[i]);
    }
    free(matrix2);

    for(i=0;i<rows1;i++){
        free(result[i]);
    }
    free(result);

    return 0;
}