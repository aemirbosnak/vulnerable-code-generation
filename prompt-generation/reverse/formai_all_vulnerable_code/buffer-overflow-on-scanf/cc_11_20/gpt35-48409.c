//FormAI DATASET v1.0 Category: Matrix operations ; Style: careful
#include <stdio.h>

int main()
{
    int m1[100][100], m2[100][100], res[100][100];
    int r1, c1, r2, c2;
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d%d", &r1, &c1);
    printf("Enter the elements of matrix 1:\n");
    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d%d", &r2, &c2);
    printf("Enter the elements of matrix 2:\n");
    for(int i=0; i<r2; i++)
    {
        for(int j=0; j<c2; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    if(c1!=r2)
    {
        printf("Multiplication not possible!\n");
    }
    else
    {
        // Multiplying the matrices
        for(int i=0; i<r1; i++)
        {
            for(int j=0; j<c2; j++)
            {
                res[i][j] = 0;
                for(int k=0; k<c1; k++)
                {
                    res[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }

        // Printing the result
        printf("Resultant matrix:\n");
        for(int i=0; i<r1; i++)
        {
            for(int j=0; j<c2; j++)
            {
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
    }

    // Transposing the matrix
    printf("Transpose of matrix 1:\n");
    for(int i=0; i<c1; i++)
    {
        for(int j=0; j<r1; j++)
        {
            printf("%d ", m1[j][i]);
        }
        printf("\n");
    }

    // Finding the sum of elements in each row
    printf("Sum of elements in each row of matrix 2:\n");
    for(int i=0; i<r2; i++)
    {
        int rowSum = 0;
        for(int j=0; j<c2; j++)
        {
            rowSum += m2[i][j];
        }
        printf("%d ", rowSum);
    }
    printf("\n");

    return 0;
}