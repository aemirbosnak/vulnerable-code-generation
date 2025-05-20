//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **arr;
    int r, c, i, j, k;
    int water_level = 0;
    int num_percolation = 0;

    printf("Enter the number of rows and columns:");
    scanf("%d %d", &r, &c);

    arr = (int *)malloc(r * c * sizeof(int));

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            arr[i][j] = 0;
        }
    }

    printf("Enter the number of water drops:");
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        printf("Enter the row and column of the water drop:");
        scanf("%d %d", &i, &j);

        arr[i][j] = 1;
    }

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (arr[i][j] == 1)
            {
                water_level++;
            }
        }
    }

    printf("The water level is:");
    printf("\n%d", water_level);

    return 0;
}