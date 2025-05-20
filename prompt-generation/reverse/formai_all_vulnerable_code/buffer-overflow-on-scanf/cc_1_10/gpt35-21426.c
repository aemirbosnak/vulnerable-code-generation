//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define INFINITY 9999999

int n, e;
int graph[MAX_NODES][MAX_NODES];

void prim()
{
    int visited[MAX_NODES] = {0};
    visited[0] = 1; 

    int min_distance[MAX_NODES];
    for(int i=0; i<n; i++)
        min_distance[i] = graph[0][i];

    int total_weight = 0;

    for(int i=0; i<n-1; i++)
    {
        int min_index = -1;
        for(int j=0; j<n; j++)
        {
            if(visited[j] == 0)
            {
                if(min_index == -1 || min_distance[j] < min_distance[min_index])
                    min_index = j;
            }
        }

        visited[min_index] = 1;
        total_weight += min_distance[min_index];

        for(int j=0; j<n; j++)
        {
            if(graph[min_index][j] != 0 && visited[j] == 0 && graph[min_index][j] < min_distance[j])
                min_distance[j] = graph[min_index][j];
        }
    }

    printf("Total weight of the minimum spanning tree: %d", total_weight);
}

int main()
{
    printf("Enter the number of nodes and edges of the graph: ");
    scanf("%d%d", &n, &e);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            graph[i][j] = INFINITY;
    }

    for(int i=0; i<e; i++)
    {
        int u, v, w;
        printf("Enter the source, destination, and weight of edge %d: ", i+1);
        scanf("%d%d%d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    prim();

    return 0;
}