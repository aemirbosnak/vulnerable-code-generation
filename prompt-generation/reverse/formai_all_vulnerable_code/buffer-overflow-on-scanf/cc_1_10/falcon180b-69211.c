//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 1000000000

int n, m;
int graph[MAX_NODES][MAX_NODES];
int parent[MAX_NODES];
int rank[MAX_NODES];

void initialize() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x]!= x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px!= py) {
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[px] = py;
            if (rank[px] == rank[py]) {
                rank[py]++;
            }
        }
    }
}

void kruskal(int start, int end) {
    int u = start;
    int v = end;
    int w = graph[u][v];
    printf("%d - %d (%d)\n", u, v, w);
    merge(u, v);
}

void printSolution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]!= INF) {
                printf("%d - %d (%d)\n", i, j, graph[i][j]);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    initialize();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]!= INF) {
                kruskal(i, j);
            }
        }
    }

    printSolution();

    return 0;
}