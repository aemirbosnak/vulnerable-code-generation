//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void graph_coloring(int **graph, int n, int k)
{
    int *colors = (int *)malloc(n * sizeof(int));
    int i, j, color = 0, flag = 0;

    for (i = 0; i < n; i++)
    {
        colors[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][0]; j++)
        {
            if (colors[graph[i][j]] == colors[i])
            {
                flag = 1;
            }
        }
    }

    if (!flag)
    {
        for (i = 0; i < n; i++)
        {
            colors[i] = color;
        }

        printf("The coloring is successful.\n");
    }
    else
    {
        printf("The coloring is not successful.\n");
    }

    free(colors);
}

int main()
{
    int **graph = (int **)malloc(MAX * sizeof(int *));
    int n, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &k);

    graph_coloring(graph, n, k);

    return 0;
}