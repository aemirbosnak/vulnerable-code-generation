//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i, j, k, l, m, n, x, y, z;
    int graph[MAX][MAX];
    int visited[MAX];

    printf("Enter the number of nodes:");
    scanf("%d", &n);

    printf("Enter the number of edges:");
    scanf("%d", &m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < m; i++)
    {
        printf("Enter the source node:");
        scanf("%d", &x);

        printf("Enter the destination node:");
        scanf("%d", &y);

        graph[x][y] = 1;
    }

    printf("Enter the starting node:");
    scanf("%d", &z);

    visited[z] = 1;

    for (l = 0; visited[l] != 1; l++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] && visited[i] && !visited[j])
                {
                    visited[j] = 1;
                    printf("Node %d visited from node %d\n", j, i);
                }
            }
        }
    }

    return 0;
}