//Gemma-7B DATASET v1.0 Category: Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    printf("Enter the dimensions of the shape: ");
    scanf("%d %d", &x, &y);

    int **arr = (int **)malloc(x * sizeof(int *));
    for (int i = 0; i < x; i++)
    {
        arr[i] = (int *)malloc(y * sizeof(int));
    }

    printf("Enter the elements of the shape: ");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int dx = 2, dy = 2;
    for (int i = 0; i < dx; i++)
    {
        for (int j = 0; j < dy; j++)
        {
            for (int a = 0; a < x; a++)
            {
                for (int b = 0; b < y; b++)
                {
                    arr[a][b] = arr[a - dx][b - dy] + arr[a + dx][b - dy] + arr[a - dx][b + dy] + arr[a + dx][b + dy] + arr[a][b - dy] + arr[a][b + dy] + arr[a - dy][b] + arr[a + dy][b] + arr[a][b];
                }
            }
        }
    }

    printf("The shape after shifting is: ");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}