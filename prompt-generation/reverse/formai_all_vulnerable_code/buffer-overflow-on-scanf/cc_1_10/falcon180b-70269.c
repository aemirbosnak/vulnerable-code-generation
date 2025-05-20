//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 999999

typedef struct {
    int id;
    int pos_x;
    int pos_y;
} Node;

typedef struct {
    int id;
    int node1;
    int node2;
    int weight;
} Edge;

void read_nodes(Node nodes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter node %d position (x,y): ", i+1);
        scanf("%d %d", &nodes[i].pos_x, &nodes[i].pos_y);
    }
}

void read_edges(Edge edges[], int m) {
    for (int i = 0; i < m; i++) {
        printf("Enter edge %d (node1, node2, weight): ", i+1);
        scanf("%d %d %d", &edges[i].node1, &edges[i].node2, &edges[i].weight);
    }
}

void prim(Node nodes[], Edge edges[], int m, int start) {
    int visited[MAX_NODES] = {0};
    int parent[MAX_NODES] = {0};
    int min_distance[MAX_NODES] = {INF};
    int min_index;

    visited[start] = 1;
    min_distance[start] = 0;

    for (int i = 1; i < m; i++) {
        min_index = -1;
        for (int j = 0; j < m; j++) {
            if (!visited[j] && min_distance[j] < min_distance[min_index]) {
                min_index = j;
            }
        }
        visited[min_index] = 1;

        for (int j = 0; j < m; j++) {
            if (!visited[j] && edges[min_index].weight < min_distance[j]) {
                parent[j] = min_index;
                min_distance[j] = edges[min_index].weight;
            }
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < m; i++) {
        if (parent[i]!= -1) {
            printf("Edge %d (%d,%d) with weight %d\n", i+1, nodes[i].id, nodes[parent[i]].id, edges[i].weight);
        }
    }
}

int main() {
    int n, m;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    Node nodes[MAX_NODES];
    read_nodes(nodes, n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    Edge edges[MAX_EDGES];
    read_edges(edges, m);

    prim(nodes, edges, m, 0);

    return 0;
}