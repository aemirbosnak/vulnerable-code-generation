//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 9

// Define the graph as a 2D array
int graph[V][V] = { { 0, 4, INF, 0, INF, 0, INF, INF, INF },
                    { INF, 0, 8, INF, 0, 0, 0, INF, INF },
                    { INF, INF, 0, 2, 0, 0, 0, 0, INF },
                    { 0, INF, INF, 0, 1, INF, INF, INF, 6 },
                    { INF, 0, 0, INF, 0, 5, INF, INF, INF },
                    { 0, INF, INF, INF, INF, 0, 3, INF, INF },
                    { INF, 0, INF, INF, INF, INF, 0, 1, INF },
                    { INF, INF, 0, INF, INF, INF, INF, 0, 7 },
                    { INF, INF, INF, INF, INF, INF, INF, INF, 0 } };

// Function to find the minimum distance value from distances array
int minDistance(int dist[], int sptSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int n)
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's single source shortest path algorithm
void dijkstra(int src, int dest)
{
    int dist[V], sptSet[V];

    // Initialize all distances as INFINITY and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INF, sptSet[i] = 0;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex, if it is not in sptSet
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

// Driver program to test above functions
int main()
{
    int source, destination;

    printf("Enter the source and destination vertices: ");
    scanf("%d %d", &source, &destination);

    dijkstra(source, destination);

    return 0;
}