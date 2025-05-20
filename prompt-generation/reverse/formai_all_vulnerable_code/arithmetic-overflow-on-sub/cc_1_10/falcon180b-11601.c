//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX_VERTS 1000
#define MAX_EDGES 2000

typedef struct {
    int u;
    int v;
    int w;
} Edge;

typedef struct {
    int n;
    int m;
    int **graph;
} Graph;

Graph createGraph(int n) {
    Graph g = {n, 0, NULL};
    g.graph = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g.graph[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            g.graph[i][j] = INT_MAX;
        }
    }
    return g;
}

void addEdge(Graph *g, int u, int v, int w) {
    Edge e = {u, v, w};
    g->graph[u][v] = w;
    g->graph[v][u] = w;
    g->m++;
}

void dijkstra(Graph g, int start) {
    int n = g.n;
    int *dist = (int *)malloc(n * sizeof(int));
    int *prev = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[start] = 0;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        int min_dist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                u = j;
                min_dist = dist[j];
            }
        }
        visited[u] = 1;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                v = j;
                int new_dist = dist[u] + g.graph[u][v];
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    prev[v] = u;
                }
            }
        }
    }
    printf("Vertex\t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    Graph g = createGraph(n);
    int u, v, w;
    printf("Enter the edges (u, v, w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&g, u, v, w);
    }
    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    dijkstra(g, start);
    return 0;
}