//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODES 9
#define INF INT_MAX

typedef struct {
    int x;
    int y;
} Node;

Node graph[NODES] = {
    {0, 0}, {0, 1}, {0, 2}, {1, 0},
    {1, 1}, {1, 2}, {2, 0}, {2, 1},
    {2, 2}
};

void printSolution(int dist[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int src, int dest) {
    int dist[NODES];
    int visited[NODES];

    for (int i = 0; i < NODES; i++)
        dist[i] = INF, visited[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < NODES - 1; count++) {
        int u = minDistance(dist, visited);

        visited[u] = 1;

        for (int v = 0; v < NODES; v++)

            if (!visited[v] && graph[u].x == graph[v].x ||
                graph[u].y == graph[v].y &&
                dist[u]!= INF && dist[u] + 1 < dist[v])
                dist[v] = dist[u] + 1;
    }

    printSolution(dist, NODES);
}

int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;

    for (int v = 0; v < NODES; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

int main() {
    int source, destination;

    printf("Enter the source node: ");
    scanf("%d", &source);

    printf("Enter the destination node: ");
    scanf("%d", &destination);

    dijkstra(source, destination);

    return 0;
}