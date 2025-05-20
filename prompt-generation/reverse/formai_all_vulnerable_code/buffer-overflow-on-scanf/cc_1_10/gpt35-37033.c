//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include<stdio.h>
#include<stdlib.h>

void displayMatrix(int **matrix, int row, int col)
{
    printf("Here's your matrix:\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int findSum(int **matrix, int row, int col)
{
    int sum = 0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int** transpose(int **matrix, int row, int col)
{
    int **new_matrix = (int**)malloc(sizeof(int*)*col);
    for(int i=0;i<col;i++)
    {
        new_matrix[i] = (int*)malloc(sizeof(int)*row);
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            new_matrix[j][i] = matrix[i][j];
        }
    }
    return new_matrix;
}

int main()
{
    int row, col;
    printf("Hello user! Let's play with matrices today!\n");
    printf("Enter number of rows:");
    scanf("%d", &row);
    printf("Enter number of columns:");
    scanf("%d", &col);

    int** matrix = (int**)malloc(sizeof(int*)*row);
    for(int i=0;i<row;i++)
    {
        matrix[i] = (int*)malloc(sizeof(int)*col);
    }

    printf("Enter the elements of the matrix:\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("Enter element[%d][%d]:", i+1, j+1);
            scanf("%d",&matrix[i][j]);
        }
    }

    displayMatrix(matrix, row, col);
    printf("The sum of all the elements in the matrix is %d\n", findSum(matrix, row, col));

    int** new_matrix = transpose(matrix, row, col);
    printf("Transpose of your matrix is:\n");
    displayMatrix(new_matrix, col, row);

    for(int i=0;i<row;i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    for(int i=0;i<col;i++)
    {
        free(new_matrix[i]);
    }
    free(new_matrix);

    printf("Have a great day!\n");
    return 0;
}