//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 100
#define MAX_EDGE 1000
#define INF 999999

typedef struct Edge {
    int u, v, w;
} Edge;

typedef struct Graph {
    int n, m;
    Edge edges[MAX_EDGE];
} Graph;

Graph* createGraph(int n) {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->n = n;
    g->m = 0;
    return g;
}

void addEdge(Graph* g, int u, int v, int w) {
    Edge e = {u, v, w};
    g->edges[g->m++] = e;
}

void dijkstra(Graph* g, int start, int end) {
    int dist[MAX_VERTEX];
    int visited[MAX_VERTEX];
    int n = g->n;

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1, min_dist = INF;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        visited[u] = 1;

        for (int j = 0; j < n; j++) {
            int v = g->edges[u * n + j].v;
            int w = g->edges[u * n + j].w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    printf("The shortest distance from %d to %d is %d\n", start, end, dist[end]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* g = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(g, u, v, w);
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dijkstra(g, start, end);

    return 0;
}