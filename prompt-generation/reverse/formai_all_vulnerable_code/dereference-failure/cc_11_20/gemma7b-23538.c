//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, x, y;
    printf("Enter the number of test cases:");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter the number of rows:");
        scanf("%d", &x);

        printf("Enter the number of columns:");
        scanf("%d", &y);

        int **arr = (int **)malloc(x * sizeof(int *));
        for(k = 0; k < x; k++)
            arr[k] = (int *)malloc(y * sizeof(int));

        printf("Enter the matrix elements:");
        for(l = 0; l < x; l++)
        {
            for(m = 0; m < y; m++)
            {
                scanf("%d", &arr[l][m]);
            }
        }

        int max_sum = 0;
        for(l = 0; l < x; l++)
        {
            for(m = 0; m < y; m++)
            {
                int sum = 0;
                for(k = 0; k < x; k++)
                {
                    for(j = 0; j < y; j++)
                    {
                        if(k == l && j == m)
                            continue;
                        sum += arr[k][j];
                    }
                }
                if(sum > max_sum)
                    max_sum = sum;
            }
        }

        printf("The maximum sum of the submatrix is: %d", max_sum);
        printf("\n");
    }

    return 0;
}