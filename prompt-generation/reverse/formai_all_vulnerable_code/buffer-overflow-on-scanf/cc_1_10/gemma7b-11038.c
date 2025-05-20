//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **a = NULL;
    int n, m, i, j, k, l;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    a = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(m * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The matrix is: ");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("The transpose of the matrix is: ");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            free(a[i][j]);
        }
        free(a[i]);
    }
    free(a);

    return 0;
}