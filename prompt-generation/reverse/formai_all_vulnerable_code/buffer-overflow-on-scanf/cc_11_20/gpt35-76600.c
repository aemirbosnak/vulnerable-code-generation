//FormAI DATASET v1.0 Category: Matrix operations ; Style: detailed
#include <stdio.h>

int main()
{
    // Declare matrices
    int A[3][3], B[3][3], C[3][3];
    int choice, i, j, k;

    // Get user choice for operation
    printf("Enter 1 to add two matrices\nEnter 2 to subtract two matrices\nEnter 3 to multiply two matrices\n");
    scanf("%d", &choice);

    // Get values of matrix A
    printf("\nEnter values for matrix A:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter value for A[%d][%d]: ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }

    // Get values of matrix B
    printf("\nEnter values for matrix B:\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter value for B[%d][%d]: ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }

    // Compute chosen operation
    switch(choice)
    {
        case 1:
        	// Add matrices A and B
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    C[i][j] = A[i][j] + B[i][j];
                }
            }
            printf("\nMatrix A + B =\n");
            break;
        case 2:
        	// Subtract matrices A and B
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    C[i][j] = A[i][j] - B[i][j];
                }
            }
            printf("\nMatrix A - B =\n");
            break;
        case 3:
        	// Multiply matrices A and B
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    C[i][j] = 0;
                    for(k=0;k<3;k++)
                    {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            printf("\nMatrix A * B =\n");
            break;
        default:
            printf("\nInvalid choice!\n");
            return 0;
    }

    // Display resulting matrix C
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}