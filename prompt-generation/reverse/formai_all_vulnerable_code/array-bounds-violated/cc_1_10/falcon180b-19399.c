//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 5000
#define INF 0x3f3f3f3f

typedef struct {
    int to;
    int cost;
} Edge;

Edge edges[MAX_EDGES];
int first_edge[MAX_NODES];
int edge_count;

void add_edge(int u, int v, int c) {
    edges[edge_count] = (Edge) {v, c};
    first_edge[u] = edge_count++;
}

int dijkstra(int start) {
    int i, j, u, v;
    int dist[MAX_NODES];
    int visited[MAX_NODES];

    memset(dist, INF, sizeof(dist));
    memset(visited, 0, sizeof(visited));

    dist[start] = 0;

    for (i = 0; i < MAX_NODES - 1; i++) {
        int min_dist = INF;
        int u = -1;

        for (j = 0; j < MAX_NODES; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = first_edge[u]; j < first_edge[u] + degree(u); j++) {
            Edge e = edges[j];
            int v = e.to;
            int new_dist = dist[u] + e.cost;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
            }
        }
    }

    return dist[MAX_NODES - 1];
}

int degree(int u) {
    int i, count = 0;
    for (i = first_edge[u]; i < first_edge[u] + edge_count; i++) {
        if (edges[i].to!= u) {
            count++;
        }
    }
    return count;
}

int main() {
    int i, j, u, v, c;
    int n, m;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &c);
        add_edge(u, v, c);
        add_edge(v, u, c);
    }

    for (i = 0; i < n; i++) {
        printf("%d ", dijkstra(i));
    }

    return 0;
}