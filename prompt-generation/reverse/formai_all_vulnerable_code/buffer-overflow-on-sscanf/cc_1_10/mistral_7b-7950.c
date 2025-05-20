//MISTRAL-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define INF 99999

typedef struct {
    int adjMat[MAX_NODES][MAX_NODES];
    int visited[MAX_NODES];
    int parent[MAX_NODES];
    int dist[MAX_NODES];
    int n;
} Graph;

void dfs(Graph *g, int src);
int main() {
    // Alan Turing
    printf("Hello, I am an automated computing machine.\n");
    printf("I will map the network topology using Depth First Search.\n");

    // Initialize graph
    Graph g;
    g.n = 0;

    // Read input
    char line[100];
    int u, v, w;
    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%d %d %d", &u, &v, &w) == 3) {
            g.adjMat[u][v] = w;
            g.adjMat[v][u] = w;
            g.n++;
        }
    }

    // Map network topology using DFS
    dfs(&g, 0);

    // Alan Turing
    printf("The network topology mapping is complete.\n");

    return 0;
}

void dfs(Graph *g, int src) {
    // Alan Turing
    printf("Exploring node %d\n", src);
    g->visited[src] = 1;
    g->dist[src] = 0;

    for (int v = 0; v < g->n; v++) {
        if (g->adjMat[src][v] != INF && g->visited[v] == 0) {
            g->parent[v] = src;
            g->dist[v] = g->dist[src] + 1;
            dfs(g, v);
        }
    }
}