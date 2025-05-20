//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void map_topology(int **graph, int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                printf("%d - %d ", i, j);
                for (k = 0; k < n; k++)
                {
                    if (graph[i][k] == 1 && k != j)
                    {
                        printf("-> %d ", k);
                    }
                }
                printf("\n");
            }
        }
    }
}

int main()
{
    int **graph = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    map_topology(graph, n);

    return 0;
}