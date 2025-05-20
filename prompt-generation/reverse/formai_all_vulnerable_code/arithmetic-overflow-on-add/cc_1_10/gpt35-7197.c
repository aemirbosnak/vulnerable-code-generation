//FormAI DATASET v1.0 Category: Graph representation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    Edge* edges;
    int num_edges;
} Vertex;

typedef struct {
    Vertex* vertices;
    int num_vertices;
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = calloc(1, sizeof(Graph));
    graph->num_vertices = num_vertices;
    graph->vertices = calloc(num_vertices, sizeof(Vertex));
    return graph;
}

void add_edge(Graph* graph, int from, int to, int weight) {
    Edge* edge = malloc(sizeof(Edge));
    edge->vertex = to;
    edge->weight = weight;
    graph->vertices[from].edges = realloc(graph->vertices[from].edges, (graph->vertices[from].num_edges + 1) * sizeof(Edge));
    graph->vertices[from].edges[graph->vertices[from].num_edges] = *edge;
    graph->vertices[from].num_edges++;
}

void print_edges(Graph* graph, int vertex) {
    Vertex v = graph->vertices[vertex];
    printf("Edges of Vertex %d:\n", vertex);
    for(int i = 0; i < v.num_edges; i++) {
        printf("%d => %d (Weight: %d)\n", vertex, v.edges[i].vertex, v.edges[i].weight);
    }
}

void print_graph(Graph* graph) {
    printf("===============\n");
    printf("=== GRAPH =====\n");
    printf("===============\n");
    for(int i = 0; i < graph->num_vertices; i++) {
        print_edges(graph, i);
    }
}

int main() {
    int num_vertices = 5;
    Graph* graph = create_graph(num_vertices);
    add_edge(graph, 0, 1, 2);
    add_edge(graph, 1, 2, 3);
    add_edge(graph, 2, 1, 4);
    add_edge(graph, 2, 3, 5);
    add_edge(graph, 3, 0, 6);
    add_edge(graph, 3, 4, 7);
    add_edge(graph, 4, 2, 8);
    print_graph(graph);
    return 0;
}