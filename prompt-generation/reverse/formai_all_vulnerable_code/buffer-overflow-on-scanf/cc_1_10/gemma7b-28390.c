//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i, j, k, n, m, graph[MAX][MAX], distance[MAX], parent[MAX];
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("Enter the number of edges:");
    scanf("%d", &m);
    for (i = 0; i < n; i++)
    {
        distance[i] = -1;
        parent[i] = -1;
    }
    for (i = 0; i < m; i++)
    {
        scanf("Enter the source node:");
        k = atoi(stdin);
        scanf("Enter the destination node:");
        j = atoi(stdin);
        graph[k][j] = 1;
    }
    distance[0] = 0;
    parent[0] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] && distance[i] != -1 && distance[j] != -1)
            {
                if (distance[i] + 1 < distance[j])
                {
                    distance[j] = distance[i] + 1;
                    parent[j] = i;
                }
            }
        }
    }
    printf("The shortest path is:");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", parent[i]);
    }
    printf("\nThe total distance is:");
    printf("%d", distance[n - 1]);
    return 0;
}