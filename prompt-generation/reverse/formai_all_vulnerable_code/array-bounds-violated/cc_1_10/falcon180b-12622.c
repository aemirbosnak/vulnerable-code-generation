//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

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
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = k;
                }
            }
        }
    }
}

void printSolution(int parent[V][V], int n) {
    int i, j;
    printf("Vertex\t Distance from Source\tPath\n");
    for (i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t", i, dist[0][i]);
        j = parent[0][i];
        printf("%d ", j);
        while (j!= -1) {
            j = parent[j][i];
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = { { 0, 4, INF, 0 },
                        { INF, 0, 8, 0 },
                        { INF, INF, 0, 2 },
                        { 0, INF, INF, 0 },
                        { INF, 5, INF, 0 },
                        { INF, INF, 1, INF },
                        { INF, 6, INF, INF },
                        { 2, INF, INF, INF },
                        { INF, INF, INF, 1 } };
    int source;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);
    printSolution(parent, V);

    return 0;
}