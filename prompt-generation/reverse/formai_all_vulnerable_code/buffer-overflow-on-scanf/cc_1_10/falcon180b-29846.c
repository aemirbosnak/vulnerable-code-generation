//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define N 5 // Number of nodes in the graph
#define INF 9999 // Initialized to a large value

// Graph represented as an adjacency matrix
int graph[N][N] = {
    {0, 2, INF, 8, INF},
    {INF, 0, 1, INF, 2},
    {INF, INF, 0, 7, INF},
    {INF, INF, INF, 0, 4},
    {INF, INF, INF, INF, 0}
};

void printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int src, int dest, int dist[])
{
    int n = N;
    int u, v;
    int min_dist = 0;
    int sptSet[N]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    for (int i = 0; i < n; i++)
        dist[i] = INF, sptSet[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        min_dist = INF;
        u = -1;

        for (int i = 0; i < n; i++) {
            if (sptSet[i] == 0 && dist[i] <= min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }

        sptSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printSolution(dist, n);
}

int main()
{
    int source, destination;

    printf("Enter the source and destination nodes: ");
    scanf("%d %d", &source, &destination);

    dijkstra(source, destination, graph[source]);

    return 0;
}