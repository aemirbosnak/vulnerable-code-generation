//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define V 9

int dist[V][V];
int parent[V][V];

void dijkstra(int graph[V][V], int src)
{
    int u, v, w, i, min_dist, min_index;

    for (u = 0; u < V; u++)
        dist[src][u] = graph[src][u];

    for (u = 0; u < V - 1; u++)
    {
        min_dist = INT_MAX;
        min_index = -1;

        for (v = 0; v < V; v++)
        {
            if (dist[src][v] <= min_dist)
            {
                min_dist = dist[src][v];
                min_index = v;
            }
        }

        u = min_index;

        for (v = 0; v < V; v++)
        {
            if ((dist[src][v] > dist[src][u] + graph[u][v]) && (parent[src][v] == -1))
            {
                dist[src][v] = dist[src][u] + graph[u][v];
                parent[src][v] = u;
            }
        }
    }
}

void print_solution(int parent[V][V], int dest)
{
    if (parent[dest][0] == -1)
        printf("\nNo path found");
    else
    {
        int v = dest;
        printf("\nPath from 0 to %d: ", dest);
        while (v!= -1)
        {
            printf("%d ", v);
            v = parent[dest][v];
        }
    }
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                     {2, 0, 3, 8, 5},
                     {0, 3, 0, 0, 7},
                     {6, 8, 0, 0, 9},
                     {0, 5, 7, 9, 0}};

    int src, dest;

    printf("\nEnter the source vertex: ");
    scanf("%d", &src);

    printf("\nEnter the destination vertex: ");
    scanf("%d", &dest);

    dijkstra(graph, src);

    print_solution(parent, dest);

    return 0;
}