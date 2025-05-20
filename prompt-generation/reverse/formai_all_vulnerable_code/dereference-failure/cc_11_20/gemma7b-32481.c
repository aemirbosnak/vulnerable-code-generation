//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, x, y, a, b, c, d, e, f, g, h, k, l, o, p, q, r, s, t, u, v, w, z;
    scanf("Enter the number of test cases:", &t);
    for(i = 0; i < t; i++)
    {
        scanf("Enter the number of points:", &n);
        int **arr = (int **)malloc(n * sizeof(int *));
        for(j = 0; j < n; j++)
        {
            arr[j] = (int *)malloc(2 * sizeof(int));
            scanf("Enter the coordinates of the point:", &arr[j][0], &arr[j][1]);
        }
        scanf("Enter the number of lines:", &m);
        int **lines = (int **)malloc(m * sizeof(int *));
        for(j = 0; j < m; j++)
        {
            lines[j] = (int *)malloc(2 * sizeof(int));
            scanf("Enter the coordinates of the line:", &lines[j][0], &lines[j][1]);
        }
        int **result = (int **)malloc(n * sizeof(int *));
        for(j = 0; j < n; j++)
        {
            result[j] = (int *)malloc(m * sizeof(int));
            result[j][0] = 0;
            for(k = 0; k < m; k++)
            {
                int flag = 0;
                for(l = 0; l < n; l++)
                {
                    if(arr[l][0] == lines[k][0] && arr[l][1] == lines[k][1])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    result[j][0]++;
                }
            }
        }
        for(j = 0; j < n; j++)
        {
            printf("The number of points that are not connected to any line is: %d\n", result[j][0]);
        }
        free(arr);
        free(lines);
        free(result);
    }
    return 0;
}