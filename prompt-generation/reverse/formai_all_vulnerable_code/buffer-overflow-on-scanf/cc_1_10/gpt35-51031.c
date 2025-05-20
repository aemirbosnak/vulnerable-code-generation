//FormAI DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>

void input_matrix(int mat[10][10], int m, int n);
void display_matrix(int mat[10][10], int m, int n);
void add_matrices(int mat1[10][10], int mat2[10][10], int res[10][10], int m, int n);
void multiply_matrices(int mat1[10][10], int mat2[10][10], int res[10][10], int m1, int n1, int m2, int n2);
void transpose_matrix(int mat[10][10], int res[10][10], int m, int n);

int main()
{
    int mat1[10][10], mat2[10][10], res[10][10];
    int m1, n1, m2, n2, choice;

    printf("Enter size of Matrix 1 (mXn): ");
    scanf("%d%d", &m1, &n1);
    input_matrix(mat1, m1, n1);
    printf("\nMatrix 1:\n");
    display_matrix(mat1, m1, n1);

    printf("\nEnter size of Matrix 2 (mXn): ");
    scanf("%d%d", &m2, &n2);
    input_matrix(mat2, m2, n2);
    printf("\nMatrix 2:\n");
    display_matrix(mat2, m2, n2);

    printf("\nSelect operation:\n1. Addition\n2. Multiplication\n3. Transpose\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            if (m1 == m2 && n1 == n2)
            {
                add_matrices(mat1, mat2, res, m1, n1);
                printf("\nResultant Matrix:\n");
                display_matrix(res, m1, n1);
            }
            else
            {
                printf("Invalid operation: Number of rows and columns must be same for both matrices.\n");
            }
            break;

        case 2:
            if (n1 == m2)
            {
                multiply_matrices(mat1, mat2, res, m1, n1, m2, n2);
                printf("\nResultant Matrix:\n");
                display_matrix(res, m1, n2);
            }
            else
            {
                printf("Invalid operation: Number of columns in Matrix 1 must be same as number of rows in Matrix 2.\n");
            }
            break;

        case 3:
            printf("\nTranspose of Matrix 1:\n");
            transpose_matrix(mat1, res, m1, n1);
            display_matrix(res, n1, m1);
            printf("\nTranspose of Matrix 2:\n");
            transpose_matrix(mat2, res, m2, n2);
            display_matrix(res, n2, m2);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

void input_matrix(int mat[10][10], int m, int n)
{
    printf("Enter matrix elements:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void display_matrix(int mat[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int mat1[10][10], int mat2[10][10], int res[10][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiply_matrices(int mat1[10][10], int mat2[10][10], int res[10][10], int m1, int n1, int m2, int n2)
{
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < n1; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transpose_matrix(int mat[10][10], int res[10][10], int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res[i][j] = mat[j][i];
        }
    }
}