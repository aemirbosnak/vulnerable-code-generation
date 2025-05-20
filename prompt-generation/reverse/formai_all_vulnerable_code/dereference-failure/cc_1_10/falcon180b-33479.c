//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9
#define INF INT_MAX

int dist[V][V];
int parent[V][V];

void dijkstra(int graph[V][V], int src) {
    int u, v, i, j, min_dist, k;

    for (i = 0; i < V; i++) {
        dist[src][i] = graph[src][i];
        parent[src][i] = -1;
    }

    dist[src][src] = 0;

    for (k = 1; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k]!= INF && dist[k][j]!= INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = k;
                }
            }
        }
    }
}

void printSolution(int dist[], int n) {
    int i, j;
    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int source;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);

    printSolution(dist, V);

    return 0;
}