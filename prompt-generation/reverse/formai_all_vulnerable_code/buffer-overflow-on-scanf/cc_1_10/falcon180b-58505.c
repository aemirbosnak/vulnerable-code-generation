//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 99999

typedef struct Edge{
    int v;
    int w;
    int cost;
}Edge;

int minDistance(int dist[], int sptSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < MAX_NODES; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int n)
{
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t %d\n", i, dist[i]);
}

void dijkstra(Edge graph[MAX_EDGES], int src, int dest)
{
    int n = 2;
    int dist[MAX_NODES];
    int sptSet[MAX_NODES];

    memset(sptSet, 0, sizeof(sptSet));
    memset(dist, INF, sizeof(dist));

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = 1;

        for (int v = 0; v < n; v++)

            if (!sptSet[v] && graph[u].cost && graph[u].cost + dist[u] < dist[v])
                dist[v] = dist[u] + graph[u].cost;
    }

    printf("The shortest distance from %d to %d is %d\n", src, dest, dist[dest]);
}

int main()
{
    int graph[MAX_EDGES][3] = { { 0, 4, 0 }, { INF, 0, 8 }, { INF, INF, 0 }, { 0, 8, INF }, { INF, INF, 2 } };
    int source, destination;

    printf("Enter the source node: ");
    scanf("%d", &source);

    printf("Enter the destination node: ");
    scanf("%d", &destination);

    dijkstra(graph, source, destination);

    return 0;
}