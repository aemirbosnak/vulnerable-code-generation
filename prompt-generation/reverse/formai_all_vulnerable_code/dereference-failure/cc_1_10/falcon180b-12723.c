//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 1e9

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int v;
    int dist;
} Vertex;

void dijkstra(int start, int end, Edge edges[], int num_edges, Vertex dist[], int num_vertices) {
    int i, j;
    for (i = 0; i < num_vertices; i++) {
        dist[i].dist = INF;
        dist[i].v = -1;
    }
    dist[start].dist = 0;
    for (i = 0; i < num_edges; i++) {
        for (j = 0; j < num_vertices; j++) {
            if (edges[i].u == j && edges[i].v!= -1) {
                if (dist[j].dist!= INF && dist[j].dist + edges[i].w < dist[edges[i].v].dist) {
                    dist[edges[i].v].dist = dist[j].dist + edges[i].w;
                    dist[edges[i].v].v = j;
                }
            }
        }
    }
    printf("Shortest path from %d to %d: ", start, end);
    j = end;
    while (j!= -1) {
        printf("%d ", j);
        j = dist[j].v;
    }
    printf("\n");
}

int main() {
    int num_vertices, num_edges;
    scanf("%d %d", &num_vertices, &num_edges);
    Edge edges[MAX_EDGE];
    Vertex dist[MAX_VERTEX];
    int i, u, v, w;
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }
    int start, end;
    scanf("%d %d", &start, &end);
    dijkstra(start, end, edges, num_edges, dist, num_vertices);
    return 0;
}