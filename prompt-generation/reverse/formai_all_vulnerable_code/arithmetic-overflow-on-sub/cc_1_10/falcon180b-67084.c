//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

struct Edge {
    int node1, node2, weight;
};

struct Node {
    int id;
    int parent;
    int rank;
};

int find_parent(struct Node nodes[], int i) {
    if (nodes[i].parent == i)
        return i;
    else
        return find_parent(nodes, nodes[i].parent);
}

void merge(struct Node nodes[], int i, int j) {
    int parent_i = find_parent(nodes, i);
    int parent_j = find_parent(nodes, j);

    if (parent_i == parent_j)
        return;

    if (nodes[parent_i].rank > nodes[parent_j].rank) {
        nodes[parent_j].parent = parent_i;
        nodes[parent_i].rank += nodes[parent_j].rank;
    }
    else {
        nodes[parent_i].parent = parent_j;
        nodes[parent_j].rank += nodes[parent_i].rank;
    }
}

void kruskals_algorithm(struct Edge edges[], int n) {
    struct Node nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].parent = i;
        nodes[i].rank = 0;
    }

    int mst_edges = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (edges[i].weight + edges[j].weight < nodes[i].rank + nodes[j].rank) {
                merge(nodes, i, j);
                mst_edges++;
            }
        }
    }

    printf("Minimum Spanning Tree: ");
    for (int i = 0; i < n; i++) {
        if (nodes[i].parent!= i)
            printf("%d - %d (%d)\n", i, nodes[i].parent, edges[i].weight);
    }

    printf("\nTotal number of edges in MST: %d\n", mst_edges);
}

int main() {
    int n, m;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    struct Edge edges[m];

    printf("Enter the edges (node1 node2 weight):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].node1, &edges[i].node2, &edges[i].weight);
    }

    kruskals_algorithm(edges, n);

    return 0;
}