//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void find_perimeter(int **arr, int n)
{
    int i, j, total = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                total += 2;
            }
        }
    }

    printf("The perimeter of the polygon is: %d\n", total);
}

int main()
{
    int n, i, j, **arr;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the coordinates of the vertices: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    find_perimeter(arr, n);

    free(arr);

    return 0;
}