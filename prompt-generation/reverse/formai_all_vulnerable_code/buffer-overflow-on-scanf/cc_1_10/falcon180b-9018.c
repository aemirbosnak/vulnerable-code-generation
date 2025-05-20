//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 99999

typedef struct {
    int u, v;
    int w;
} Edge;

Edge graph[MAX_EDGE];
int dist[MAX_VERTEX];
int n, m;

void dijkstra(int start) {
    int i, u, v;
    memset(dist, INF, sizeof(dist));
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        int min_dist = INF;
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (dist[j] < min_dist && dist[j]!= INF) {
                min_dist = dist[j];
                u = j;
            }
        }
        dist[u] = INF;
        for (int j = 0; j < n; j++) {
            if (graph[u * n + j].w!= INF && dist[u]!= INF && dist[u] + graph[u * n + j].w < dist[j]) {
                dist[j] = dist[u] + graph[u * n + j].w;
            }
        }
    }
}

int main() {
    int i, u, v, w;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (u v w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[i].u = u;
        graph[i].v = v;
        graph[i].w = w;
    }
    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    dijkstra(start);
    printf("Vertex\tDistance from %d\n", start);
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
    return 0;
}