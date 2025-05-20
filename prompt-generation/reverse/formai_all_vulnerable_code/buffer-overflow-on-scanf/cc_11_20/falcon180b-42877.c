//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int rows,cols;
    printf("Enter number of rows: ");
    scanf("%d",&rows);
    printf("Enter number of columns: ");
    scanf("%d",&cols);
    int **matrix1=(int **)malloc(rows*sizeof(int*));
    int **matrix2=(int **)malloc(rows*sizeof(int*));
    int **matrix3=(int **)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++)
    {
        matrix1[i]=(int *)malloc(cols*sizeof(int));
        matrix2[i]=(int *)malloc(cols*sizeof(int));
        matrix3[i]=(int *)malloc(cols*sizeof(int));
    }
    printf("Enter elements of matrix 1:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Enter elements of matrix 2:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    printf("Sum of matrices:\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d\t",matrix3[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<rows;i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(matrix3[i]);
    }
    free(matrix1);
    free(matrix2);
    free(matrix3);
}