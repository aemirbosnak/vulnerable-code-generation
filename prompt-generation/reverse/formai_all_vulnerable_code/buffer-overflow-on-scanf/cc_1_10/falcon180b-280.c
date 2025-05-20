//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999999

typedef struct {
    int node;
    int weight;
    int next;
} Edge;

Edge edges[MAX_EDGES];
int n, m, parent[MAX_NODES];
bool marked[MAX_NODES];

void init() {
    memset(parent, -1, sizeof(parent));
    memset(marked, false, sizeof(marked));
}

int findParent(int i) {
    if (parent[i] == -1)
        return i;
    else
        return findParent(parent[i]);
}

void unionParent(int i, int j) {
    int pi = findParent(i);
    int pj = findParent(j);
    if (pi!= pj) {
        if (marked[pi]) {
            parent[pi] = pj;
            marked[pi] = false;
        } else {
            parent[pj] = pi;
            marked[pj] = false;
        }
    }
}

void kruskalsAlgorithm() {
    int count = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++) {
        int u = edges[i].node;
        int v = edges[i].next;
        int w = edges[i].weight;

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu!= pv) {
            count++;
            unionParent(pu, pv);
        }
    }

    printf("Minimum Spanning Tree has %d edges\n", count);
}

int main() {
    int i, u, v, w;

    printf("Enter the number of nodes and edges: ");
    scanf("%d%d", &n, &m);

    init();

    printf("Enter the edges with their weights:\n");
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edges[i].node = u;
        edges[i].next = v;
        edges[i].weight = w;
    }

    kruskalsAlgorithm();

    return 0;
}