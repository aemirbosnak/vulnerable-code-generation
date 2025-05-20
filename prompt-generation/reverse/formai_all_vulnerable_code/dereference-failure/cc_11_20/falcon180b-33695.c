//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int rows, cols;
    int **matrix;
    int **result;
    int i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    result = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
        result[i] = (int *)malloc(cols * sizeof(int));

    printf("Enter the operation (+ or -): ");
    char operation;
    scanf("%c", &operation);

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &result[i][j]);

    switch(operation)
    {
        case '+':
            for (i = 0; i < rows; i++)
                for (j = 0; j < cols; j++)
                    matrix[i][j] += result[i][j];
            break;

        case '-':
            for (i = 0; i < rows; i++)
                for (j = 0; j < cols; j++)
                    matrix[i][j] -= result[i][j];
            break;

        default:
            printf("Invalid operation!\n");
            exit(0);
    }

    printf("Result:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);

    return 0;
}