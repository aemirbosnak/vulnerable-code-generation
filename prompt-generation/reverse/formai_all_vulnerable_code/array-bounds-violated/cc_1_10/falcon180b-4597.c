//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 100
#define MAX_E 100

typedef struct {
    int v;
    int w;
    int next;
} Edge;

Edge graph[MAX_V][MAX_V];
int dist[MAX_V];
int prev[MAX_V];
int n, m;

void init() {
    int u, v, w;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j].w = INF;
            graph[i][j].next = -1;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v].w = w;
        graph[v][u].w = w;
    }
}

void dijkstra(int s) {
    int u, v;
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            u = s;
            for (int k = 0; k < n; k++) {
                if (dist[k]!= INF && graph[k][j].w!= INF &&
                    graph[k][j].w + dist[k] < dist[j]) {
                    dist[j] = dist[k] + graph[k][j].w;
                    prev[j] = k;
                }
            }
        }
    }
}

void print_path(int v) {
    if (v == -1)
        return;
    print_path(prev[v]);
    printf("%d ", v);
}

int main() {
    init();
    int s, d;

    scanf("%d %d", &s, &d);

    dijkstra(s);

    printf("Shortest Path: ");
    print_path(d);
    printf("\n");

    return 0;
}