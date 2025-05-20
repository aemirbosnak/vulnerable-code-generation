//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 100

typedef struct {
    int node1;
    int node2;
} Link;

typedef struct {
    int num_nodes;
    int num_links;
    int **adjacency_matrix;
} Graph;

Graph *create_graph(int num_nodes) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->num_nodes = num_nodes;
    graph->num_links = 0;
    graph->adjacency_matrix = (int **) malloc(num_nodes * sizeof(int *));
    for (int i = 0; i < num_nodes; i++) {
        graph->adjacency_matrix[i] = (int *) malloc(num_nodes * sizeof(int));
        for (int j = 0; j < num_nodes; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    return graph;
}

void add_link(Graph *graph, int node1, int node2) {
    graph->adjacency_matrix[node1][node2] = 1;
    graph->adjacency_matrix[node2][node1] = 1;
    graph->num_links++;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        for (int j = 0; j < graph->num_nodes; j++) {
            if (graph->adjacency_matrix[i][j] == 1) {
                printf("%d -> %d\n", i, j);
            }
        }
    }
}

int main() {
    int num_nodes, num_links;
    scanf("%d %d", &num_nodes, &num_links);

    Graph *graph = create_graph(num_nodes);

    for (int i = 0; i < num_links; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        add_link(graph, node1, node2);
    }

    print_graph(graph);

    return 0;
}