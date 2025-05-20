//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define V 9

int graph[V][V];
int dist[V];
int parent[V];

void dijkstra(int src) {
    int u, v, i, min, k;
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (k = 0; k < V - 1; k++) {
        for (i = 0; i < V; i++) {
            for (u = 0; u < V; u++) {
                if (graph[i][u] && dist[i]!= INT_MAX && dist[i] + graph[i][u] < dist[u]) {
                    dist[u] = dist[i] + graph[i][u];
                    parent[u] = i;
                }
            }
        }
    }

    printf("\nVertex\t Distance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
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

    printf("\nEnter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}