//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100

int main()
{
    int n, i, j, k, l, m, flag = 0, found = 0;
    char **a, **b, **c, **d;

    a = (char **)malloc(MAX_N * sizeof(char *));
    b = (char **)malloc(MAX_N * sizeof(char *));
    c = (char **)malloc(MAX_N * sizeof(char *));
    d = (char **)malloc(MAX_N * sizeof(char *));

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        a[i] = (char *)malloc(MAX_N * sizeof(char));
        b[i] = (char *)malloc(MAX_N * sizeof(char));
        c[i] = (char *)malloc(MAX_N * sizeof(char));
        d[i] = (char *)malloc(MAX_N * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the connection between node %d and node %d (Y/N): ", i + 1, j + 1);
            scanf("%c", &c[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (c[i][j] == 'Y')
            {
                l = 0;
                for (k = 0; k < n; k++)
                {
                    if (c[k][i] == 'Y' && c[k][j] == 'Y')
                    {
                        l++;
                    }
                }
                if (l > 1)
                {
                    flag = 1;
                }
            }
        }
    }

    if (flag)
    {
        printf("Warning: There are nodes with more than one connection.\n");
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
        free(d[i]);
    }

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}