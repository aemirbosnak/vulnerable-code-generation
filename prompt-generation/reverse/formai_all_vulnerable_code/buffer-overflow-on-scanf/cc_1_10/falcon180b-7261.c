//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 100

typedef struct {
    int v;
    int cost;
    int prev;
} Edge;

void dijkstra(int graph[MAX_V][MAX_V], int src, int dest) {
    int dist[MAX_V];
    int visited[MAX_V];
    int u, v, i, j, min_dist, k;

    for (i = 0; i < MAX_V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (i = 0; i < MAX_V - 1; i++) {
        for (j = 0; j < MAX_V; j++) {
            if (graph[j][k] && dist[j]!= INF && dist[j] + graph[j][k] < dist[k]) {
                dist[k] = dist[j] + graph[j][k];
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < MAX_V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[MAX_V][MAX_V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int src, dest;

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    dijkstra(graph, src, dest);

    return 0;
}