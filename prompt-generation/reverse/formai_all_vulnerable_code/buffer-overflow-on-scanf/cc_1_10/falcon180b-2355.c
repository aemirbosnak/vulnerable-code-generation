//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// function to find the minimum cost path using Dijkstra's algorithm
void dijkstra(int graph[10][10], int src, int dest) {
    int n = 9;
    int visited[n];
    int dist[n];
    int parent[n];

    // initializing distances and parents
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    // initializing distances for source node
    dist[src] = 0;

    // finding minimum cost path
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // printing the minimum cost path
    int path[n];
    int pathLength = 0;
    int v = dest;
    while (v!= -1) {
        path[pathLength++] = v;
        v = parent[v];
    }
    pathLength--;

    // printing the path in reverse order
    for (int i = pathLength; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

// function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int visited[], int n) {
    int min = INF;
    int minIndex;

    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// main function
int main() {
    int graph[10][10] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, {4, 0, 8, 0, 0, 0, 0, 11, 0}, {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 14, 0, 0, 0}, {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7}, {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    int src, dest;

    printf("Enter source vertex: ");
    scanf("%d", &src);

    printf("Enter destination vertex: ");
    scanf("%d", &dest);

    dijkstra(graph, src, dest);

    return 0;
}