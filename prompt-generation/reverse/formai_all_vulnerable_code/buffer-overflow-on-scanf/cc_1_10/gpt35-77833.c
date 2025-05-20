//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int u, v;
    double weight;
} Edge;

int N, M;
Edge edges[MAX_EDGES];
int parent[MAX_NODES + 1];
double MST_weight = 0;

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

int merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    parent[u] = v;
    return 1;
}

int cmp(const void *a, const void *b) {
    Edge *ia = (Edge *) a;
    Edge *ib = (Edge *) b;
    return (int) (ia->weight - ib->weight);
}

void kruskals() {
    int e = 0, i = 0;
    qsort(edges, M, sizeof(Edge), cmp);
    for (i = 0; i <= N; i++) parent[i] = i;
    for (i = 0; i < M; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        double weight = edges[i].weight;

        if (merge(u, v)) {
            MST_weight += weight;
            e++;
            if (e == N - 1) break;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
        scanf("%d %d %lf", &edges[i].u, &edges[i].v, &edges[i].weight);

    kruskals();

    printf("Minimum spanning tree weight: %lf\n", MST_weight);

    return 0;
}