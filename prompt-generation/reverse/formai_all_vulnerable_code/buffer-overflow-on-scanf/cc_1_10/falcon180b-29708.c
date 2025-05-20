//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 500
#define MAX_WEIGHT 1000
#define INF 1000000

int num_nodes, num_edges;
int graph[MAX_NODES][MAX_NODES];
int weight[MAX_EDGES];
int parent[MAX_NODES];

void init() {
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            graph[i][j] = INF;
        }
    }
}

void add_edge(int u, int v, int w) {
    graph[u][v] = w;
    graph[v][u] = w;
}

void kruskal() {
    int count = 0;
    for (int i = 0; i < num_nodes; i++) {
        parent[i] = i;
    }

    int e = 0;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            if (graph[i][j] < weight[e]) {
                weight[e] = graph[i][j];
                parent[i] = j;
            }
        }
        e++;
    }

    for (int i = 0; i < num_nodes; i++) {
        for (int j = i + 1; j < num_nodes; j++) {
            if (graph[i][j] == weight[e - 1]) {
                printf("%d - %d : %d\n", i, j, weight[e - 1]);
                count++;
            }
        }
    }

    printf("\nMinimum Spanning Tree has %d edges\n", count);
}

int main() {
    int i, j, u, v, w;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &num_nodes, &num_edges);

    init();

    printf("Enter the edges with their weights:\n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }

    kruskal();

    return 0;
}