//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    int n, i, j, k, l, m, count = 0, graph[MAX][MAX], visited[MAX] = {0};

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
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
        printf("Enter the source node: ");
        scanf("%d", &k);

        printf("Enter the destination node: ");
        scanf("%d", &l);

        graph[k][l] = 1;
    }

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] && !visited[j])
                {
                    visited[j] = 1;
                    count++;
                }
            }
        }
    }

    printf("The number of connected components is: %d", count);

    return 0;
}