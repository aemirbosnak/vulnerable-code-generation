//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_EDGES 100000
#define INF 1000000

typedef struct {
    int u;
    int v;
    int w;
} edge;

typedef struct {
    int v;
    int parent;
} node;

int n, m;
int start, end;
edge edges[MAX_EDGES];
node nodes[MAX_NODES];

void init() {
    memset(nodes, -1, sizeof(nodes));
}

int find(int x) {
    if (nodes[x].parent!= -1) {
        nodes[x].parent = find(nodes[x].parent);
    }
    return nodes[x].parent;
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px!= py) {
        nodes[px].parent = py;
    }
}

void kruskal() {
    int count = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int pu = find(u);
        int pv = find(v);
        if (pu!= pv) {
            merge(pu, pv);
            if (count < n - 1) {
                ans += edges[i].w;
                count++;
            }
        }
    }
    printf("Minimum Spanning Tree: %d\n", ans);
}

int main() {
    scanf("%d %d", &n, &m);
    init();
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (edge) {u, v, w};
    }
    scanf("%d %d", &start, &end);
    kruskal();
    return 0;
}