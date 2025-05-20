//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graphColoring(int **graph, int n)
{
    int i, j, k, color, visited = 0, conflict = 0;
    int *colorArr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        colorArr[i] = -1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < graph[i][MAX]; j++)
        {
            if (colorArr[graph[i][j]] != -1 && colorArr[graph[i][j]] == colorArr[i])
            {
                conflict = 1;
            }
        }
    }

    if (conflict)
    {
        printf("No coloring possible\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            colorArr[i] = 0;
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < graph[i][MAX]; j++)
            {
                colorArr[graph[i][j]] = colorArr[i] + 1;
            }
        }

        printf("The coloring is:\n");
        for (i = 0; i < n; i++)
        {
            printf("Vertex %d has color %d\n", i, colorArr[i]);
        }
    }
}

int main()
{
    int n, i, j, graph[MAX][MAX];

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the adjacency list:");
    for (i = 0; i < n; i++)
    {
        graph[i][MAX] = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d ", &graph[i][j]);
            graph[i][MAX]++;
        }
    }

    graphColoring(graph, n);

    return 0;
}