//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 1000
#define MAX_EDGE 10000
#define INF 99999999

typedef struct {
    int u, v, w;
} Edge;

Edge graph[MAX_EDGE];
int n, m, sptSet[MAX_VERTEX];

void dijkstra(int start) {
    int dist[MAX_VERTEX];
    int i, j, k, u, v;
    for (i = 0; i < n; i++)
        dist[i] = INF;
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = graph[j].u;
            v = graph[j].v;
            if (dist[u]!= INF && dist[v] > dist[u] + graph[j].w) {
                dist[v] = dist[u] + graph[j].w;
            }
        }
    }
    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int i, j, u, v, w;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges and their weights:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[i].u = u;
        graph[i].v = v;
        graph[i].w = w;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &sptSet[0]);
    dijkstra(sptSet[0]);
    return 0;
}