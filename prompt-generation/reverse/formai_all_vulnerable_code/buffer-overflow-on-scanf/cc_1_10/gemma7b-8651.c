//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int i, j, k, n, graph[MAX][MAX], color[MAX], used[MAX], max_color = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &k);

    printf("Enter the edges: ");
    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &graph[i][0], &graph[i][1]);
    }

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        used[i] = 0;
    }

    for (i = 0; i < k; i++)
    {
        used[graph[i][0]] = 1;
        used[graph[i][1]] = 1;
    }

    for (i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            color[i] = max_color + 1;
            max_color++;
        }
    }

    printf("The maximum number of colors is: %d", max_color);

    return 0;
}