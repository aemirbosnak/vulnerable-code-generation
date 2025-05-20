//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, x, y, z;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    printf("Enter the number of iterations: ");
    scanf("%d", &z);

    for(x = 0; x < z; x++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(arr[i][j] == 1)
                {
                    int r = rand() % 4;
                    switch(r)
                    {
                        case 0:
                            arr[i][j] = 0;
                            break;
                        case 1:
                            arr[i][j] = 1;
                            break;
                        case 2:
                            arr[i][j] = 2;
                            break;
                        case 3:
                            arr[i][j] = 3;
                            break;
                    }
                }
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}