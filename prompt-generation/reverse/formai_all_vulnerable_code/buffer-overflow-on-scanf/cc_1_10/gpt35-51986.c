//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20
#define MAX_EDGES 50

int parent[MAX_NODES];    // parent of each node
int rank[MAX_NODES];      // rank of each node
int edges[MAX_EDGES][3];  // graph edges

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_set(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px == py) {
        return;
    }
    
    if (rank[px] < rank[py]) {
        parent[px] = py;
    } else if (rank[px] > rank[py]) {
        parent[py] = px;
    } else {
        parent[px] = py;
        rank[py]++;
    }
}

void kruskal(int num_nodes, int num_edges) {
    int i, j, k;

    // sort edges by weight
    for (i = 0; i < num_edges; i++) {
        for (j = i + 1; j < num_edges; j++) {
            if (edges[i][2] > edges[j][2]) {
                int temp[3] = { edges[i][0], edges[i][1], edges[i][2] };
                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];
                edges[j][0] = temp[0];
                edges[j][1] = temp[1];
                edges[j][2] = temp[2];
            }
        }
    }

    for (i = 0; i < num_nodes; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mst_weight = 0;
    int mst_count = 0;  // number of edges in MST

    for (i = 0; i < num_edges; i++) {
        // add edge to MST if it does not form a cycle
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (find(u) != find(v)) {
            union_set(u, v);
            mst_weight += w;
            mst_count++;

            if (mst_count == num_nodes - 1) {
                break;
            }
        }
    }

    if (mst_count != num_nodes - 1) {
        printf("No MST found\n");
    } else {
        printf("Minimum Spanning Tree Weight: %d\n", mst_weight);
    }
}

int main() {
    int num_nodes, num_edges;
    int i, j, u, v, w;

    printf("Enter number of nodes and number of edges: ");
    scanf("%d %d", &num_nodes, &num_edges);

    printf("Enter edges as (u v w):\n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
    }

    kruskal(num_nodes, num_edges);

    return 0;
}