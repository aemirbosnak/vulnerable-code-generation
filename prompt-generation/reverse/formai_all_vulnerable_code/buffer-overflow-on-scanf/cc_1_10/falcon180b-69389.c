//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF INT_MAX

typedef struct {
    int u, v;
    int c;
} Edge;

int n, m;
Edge edges[MAX_EDGES];
int color[MAX_NODES + 1];
int parent[MAX_NODES + 1];

void init() {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x]!= x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void kruskal() {
    int count = 0;
    int i = 0;
    while (count < n - 1) {
        int min = INF;
        int u, v;
        for (int j = i; j < m; j++) {
            if (edges[j].c < min) {
                min = edges[j].c;
                u = edges[j].u;
                v = edges[j].v;
            }
        }
        if (find(u)!= find(v)) {
            parent[find(u)] = find(v);
            count++;
        }
        i++;
    }
}

int main() {
    srand(time(NULL));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        edges[i] = (Edge) {u, v, c};
    }
    init();
    kruskal();
    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < m; i++) {
        if (find(edges[i].u)!= find(edges[i].v)) {
            printf("%d - %d (%d)\n", edges[i].u, edges[i].v, edges[i].c);
        }
    }
    return 0;
}