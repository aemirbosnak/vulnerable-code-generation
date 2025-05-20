//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

typedef struct {
    int num_vertices;
    int num_edges;
    Edge* edges;
} Graph;

void init_graph(Graph* graph) {
    graph->num_vertices = 0;
    graph->num_edges = 0;
    graph->edges = NULL;
}

void add_vertex(Graph* graph, int vertex) {
    graph->num_vertices++;
    graph->edges = realloc(graph->edges, graph->num_vertices * sizeof(Edge));
    graph->edges[vertex].start = vertex;
    graph->edges[vertex].end = -1;
    graph->edges[vertex].weight = 0;
}

void add_edge(Graph* graph, int start, int end, int weight) {
    graph->num_edges++;
    graph->edges = realloc(graph->edges, graph->num_edges * sizeof(Edge));
    graph->edges[graph->num_edges - 1].start = start;
    graph->edges[graph->num_edges - 1].end = end;
    graph->edges[graph->num_edges - 1].weight = weight;
}

void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < graph->num_edges; j++) {
            if (graph->edges[j].start == i) {
                printf("%d ", graph->edges[j].end);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph graph;
    init_graph(&graph);

    add_vertex(&graph, 0);
    add_vertex(&graph, 1);
    add_vertex(&graph, 2);
    add_edge(&graph, 0, 1, 2);
    add_edge(&graph, 0, 2, 3);
    add_edge(&graph, 1, 2, 4);

    print_graph(&graph);

    return 0;
}