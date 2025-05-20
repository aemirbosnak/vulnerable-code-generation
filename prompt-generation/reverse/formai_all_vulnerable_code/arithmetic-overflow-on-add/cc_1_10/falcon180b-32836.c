//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int id;
    int x;
    int y;
} Node;

typedef struct {
    int from;
    int to;
    int cost;
} Edge;

int num_nodes, num_edges;
Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];

void add_edge(int from, int to, int cost) {
    edges[num_edges].from = from;
    edges[num_edges].to = to;
    edges[num_edges].cost = cost;
    num_edges++;
}

void kruskal() {
    int parent[MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        parent[i] = i;
    }

    int num_components = num_nodes;

    for (int i = 0; i < num_edges; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        int cost = edges[i].cost;

        int root1 = find_parent(parent, from);
        int root2 = find_parent(parent, to);

        if (root1!= root2) {
            parent[root1] = root2;
            num_components--;
        }
    }

    printf("Number of components: %d\n", num_components);
}

int find_parent(int parent[], int node) {
    if (parent[node]!= node) {
        parent[node] = find_parent(parent, parent[node]);
    }
    return parent[node];
}

int main() {
    int i, j;
    scanf("%d", &num_nodes);

    for (i = 0; i < num_nodes; i++) {
        scanf("%d %d", &nodes[i].id, &nodes[i].x);
        nodes[i].y = i;
    }

    scanf("%d", &num_edges);

    for (i = 0; i < num_edges; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        add_edge(from, to, cost);
    }

    kruskal();

    return 0;
}