//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define NODE_COUNT 9
#define INF INT_MAX

// Graph represented as adjacency matrix
int graph[NODE_COUNT][NODE_COUNT] = {
    {0, 4, INF, 0, 0, 0, INF, INF, INF},
    {INF, 0, 8, INF, 0, 0, 11, INF, 0},
    {INF, INF, 0, 7, 0, 4, 0, 2, INF},
    {0, INF, INF, 0, 9, 14, 0, 0, 6},
    {INF, 0, INF, INF, 0, 10, 2, 0, 1},
    {INF, INF, 2, INF, INF, 0, 0, 8, 7},
    {INF, INF, INF, 0, 0, INF, 1, INF, 9},
    {INF, INF, INF, INF, INF, INF, INF, 0, 5},
    {INF, INF, INF, INF, INF, INF, INF, INF, 0}
};

// Function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int sptSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < NODE_COUNT; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation
void dijkstra(int src)
{
    int dist[NODE_COUNT]; // The output array. dist[i] will hold the shortest distance from src to i

    int sptSet[NODE_COUNT]; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < NODE_COUNT; i++)
        dist[i] = INF, sptSet[i] = 0;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < NODE_COUNT - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex, if it is not in sptSet
        for (int v = 0; v < NODE_COUNT; v++)

            if (!sptSet[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < NODE_COUNT; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Driver program to test above functions
int main()
{
    dijkstra(0);

    return 0;
}