//FormAI DATASET v1.0 Category: Matrix operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, columns, i, j, matrix1[10][10], matrix2[10][10], sumMatrix[10][10], multiplyMatrix[10][10];

    printf("Enter the number of rows in the matrix: "); scanf("%d", &rows);

    printf("\nEnter the number of columns in the matrix: "); scanf("%d", &columns);

    printf("\nEnter the elements of the first matrix: \n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("Element %d, %d: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter the elements of the second matrix: \n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("Element %d, %d: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    /* Sum of two matrices */
    printf("\nSum of two matrices: \n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", sumMatrix[i][j]);
        }
        printf("\n");
    }

    /* Product of two matrices*/
    printf("\nProduct of two matrices: \n");
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            multiplyMatrix[i][j] = 0;
            for(int k = 0; k < columns; k++)
            {
                multiplyMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            printf("%d ", multiplyMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}