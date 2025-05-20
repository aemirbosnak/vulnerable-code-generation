//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int main()
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int i, j, k, r, s;

    printf("Enter the number of rows and columns for the matrices (separated by a space): ");
    scanf("%d %d", &r, &s);

    printf("Enter the elements of the first matrix (separated by space): ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < s; j++)
        {
            scanf("%d ", &a[i][j]);
        }
    }

    printf("Enter the elements of the second matrix (separated by space): ");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < s; j++)
        {
            scanf("%d ", &b[i][j]);
        }
    }

    printf("Performing matrix multiplication...\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < s; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < MAX; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("The product of the two matrices is:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < s; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}