//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: portable
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define V 9
#define INF INT_MAX

int dist[V][V];

void dijkstra(int graph[V][V], int src) {
    int u, v, i, j, min_dist, k;

    for (i = 0; i < V; i++)
        dist[src][i] = graph[src][i];

    for (k = 0; k < V - 1; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k]!= INF && dist[k][j]!= INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void printSolution(int dist[], int n) {
    int i, j;
    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = { { 0, 4, INF, 0, 0, 0, 0, 8, 0 },
                        { INF, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { INF, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 4, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 0, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { INF, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int source;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);

    printf("\nThe shortest distances from vertex %d to all other vertices are:\n", source);
    printSolution(dist[source], V);

    return 0;
}