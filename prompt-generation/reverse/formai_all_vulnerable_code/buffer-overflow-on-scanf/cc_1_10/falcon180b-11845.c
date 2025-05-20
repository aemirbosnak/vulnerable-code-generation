//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NO_PARENT -1
#define INF INT_MAX

typedef struct {
    int distance;
    int parent;
} dist_t;

void dijkstra(int graph[10][10], int src, int dest) {
    int n = 10;
    int visited[10] = {0};
    int path[10] = {0};
    int u, v, k;
    dist_t dist[10];

    for (u = 0; u < n; u++) {
        dist[u].distance = INF;
        dist[u].parent = NO_PARENT;
    }

    dist[src].distance = 0;

    for (k = 0; k < n - 1; k++) {
        int min_dist = INF;
        int u = -1;

        for (u = 0; u < n; u++) {
            if (!visited[u] && dist[u].distance <= min_dist) {
                min_dist = dist[u].distance;
                v = u;
            }
        }

        visited[v] = 1;

        for (u = 0; u < n; u++) {
            if (!visited[u] && graph[v][u] && dist[v].distance!= INF && dist[v].distance + graph[v][u] < dist[u].distance) {
                dist[u].distance = dist[v].distance + graph[v][u];
                dist[u].parent = v;
            }
        }
    }

    printf("Vertex\tDistance from Source\tPath\n");
    printf("--------------------\t--------------------\t--------------------\n");

    for (u = 0; u < n; u++) {
        if (dist[u].distance!= INF) {
            printf("%d\t\t%d\t\t", u, dist[u].distance);

            v = dist[u].parent;

            while (v!= NO_PARENT) {
                path[k++] = v;
                v = dist[v].parent;
            }

            printf("%d\n", path[--k]);
        }
    }
}

int main() {
    int graph[10][10] = {
        {0, 2, 0, 6, 0},
        {0, 0, 1, 2, 0},
        {0, 4, 0, 0, 1},
        {0, 0, 0, 0, 2},
        {INF, INF, INF, INF, 0}
    };

    int src, dest;

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    printf("Enter the destination vertex: ");
    scanf("%d", &dest);

    dijkstra(graph, src, dest);

    return 0;
}