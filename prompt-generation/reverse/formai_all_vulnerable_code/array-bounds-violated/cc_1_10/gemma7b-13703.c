//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main()
{
    int n, m, i, j, k, l, graph[100][100], color[100], max_color = 0;
    char str[10000];

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    graph[n][m] = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    k = 0;
    while (k < n)
    {
        l = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (graph[i][j] && color[i] == -1)
                {
                    color[i] = l;
                    l++;
                }
            }
        }

        max_color = fmax(max_color, l);
        k++;
    }

    printf("The maximum number of colors is: %d\n", max_color);

    return 0;
}