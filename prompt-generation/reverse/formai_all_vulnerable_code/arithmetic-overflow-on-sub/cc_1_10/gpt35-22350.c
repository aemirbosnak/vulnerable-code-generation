//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 10000

typedef struct {
    int v;
    double weight;
} Edge;

typedef struct {
    int val;
    int parent;
    int rank;
} Node;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int N, M;

void initSet(int n) {
    for(int i=0; i<=n; i++) {
        nodes[i].val = i;
        nodes[i].parent = -1;
        nodes[i].rank = 0;
    }
}

int Find(int x) {
    if(nodes[x].parent == -1) return x;
    return nodes[x].parent = Find(nodes[x].parent);
}

void Union(int x, int y) {
    int rx = Find(x), ry = Find(y);
    if(rx == ry) return;
    if(nodes[rx].rank > nodes[ry].rank) nodes[ry].parent = rx;
    else if(nodes[rx].rank < nodes[ry].rank) nodes[rx].parent = ry;
    else {
        nodes[ry].parent = rx;
        nodes[rx].rank++;
    }
}

int cmp(const void *a, const void *b) {
    Edge *e1 = (Edge*)a, *e2 = (Edge*)b;
    return e1->weight > e2->weight;
}

void KruskalMST() {
    qsort(edges, M, sizeof(Edge), cmp);
    int count = 0, i = 0;
    while(count < N-1) {
        Edge e = edges[i++];
        int u = e.v/101, v = e.v%101;
        if(Find(u) != Find(v)) {
            printf("(%d, %d) %.2lf\n", u, v, e.weight);
            Union(u, v);
            count++;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    initSet(N);
    for(int i=0; i<M; i++) {
        int u, v;
        double w;
        scanf("%d %d %lf", &u, &v, &w);
        edges[i].v = u*101 + v;
        edges[i].weight = w;
    }
    KruskalMST();
    return 0;
}