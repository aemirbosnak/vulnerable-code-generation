//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4

// Graph represented as an adjacency matrix
int graph[V][V] = { { 0, 2, INF, 1 },
                    { INF, 0, 1, INF },
                    { INF, INF, 0, 2 },
                    { INF, INF, INF, 0 } };

void printSolution(int dist[], int n) {
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int src, int dest) {
    int dist[V];
    int visited[V];

    // Initialize all distances as INF and visited[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INF, visited[i] = 0;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, visited);

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex, if it is not equal to INF
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(dist, V);
}

// Function that returns the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Driver program to test above functions
int main() {
    int source, destination;

    // Add your own test cases here
    source = 0;
    destination = 3;

    printf("The shortest distance from %d to %d is: ", source, destination);
    dijkstra(source, destination);

    return 0;
}