//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define INF 9999999

typedef struct {
    int x, y;
} Node;

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX_NODES][MAX_NODES];
int dist[MAX_NODES];
int n, m, s, t;

void dijkstra(int start_node) {
    int i, j, k, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start_node] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                if (edges[j][k].w > 0 && dist[j]!= INF && dist[j] + edges[j][k].w < dist[k]) {
                    dist[k] = dist[j] + edges[j][k].w;
                }
            }
        }
    }
}

void print_solution(int end_node) {
    int u = end_node;
    while (u!= -1) {
        printf("%c", toupper(u + 'A'));
        int v = dist[u] == INF? -1 : u - n;
        u = v;
    }
    printf("\n");
}

int main() {
    int i, j, k, u, v, w;
    char map[10][10];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", map[i]);
        for (j = 0; j < n; j++) {
            if (map[i][j] == 'S') {
                s = i * n + j;
            } else if (map[i][j] == 'T') {
                t = i * n + j;
            }
        }
    }

    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edges[u][v] = (Edge){v, w};
        edges[v][u] = (Edge){u, w};
    }

    dijkstra(s);
    print_solution(t);

    return 0;
}