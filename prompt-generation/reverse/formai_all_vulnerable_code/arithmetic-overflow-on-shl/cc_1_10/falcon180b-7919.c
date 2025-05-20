//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_COMPONENTS 100
#define MAX_EDGES 200
#define MAX_NODES 200

typedef struct {
    char *name;
    int value;
    int num_edges;
    int *edges;
} Component;

typedef struct {
    int num_nodes;
    int *nodes;
} Graph;

void add_edge(Graph *graph, int node1, int node2) {
    graph->nodes[node1] |= (1 << node2);
    graph->nodes[node2] |= (1 << node1);
}

void dfs(Graph *graph, int node, int *visited) {
    visited[node] = TRUE;
    for (int i = 0; i < graph->num_nodes; i++) {
        if ((graph->nodes[node] & (1 << i)) &&!visited[i]) {
            dfs(graph, i, visited);
        }
    }
}

int count_components(Graph *graph, int *visited) {
    int num_components = 0;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited);
            num_components++;
        }
    }
    return num_components;
}

int main() {
    int num_nodes, num_edges, num_components;
    scanf("%d %d", &num_nodes, &num_edges);

    Graph graph;
    graph.num_nodes = num_nodes;
    graph.nodes = (int *)malloc(num_nodes * sizeof(int));
    for (int i = 0; i < num_nodes; i++) {
        graph.nodes[i] = 0;
    }

    int *edges = (int *)malloc(num_edges * sizeof(int));
    for (int i = 0; i < num_edges; i++) {
        scanf("%d %d", &edges[2*i], &edges[2*i+1]);
        add_edge(&graph, edges[2*i], edges[2*i+1]);
    }

    int *visited = (int *)malloc(num_nodes * sizeof(int));
    memset(visited, 0, num_nodes * sizeof(int));
    num_components = count_components(&graph, visited);

    printf("Number of components: %d\n", num_components);

    free(graph.nodes);
    free(edges);
    free(visited);

    return 0;
}