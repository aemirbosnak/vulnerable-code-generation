//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF 0x3f3f3f3f

int n, m;
int edges[MAX_EDGES][3];
int cost[MAX_EDGES];
int parent[MAX_EDGES];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    parent[x] = y;
}

void kruskal() {
    int i, j, u, v, w;
    for (i = 0; i < m; i++) {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        if (find(u)!= find(v)) {
            merge(u, v);
            printf("Edge %d: %d - %d (Cost: %d)\n", i+1, u, v, w);
        }
    }
}

int main() {
    int i, j, u, v, w;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the nodes for edge %d: ", i+1);
        scanf("%d %d", &u, &v);
        printf("Enter the cost for edge %d: ", i+1);
        scanf("%d", &w);
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    kruskal();

    return 0;
}