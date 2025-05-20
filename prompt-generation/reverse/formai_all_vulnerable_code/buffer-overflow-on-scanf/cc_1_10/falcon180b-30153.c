//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VERTS 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGES];
int n, m, start;
int dist[MAX_VERTS];
int visited[MAX_VERTS];

void dijkstra(int start_vertex) {
    int i, u, v, min_dist;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start_vertex] = 0;

    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] <= min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int j = 0; j < n; j++) {
            v = (u * n + j) % n;

            if (!visited[v] && edges[start_vertex * n + u].w!= INF &&
                edges[start_vertex * n + u].w + edges[(u * n + j) % n].w < dist[v]) {
                dist[v] = edges[start_vertex * n + u].w + edges[(u * n + j) % n].w;
            }
        }
    }
}

int main() {
    int i, j, u, v, w;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge){u, v, w};
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Vertex\t Distance from Source\n");

    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    return 0;
}