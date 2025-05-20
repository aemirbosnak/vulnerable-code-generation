//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4
#define E 6

int dist[V][V];
int parent[V][V];

void dijkstra(int spt, int dest) {
    int i, j, u, v;
    for (i = 0; i < V; i++) {
        dist[spt][i] = 0;
        parent[spt][i] = -1;
    }
    dist[spt][spt] = 0;

    for (i = 1; i < V; i++) {
        u = -1;
        for (j = 0; j < V; j++) {
            if (dist[spt][j]!= INF && (u == -1 || dist[spt][u] > dist[spt][j])) {
                u = j;
            }
        }

        if (u!= -1) {
            v = -1;
            for (j = 0; j < V; j++) {
                if (dist[spt][j] > dist[spt][u] + dist[u][j]) {
                    dist[spt][j] = dist[spt][u] + dist[u][j];
                    parent[spt][j] = u;
                }
            }
        }
    }

    printf("\nVertex\t Distance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[spt][i]);
    }

    printf("\nPath: ");
    if (dist[spt][dest] == INF) {
        printf("No path found.\n");
    } else {
        int k = dest;
        while (k!= -1) {
            printf("%d ", k);
            k = parent[spt][k];
        }
        printf("\n");
    }
}

void addedge(int graph[V][V], int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

int main() {
    int graph[V][V] = {{0, 4, INF, 8},
                     {INF, 0, 8, 2},
                     {INF, INF, 0, 1},
                     {INF, INF, INF, 0}};

    int source, destination;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    dijkstra(source, destination);

    return 0;
}