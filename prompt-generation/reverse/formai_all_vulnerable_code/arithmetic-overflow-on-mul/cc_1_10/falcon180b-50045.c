//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_VERTEX 100
#define MAX_EDGE 200
#define INF 99999999

typedef struct {
    int v;
    int w;
    int cost;
} Edge;

int dist[MAX_VERTEX];
int prev[MAX_VERTEX];
int visited[MAX_VERTEX];

void init(int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        visited[i] = 0;
    }
}

void dijkstra(int n, int start, Edge edges[]) {
    init(n);
    dist[start] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < dist[u]) {
                u = j;
            }
        }

        visited[u] = 1;

        for (int j = 0; j < n; j++) {
            Edge e = edges[u * n + j];
            if (e.cost > 0 &&!visited[j]) {
                int newDist = dist[u] + e.cost;
                if (newDist < dist[j]) {
                    dist[j] = newDist;
                    prev[j] = u;
                }
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge edges[n * n];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[u * n + v] = (Edge) {v, u, w};
        edges[v * n + u] = (Edge) {u, v, w};
    }

    int start;
    scanf("%d", &start);

    dijkstra(n, start, edges);

    for (int i = 0; i < n; i++) {
        if (i!= start) {
            printf("%d -> %d (%d)\n", start, i, dist[i]);
        }
    }

    return 0;
}