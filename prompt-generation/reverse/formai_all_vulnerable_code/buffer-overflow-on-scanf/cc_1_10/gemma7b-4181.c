//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, graph[100][100], color[100], maximum_color = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    graph[n][m] = malloc(sizeof(int) * m);

    printf("Enter the edges: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &j, &k);
        graph[j][k] = 1;
    }

    color[n] = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        int available_colors = 0;
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && color[j] != -1)
            {
                available_colors++;
            }
        }

        color[i] = available_colors;
    }

    for (i = 0; i < n; i++)
    {
        maximum_color = fmax(maximum_color, color[i]);
    }

    printf("The maximum number of colors is: %d", maximum_color);

    return 0;
}