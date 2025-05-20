//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("Enter the dimensions of the matrix:");
    scanf("%d %d", &a, &b);

    int **arr = (int **)malloc(a * sizeof(int *));
    for(int i = 0; i < a; i++)
    {
        arr[i] = (int *)malloc(b * sizeof(int));
    }

    printf("Enter the elements of the matrix:");
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            scanf("%d ", &arr[i][j]);
        }
    }

    c = a * b;
    int **res = (int **)malloc(c * sizeof(int *));
    for(int i = 0; i < c; i++)
    {
        res[i] = (int *)malloc(b * sizeof(int));
    }

    int k = 0;
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            for(int l = 0; l < b; l++)
            {
                res[k][l] = 0;
                for(int m = 0; m < a; m++)
                {
                    res[k][l] += arr[m][j] * arr[m][l];
                }
                k++;
            }
        }
    }

    printf("The product of the matrices is:");
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < b; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    free(arr);
    free(res);

    return 0;
}