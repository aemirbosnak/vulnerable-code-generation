//FormAI DATASET v1.0 Category: Matrix operations ; Style: brave
#include <stdio.h>

void add_matrices(int mat1[2][2], int mat2[2][2])
{
    int result[2][2];

    // Adding two matrices
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // Displaying the result
    printf("\nResultant Matrix:\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void multiply_matrices(int mat1[2][2], int mat2[2][2])
{
    int result[2][2];

    // Multiplying two matrices
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Displaying the result
    printf("\nResultant Matrix:\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, mat1[2][2], mat2[2][2];

    // Getting two matrices from user
    printf("Enter elements of first matrix (2x2):\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter elements of second matrix (2x2):\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Displaying menu to user
    printf("Menu:\n1. Add Matrices\n2. Multiply Matrices\nEnter your choice: ");
    scanf("%d", &choice);

    // Performing operation according to user's choice
    switch(choice)
    {
        case 1:
            add_matrices(mat1, mat2);
            break;
        case 2:
            multiply_matrices(mat1, mat2);
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}