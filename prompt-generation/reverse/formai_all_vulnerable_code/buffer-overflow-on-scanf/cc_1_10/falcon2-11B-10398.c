//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int num_nodes;
    int num_edges;
    int nodes[MAX_NODES];
    int edges[MAX_EDGES][2];
    int visited[MAX_NODES];
    int num_connected_components;
    int connected_components[MAX_NODES];
} Graph;

int dfs(Graph *g, int start, int visited[]) {
    int num_connected_components = 0;
    int num_nodes = g->num_nodes;
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = 0;
    }

    visited[start] = 1;
    num_connected_components++;

    for (int i = 0; i < num_nodes; i++) {
        if (visited[i] == 0) {
            num_connected_components = dfs(g, i, visited);
        }
    }

    return num_connected_components;
}

void print_graph(Graph *g) {
    int num_nodes = g->num_nodes;
    printf("Nodes: ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", g->nodes[i]);
    }
    printf("\n");

    printf("Edges: ");
    for (int i = 0; i < g->num_edges; i++) {
        printf("%d %d ", g->edges[i][0], g->edges[i][1]);
    }
    printf("\n");
}

void print_connected_components(Graph *g) {
    int num_connected_components = g->num_connected_components;
    printf("Connected Components: ");
    for (int i = 0; i < num_connected_components; i++) {
        printf("%d ", g->connected_components[i]);
    }
    printf("\n");
}

int main() {
    Graph g;
    g.num_nodes = 0;
    g.num_edges = 0;
    g.visited[0] = 1;

    printf("Enter the number of nodes: ");
    scanf("%d", &g.num_nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &g.num_edges);

    printf("Enter the edges: ");
    for (int i = 0; i < g.num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g.edges[i][0] = u;
        g.edges[i][1] = v;
    }

    int start = 0;
    int end = g.num_nodes - 1;

    printf("Enter start node: ");
    scanf("%d", &start);

    printf("Enter end node: ");
    scanf("%d", &end);

    if (dfs(&g, start, g.visited)!= g.num_connected_components) {
        printf("The graph is not connected.\n");
    } else {
        printf("The graph is connected.\n");
    }

    print_graph(&g);
    print_connected_components(&g);

    return 0;
}