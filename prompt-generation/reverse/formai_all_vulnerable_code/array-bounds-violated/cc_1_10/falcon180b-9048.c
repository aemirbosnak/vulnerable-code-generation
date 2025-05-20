//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define INF 9999

int n; // number of nodes
int m; // number of edges
int graph[MAX_NODES][MAX_NODES]; // adjacency matrix
int parent[MAX_NODES]; // parent node in minimum spanning tree
int visited[MAX_NODES]; // visited nodes

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }
}

int find_parent(int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find_parent(parent[i]);
}

void merge(int i, int j) {
    int root_i = find_parent(i);
    int root_j = find_parent(j);
    if (root_i!= root_j) {
        parent[root_i] = root_j;
    }
}

void kruskal() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] < INF && find_parent(i)!= find_parent(j)) {
                merge(i, j);
            }
        }
    }
}

void print_mst() {
    for (int i = 0; i < n; i++) {
        printf("%d ", parent[i]);
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    init();
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    kruskal();
    print_mst();
    return 0;
}