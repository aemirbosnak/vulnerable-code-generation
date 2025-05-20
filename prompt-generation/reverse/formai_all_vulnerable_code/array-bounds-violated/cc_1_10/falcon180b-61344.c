//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 999999

typedef struct {
    int to;
    int cost;
    int next;
} Edge;

Edge graph[MAX_EDGES];
int num_edges = 0;
int num_nodes = 0;
int dist[MAX_NODES];
int prev[MAX_NODES];

void add_edge(int from, int to, int cost) {
    Edge* e = &graph[num_edges];
    e->to = to;
    e->cost = cost;
    e->next = prev[from];
    prev[from] = num_edges++;
}

void dijkstra(int start) {
    int i, u, v;
    for (i = 0; i < num_nodes; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[start] = 0;
    int unvisited_nodes = num_nodes - 1;

    while (unvisited_nodes > 0) {
        int min_dist = INF;
        int u = -1;
        for (i = 0; i < num_nodes; i++) {
            if (dist[i] < min_dist && prev[i]!= -1) {
                min_dist = dist[i];
                u = i;
            }
        }
        unvisited_nodes--;

        for (v = 0; v < num_nodes; v++) {
            Edge* e = &graph[prev[u]];
            while (e!= NULL) {
                if (e->to == v && dist[u] + e->cost < dist[v]) {
                    dist[v] = dist[u] + e->cost;
                    prev[v] = u;
                }
                e = e->next;
            }
        }
    }
}

int main() {
    int i, n, m, u, v, w;
    scanf("%d %d", &n, &m);
    num_nodes = n;

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dijkstra(start);

    printf("Shortest path from %d to %d: %d\n", start, end, dist[end]);

    return 0;
}