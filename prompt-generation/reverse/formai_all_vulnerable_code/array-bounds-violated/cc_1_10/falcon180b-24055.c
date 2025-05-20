//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 8

int adj[V][V];
int parent[V];

void init() {
    int i, j;
    for (i = 0; i < V; i++) {
        parent[i] = i;
    }
    for (i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

void kruskal() {
    int i, j, u, v, count = 0;
    for (i = 0; i < V; i++) {
        parent[i] = i;
    }
    for (i = 0; i < E; i++) {
        u = find(adj[i][0]);
        v = find(adj[i][1]);
        if (u!= v) {
            count++;
            parent[u] = v;
        }
    }
    printf("Minimum spanning tree has %d edges\n", count);
}

int find(int x) {
    if (parent[x]!= x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

int main() {
    init();
    kruskal();
    return 0;
}