//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void solve(int **graph, int n)
{
    int i, j, k, color, count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                for (k = 0; k < n; k++)
                {
                    if (graph[i][k] == 1 && graph[k][j] == 1)
                    {
                        color = 0;
                        while (color == 0)
                        {
                            color = rand() % MAX;
                        }
                        graph[i][k] = graph[k][j] = color;
                        count++;
                    }
                }
            }
        }
    }

    printf("Number of colors used: %d\n", count);
}

int main()
{
    int n, i, graph[MAX][MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    solve(graph, n);

    return 0;
}