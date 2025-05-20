//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 100
#define MAX_E 200
#define INF INT_MAX

typedef struct {
    int v, w, next;
} Edge;

Edge edges[MAX_E];
int adj[MAX_V];
int dist[MAX_V];
int visited[MAX_V];
int n, m, start, end;

void add_edge(int u, int v, int w) {
    edges[m].v = v;
    edges[m].w = w;
    edges[m].next = adj[u];
    adj[u] = m++;
}

void dijkstra(int start) {
    int u, v;
    for (u = 0; u < n; u++) {
        dist[u] = INF;
        visited[u] = 0;
    }
    dist[start] = 0;
    int s = start;
    while (s!= -1) {
        int min_dist = INF;
        int next_s = -1;
        for (u = 0; u < n; u++) {
            if (!visited[u] && dist[u] < min_dist) {
                min_dist = dist[u];
                next_s = u;
            }
        }
        visited[next_s] = 1;
        s = next_s;
    }
}

void print_path(int v) {
    if (v == -1)
        return;
    print_path(edges[v].next);
    printf("%d ", v);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
    dijkstra(0);
    printf("Shortest path from node 0 to node %d:\n", end);
    print_path(dist[end]);
    return 0;
}