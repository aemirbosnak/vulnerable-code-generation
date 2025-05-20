//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int b = 3;
    int c = 2;

    int **arr1 = (int **)malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        arr1[i] = (int *)malloc(b * sizeof(int));
    }

    int **arr2 = (int **)malloc(c * sizeof(int *));
    for (int i = 0; i < c; i++)
    {
        arr2[i] = (int *)malloc(b * sizeof(int));
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            arr1[i][j] = 1;
        }
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < b; j++)
        {
            arr2[i][j] = 2;
        }
    }

    int **arr3 = (int **)malloc((a + c) * sizeof(int *));
    for (int i = 0; i < a + c; i++)
    {
        arr3[i] = (int *)malloc(b * sizeof(int));
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            arr3[i][j] = arr1[i][j];
        }
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < b; j++)
        {
            arr3[i][j] += arr2[i][j];
        }
    }

    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}