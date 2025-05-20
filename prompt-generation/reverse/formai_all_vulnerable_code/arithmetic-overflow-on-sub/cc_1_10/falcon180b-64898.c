//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 9999

typedef struct {
    int id;
    int x, y;
} Vertex;

typedef struct {
    int start, end;
    int weight;
} Edge;

int n, m;
Vertex vertices[MAX_VERTEX];
Edge edges[MAX_EDGE];
int distance[MAX_VERTEX];
int parent[MAX_VERTEX];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }
    distance[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = edges[j].start;
            v = edges[j].end;
            if (distance[u]!= INF && distance[u] + edges[j].weight < distance[v]) {
                distance[v] = distance[u] + edges[j].weight;
                parent[v] = u;
            }
        }
    }
}

void print_path(int end) {
    int v = end;
    printf("Path: %d ", v);
    while (v!= -1) {
        v = parent[v];
        printf("%d ", v);
    }
    printf("\n");
}

int main() {
    int i, j, u, v, w;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter vertices (x y):\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &vertices[i].x, &vertices[i].y);
    }
    printf("Enter edges (start end weight):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].start, &edges[i].end, &edges[i].weight);
    }
    int start, end;
    printf("Enter start vertex: ");
    scanf("%d", &start);
    printf("Enter end vertex: ");
    scanf("%d", &end);
    dijkstra(start);
    printf("Shortest path from %d to %d:\n", start, end);
    print_path(end);
    return 0;
}