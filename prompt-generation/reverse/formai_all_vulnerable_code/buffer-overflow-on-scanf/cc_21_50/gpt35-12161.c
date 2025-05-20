//FormAI DATASET v1.0 Category: Matrix operations ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice, m1_row, m1_col, m2_row, m2_col, i, j, k, sum;
    int **matrix1, **matrix2, **result_matrix;

    printf("Enter number of rows and columns for Matrix 1 (separated by space): ");
    scanf("%d %d", &m1_row, &m1_col);

    printf("Enter number of rows and columns for Matrix 2 (separated by space): ");
    scanf("%d %d", &m2_row, &m2_col);

    if(m1_col != m2_row)
    {
        printf("Error! Number of columns for Matrix1 doesn't match number of rows for Matrix2.\n");
        exit(0);
    }

    //Allocate memory for matrix1
    matrix1 = (int**)malloc(m1_row * sizeof(int*));
    for(i=0;i<m1_row;i++)
        matrix1[i] = (int*)malloc(m1_col * sizeof(int));

    //Allocate memory for matrix2
    matrix2 = (int**)malloc(m2_row * sizeof(int*));
    for(i=0;i<m2_row;i++)
        matrix2[i] = (int*)malloc(m2_col * sizeof(int));

    //Allocate memory for result_matrix
    result_matrix = (int**)malloc(m1_row * sizeof(int*));
    for(i=0;i<m1_row;i++)
        result_matrix[i] = (int*)calloc(m2_col, sizeof(int));

    //Accept values for matrix1
    printf("\nEnter values for Matrix 1: \n");
    for(i=0;i<m1_row;i++)
    {
        printf("Enter Row %d Values (separated by space): ", i+1);
        for(j=0;j<m1_col;j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    //Accept values for matrix2
    printf("\nEnter values for Matrix 2: \n");
    for(i=0;i<m2_row;i++)
    {
        printf("Enter Row %d Values (separated by space): ", i+1);
        for(j=0;j<m2_col;j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("\nSelect an Matrix operation to perform: \n");
    printf("1. Addition of two matrices\n");
    printf("2. Subtraction of two matrices\n");
    printf("3. Multiplication of two matrices\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:     
                for(i=0;i<m1_row;i++)
                {
                    for(j=0;j<m1_col;j++)
                    {
                        result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
                    }
                }
                printf("\nAddition of Matrix 1 and Matrix 2 is:\n");
            break;

        case 2:
                for(i=0;i<m1_row;i++)
                {
                    for(j=0;j<m1_col;j++)
                    {
                        result_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
                    }
                }
                printf("\nSubtraction of Matrix 1 and Matrix 2 is:\n");
            break;

        case 3:
                for(i=0;i<m1_row;i++)
                {
                    for(j=0;j<m2_col;j++)
                    {
                        sum = 0;
                        for(k=0;k<m1_col;k++)
                        {
                            sum += matrix1[i][k] * matrix2[k][j];
                        }
                        result_matrix[i][j] = sum;
                    }
                }
                printf("\nMultiplication of Matrix 1 and Matrix 2 is:\n");
            break;

        default:
                printf("\nInvalid Choice!\n");
                exit(0);
    }

    //Print result matrix
    for(i=0;i<m1_row;i++)
    {
        for(j=0;j<m2_col;j++)
        {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    //Deallocate memory
    for(i=0;i<m1_row;i++)
        free(matrix1[i]);
    free(matrix1);

    for(i=0;i<m2_row;i++)
        free(matrix2[i]);
    free(matrix2);

    for(i=0;i<m1_row;i++)
        free(result_matrix[i]);
    free(result_matrix);

    return 0;
}