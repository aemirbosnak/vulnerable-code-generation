//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODE 100
#define INF INT_MAX

int graph[NODE][NODE];

void dijkstra(int src, int dest) {
    int dist[NODE];
    int visited[NODE];
    int u, v;

    for (int i = 0; i < NODE; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 0; i < NODE - 1; i++) {
        for (int j = 0; j < NODE; j++) {
            for (int k = 0; k < NODE; k++) {
                if (dist[j]!= INF && dist[j] + graph[j][k] < dist[k]) {
                    dist[k] = dist[j] + graph[j][k];
                }
            }
        }
    }

    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < NODE; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int graph[NODE][NODE] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                              { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                              { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                              { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                              { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                              { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                              { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                              { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                              { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    int source, destination;

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    dijkstra(source, destination);

    return 0;
}