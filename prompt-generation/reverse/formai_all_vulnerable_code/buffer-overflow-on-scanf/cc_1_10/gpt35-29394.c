//FormAI DATASET v1.0 Category: Matrix operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

void addMatrix(int row, int col, int **a, int **b, int **c)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrix(int row, int col, int **a, int **b, int **c)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrix(int row1, int col1, int row2, int col2, int **a, int **b, int **c)
{
    if(col1 != row2)
    {
        printf("Error: Cannot multiply matrices with given dimensions.\n");
        return;
    }
    else
    {
        for(int i=0; i<row1; i++)
        {
            for(int j=0; j<col2; j++)
            {
                c[i][j] = 0;
                for(int k=0; k<col1; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
}

int main()
{
    int row1, col1, row2, col2;
    printf("Enter dimensions of Matrix A: ");
    scanf("%d %d", &row1, &col1);
    printf("Enter dimensions of Matrix B: ");
    scanf("%d %d", &row2, &col2);

    // Dynamically allocate memory for matrices A, B and C
    int **a = (int **)malloc(row1 * sizeof(int *));
    for(int i=0; i<row1; i++)
    {
        a[i] = (int *)malloc(col1 * sizeof(int));
    }
    int **b = (int **)malloc(row2 * sizeof(int *));
    for(int i=0; i<row2; i++)
    {
        b[i] = (int *)malloc(col2 * sizeof(int));
    }
    int **c = (int **)malloc(row1 * sizeof(int *));
    for(int i=0; i<row1; i++)
    {
        c[i] = (int *)malloc(col2 * sizeof(int));
    }

    // Input matrices A and B from user
    printf("Enter elements of Matrix A: \n");
    for(int i=0; i<row1; i++)
    {
        for(int j=0; j<col1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements of Matrix B: \n");
    for(int i=0; i<row2; i++)
    {
        for(int j=0; j<col2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Perform matrix operations
    int choice;
    printf("Menu:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            if(row1 == row2 && col1 == col2)
            {
                addMatrix(row1, col1, a, b, c);
                printf("Sum of Matrices is: \n");
                for(int i=0; i<row1; i++)
                {
                    for(int j=0; j<col1; j++)
                    {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Error: Cannot add matrices with different dimensions.\n");
            }
            break;
        case 2:
            if(row1 == row2 && col1 == col2)
            {
                subtractMatrix(row1, col1, a, b, c);
                printf("Difference of Matrices is: \n");
                for(int i=0; i<row1; i++)
                {
                    for(int j=0; j<col1; j++)
                    {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("Error: Cannot subtract matrices with different dimensions.\n");
            }
            break;
        case 3:
            multiplyMatrix(row1, col1, row2, col2, a, b, c);
            printf("Product of Matrices is: \n");
            for(int i=0; i<row1; i++)
            {
                for(int j=0; j<col2; j++)
                {
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    // Free the memory
    for(int i=0; i<row1; i++)
    {
        free(a[i]);
    }
    free(a);
    for(int i=0; i<row2; i++)
    {
        free(b[i]);
    }
    free(b);
    for(int i=0; i<row1; i++)
    {
        free(c[i]);
    }
    free(c);

    return 0;
}