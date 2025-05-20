//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rows1, cols1, rows2, cols2, i, j, k, sum = 0;
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    int **matrix1 = (int **) malloc(rows1 * sizeof(int *));
    for(i=0; i<rows1; i++)
    {
        matrix1[i] = (int *) malloc(cols1 * sizeof(int));
    }
    printf("Enter elements of first matrix:\n");
    for(i=0; i<rows1; i++)
    {
        for(j=0; j<cols1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    if(cols1!= rows2)
    {
        printf("Matrices cannot be multiplied with each other.\n");
        return 0;
    }
    int **matrix2 = (int **) malloc(rows2 * sizeof(int *));
    for(i=0; i<rows2; i++)
    {
        matrix2[i] = (int *) malloc(cols2 * sizeof(int));
    }
    printf("Enter elements of second matrix:\n");
    for(i=0; i<rows2; i++)
    {
        for(j=0; j<cols2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    int **multiplied_matrix = (int **) malloc(rows1 * sizeof(int *));
    for(i=0; i<rows1; i++)
    {
        multiplied_matrix[i] = (int *) malloc(cols2 * sizeof(int));
    }
    for(i=0; i<rows1; i++)
    {
        for(j=0; j<cols2; j++)
        {
            for(k=0; k<cols1; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            multiplied_matrix[i][j] = sum;
            sum = 0;
        }
    }
    printf("Multiplied matrix:\n");
    for(i=0; i<rows1; i++)
    {
        for(j=0; j<cols2; j++)
        {
            printf("%d\t", multiplied_matrix[i][j]);
        }
        printf("\n");
    }
    for(i=0; i<rows1; i++)
    {
        free(matrix1[i]);
    }
    free(matrix1);
    for(i=0; i<rows2; i++)
    {
        free(matrix2[i]);
    }
    free(matrix2);
    for(i=0; i<rows1; i++)
    {
        free(multiplied_matrix[i]);
    }
    free(multiplied_matrix);
    return 0;
}