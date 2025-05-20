//FormAI DATASET v1.0 Category: Matrix operations ; Style: active
#include <stdio.h>

int main()
{
    int m, n, p, q, i, j, k, choice;
    float a[10][10], b[10][10], c[10][10], transpose[10][10];

    printf("Enter the size of the first matrix (m x n): ");
    scanf("%d %d", &m, &n);

    printf("Enter the size of the second matrix (p x q): ");
    scanf("%d %d", &p, &q);

    if (n != p)
    {
        printf("Error: matrices cannot be multiplied.\n");
        return 0;
    }

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%f", &b[i][j]);
        }
    }

    printf("Choose an operation to perform on the matrices:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Transpose\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            if (m != p || n != q)
            {
                printf("Error: matrices must be the same size for addition.\n");
                return 0;
            }

            printf("The sum of the matrices is:\n");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    c[i][j] = a[i][j] + b[i][j];
                    printf("%.2f ", c[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            if (m != p || n != q)
            {
                printf("Error: matrices must be the same size for subtraction.\n");
                return 0;
            }

            printf("The difference of the matrices is:\n");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    c[i][j] = a[i][j] - b[i][j];
                    printf("%.2f ", c[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:
            printf("The product of the matrices is:\n");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < q; j++)
                {
                    c[i][j] = 0;
                    for (k = 0; k < n; k++)
                    {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                    printf("%.2f ", c[i][j]);
                }
                printf("\n");
            }
            break;

        case 4:
            printf("The transpose of the first matrix is:\n");
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    transpose[j][i] = a[i][j];
                    printf("%.2f ", transpose[j][i]);
                }
                printf("\n");
            }
            break;

        default:
            printf("Error: invalid choice.\n");
            break;
    }

    return 0;
}