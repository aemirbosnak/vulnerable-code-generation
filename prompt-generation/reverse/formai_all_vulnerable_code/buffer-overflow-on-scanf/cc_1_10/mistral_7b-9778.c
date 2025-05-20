//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100

// Function to check if the vertex 'v' is already included in included[]
int is_visited(int *included, int v) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (i == v)
            return included[v];
    }
    return 0;
}

// Recursive function for Depth First Traversal
void dfs(int graph[MAX_NODES][MAX_NODES], int *included, int source, int visited[]) {
    visited[source] = 1;
    printf("%d ", source);

    for (int i = 0; i < MAX_NODES; i++) {
        if (graph[source][i] && !visited[i] && !is_visited(included, i)) {
            included[i] = 1;
            dfs(graph, included, i, visited);
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES], n, m, source;
    int *included = malloc(MAX_NODES * sizeof(int));
    int *visited = calloc(MAX_NODES, sizeof(int));

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("\nEnter edges (u, v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("\nEnter source node: ");
    scanf("%d", &source);

    printf("\nConnected Component: ");
    dfs(graph, included, source, visited);
    printf("\n");

    free(included);
    free(visited);

    return 0;
}