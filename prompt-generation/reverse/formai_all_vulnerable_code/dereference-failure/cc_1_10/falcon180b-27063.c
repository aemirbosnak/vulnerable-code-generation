//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: enthusiastic
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

    printf("\nVertex\t Distance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[src][i]);
    }
}

int main() {
    int graph[V][V] = { { 0, 4, INF, 0, 0, 0, 0, 8, 0 },
                        { INF, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { INF, INF, 0, 0, 0, 0, 0, 0, 2 },
                        { 0, 0, INF, 0, 0, 0, 0, 1, INF },
                        { 0, 0, 0, 0, 0, 7, 0, 0, 0 },
                        { 0, 0, INF, INF, 7, 0, 9, 0, 0 },
                        { INF, INF, 0, 0, INF, 9, 0, 0, 0 },
                        { 0, 11, 1, INF, 0, 0, 0, 0, INF },
                        { INF, 0, 2, INF, 0, 0, 0, 0, 1 } };

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);

    return 0;
}