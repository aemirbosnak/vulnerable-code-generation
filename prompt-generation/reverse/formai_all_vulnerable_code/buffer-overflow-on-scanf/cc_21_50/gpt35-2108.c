//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>

int main()
{
    // Let's start with a happy announcement!
    printf("Welcome to this cheerful program that performs Matrix Operations!\n");

    // Prompt the user to enter the dimensions of the matrices.
    printf("Please enter the dimensions of the first matrix.\n");

    int n, m;
    scanf("%d%d", &n, &m);

    // Create the matrices with the given dimensions.
    int matrix1[n][m], matrix2[n][m], sum[n][m], difference[n][m], product[n][m], transpose[n][m];

    // Prompt the user to enter the elements of the matrices.
    printf("Please enter the elements of the first matrix.\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Please enter the dimensions of the second matrix.\n");

    int p, q;
    scanf("%d%d", &p, &q);

    // Check if the dimensions satisfy the condition for matrix multiplication.
    if (m != p)
    {
        printf("Oops, the dimensions do not satisfy the condition for matrix multiplication!\n");
        return 0;
    }

    // Prompt the user to enter the elements of the second matrix.
    printf("Please enter the elements of the second matrix.\n");

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform the matrix operations.
    // Sum
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Difference
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    // Product
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            int temp = 0;

            for (int k = 0; k < m; k++)
            {
                temp += matrix1[i][k] * matrix2[k][j];
            }

            product[i][j] = temp;
        }
    }

    // Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            transpose[j][i] = matrix1[i][j];
        }
    }

    // Output the results.
    printf("The sum of the matrices is:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", sum[i][j]);
        }

        printf("\n");
    }

    printf("The difference of the matrices is:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", difference[i][j]);
        }

        printf("\n");
    }

    printf("The product of the matrices is:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            printf("%d ", product[i][j]);
        }

        printf("\n");
    }

    printf("The transpose of the matrix is:\n");

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", transpose[i][j]);
        }

        printf("\n");
    }

    // A positive message to end the program!
    printf("Hooray! All matrix operations have been performed successfully!\n");

    return 0;
}