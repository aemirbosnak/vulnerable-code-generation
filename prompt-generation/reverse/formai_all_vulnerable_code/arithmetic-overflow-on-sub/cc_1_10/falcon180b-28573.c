//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF INT_MAX

typedef struct {
    int node;
    int weight;
} Edge;

Edge edges[MAX_EDGES];
int n, m;
int dist[MAX_NODES];
int prev[MAX_NODES];

void dijkstra(int start) {
    memset(dist, INF, sizeof(dist));
    memset(prev, -1, sizeof(prev));

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1, min_dist = INF;
        for (int j = 0; j < n; j++) {
            if (dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        dist[u] = INF;

        for (int j = 0; j < m; j++) {
            int v = edges[j].node;
            int w = edges[j].weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }
}

void print_path(int end) {
    if (prev[end] == -1) {
        printf("No path found.\n");
        return;
    }

    printf("Path: ");
    int u = end;
    while (u!= -1) {
        printf("%d ", u);
        u = prev[u];
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i].node = v;
        edges[i].weight = w;
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dijkstra(start);
    print_path(end);

    return 0;
}