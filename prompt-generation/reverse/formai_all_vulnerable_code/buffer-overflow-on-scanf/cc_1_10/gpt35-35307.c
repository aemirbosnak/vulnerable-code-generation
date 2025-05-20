//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct Edge {
    int u;
    int v;
    int weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];
int num_vertices = 0;
int num_edges = 0;

void make_set(int x) {
    parent[x] = x;
    rank[x] = 0;
}

int find_set(int x) {
    if (parent[x] != x) {
        parent[x] = find_set(parent[x]);
    }
    return parent[x];
}

void union_set(int x, int y) {
    int root_x = find_set(x);
    int root_y = find_set(y);
    if (root_x != root_y) {
        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else {
            parent[root_x] = root_y;
            rank[root_y]++;
        }
    }
}

int kruskal() {
    int result = 0;
    for (int i = 0; i < num_vertices; i++) {
        make_set(i);
    }
    for (int i = 0; i < num_edges; i++) {
        Edge edge = edges[i];
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;
        if (find_set(u) != find_set(v)) {
            union_set(u, v);
            result += weight;
        }
    }
    return result;
}

int main() {
    scanf("%d %d", &num_vertices, &num_edges);
    for (int i = 0; i < num_edges; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].weight = weight;
    }
    int minimum_cost = kruskal();
    printf("Minimum Cost: %d\n", minimum_cost);
    return 0;
}