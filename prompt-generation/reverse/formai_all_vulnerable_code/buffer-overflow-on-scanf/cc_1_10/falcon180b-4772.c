//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4
#define E 6

int graph[V][V] = {
    { 0, 3, INF, 2 },
    { INF, 0, 1, INF },
    { INF, INF, 0, 4 },
    { INF, INF, INF, 0 }
};

void dijkstra(int start) {
    int dist[V], prev[V], visited[V] = { 0 };
    int u, v, i, min_dist;

    for (i = 0; i < V; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < V - 1; i++) {
        min_dist = INF;
        u = -1;

        for (int j = 0; j < V; j++) {
            if (!visited[j] && dist[j] <= min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u]!= INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    printf("\nVertex\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    printf("\nPath:\n");
    int current = E;

    while (current!= -1) {
        printf("%d ", current);
        current = prev[current];
    }
}

int main() {
    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    return 0;
}