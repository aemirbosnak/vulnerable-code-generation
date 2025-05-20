//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_VERTEX 10000
#define MAX_EDGE 100000
#define INF 0x3f3f3f3f

typedef struct Edge {
    int u, v, w;
} Edge;

Edge edges[MAX_EDGE];
int nedges;

int n, m, s, t;
int dist[MAX_VERTEX];
int prev[MAX_VERTEX];

void add_edge(int u, int v, int w) {
    edges[nedges] = (Edge) {u, v, w};
    nedges++;
}

void dijkstra(int start) {
    memset(dist, 0x3f, sizeof(dist));
    memset(prev, -1, sizeof(prev));

    dist[start] = 0;
    int q[MAX_VERTEX];
    int front = 0, rear = 0;

    q[rear++] = start;

    while (front < rear) {
        int u = q[front++];

        for (int i = 0; i < nedges; i++) {
            int v = edges[i].v;
            if (dist[u]!= INF && dist[u] + edges[i].w < dist[v]) {
                dist[v] = dist[u] + edges[i].w;
                prev[v] = u;
                if (prev[v] == -1 || dist[v] < dist[q[0]]) {
                    q[rear++] = v;
                    if (rear == MAX_VERTEX) rear = 0;
                }
            }
        }
    }
}

void print_path(int v) {
    if (v == -1) return;
    print_path(prev[v]);
    printf("%d ", v);
}

int main() {
    scanf("%d%d", &n, &m);
    s = 0;
    t = n - 1;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    dijkstra(s);

    printf("Shortest path: ");
    print_path(t);
    printf("\nDistance: %d\n", dist[t]);

    return 0;
}