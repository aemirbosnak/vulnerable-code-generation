//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void network_topology_mapper(int n)
{
    int i, j, k, graph[MAX][MAX], connectivity[MAX];
    graph[MAX][MAX] = 0;
    connectivity[MAX] = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter the connections between nodes (pair of nodes, separated by space): ");
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = 1;
    }

    for (i = 0; i < n; i++)
    {
        connectivity[i] = 0;
        for (j = 0; j < n; j++)
        {
            if (graph[j][i] == 1)
            {
                connectivity[i]++;
            }
        }
    }

    printf("The connectivity of each node is:");
    for (i = 0; i < n; i++)
    {
        printf(" Node %d: %d ", i + 1, connectivity[i]);
    }

    printf("\n");
}

int main()
{
    network_topology_mapper(10);
    return 0;
}