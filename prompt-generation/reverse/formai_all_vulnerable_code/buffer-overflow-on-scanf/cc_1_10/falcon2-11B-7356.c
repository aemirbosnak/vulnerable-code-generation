//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    int vertices;
    int edges;
    Edge *edges_array;
} Graph;

void add_edge(Graph *graph, int v1, int v2, int weight) {
    if (graph->vertices == MAX_VERTICES) {
        fprintf(stderr, "Maximum number of vertices reached\n");
        exit(1);
    }

    if (graph->edges == MAX_EDGES) {
        fprintf(stderr, "Maximum number of edges reached\n");
        exit(1);
    }

    graph->edges_array[graph->edges].vertex = v1;
    graph->edges_array[graph->edges].weight = weight;
    graph->edges++;

    graph->edges_array[graph->edges].vertex = v2;
    graph->edges_array[graph->edges].weight = weight;
    graph->edges++;
}

void print_graph(Graph *graph) {
    if (graph->vertices == 0) {
        fprintf(stderr, "No vertices in the graph\n");
        exit(1);
    }

    int i, j;
    for (i = 0; i < graph->vertices; i++) {
        if (i == 0) {
            fprintf(stdout, "Vertices:\n");
        } else {
            fprintf(stdout, " ");
        }
        fprintf(stdout, "%d\n", i);
    }

    fprintf(stdout, "Edges:\n");
    for (i = 0; i < graph->edges; i++) {
        fprintf(stdout, " %d -> %d : %d\n", graph->edges_array[i].vertex, graph->edges_array[i].weight);
    }
}

int main() {
    Graph graph;
    int n, m;

    fprintf(stdout, "Enter the number of vertices: ");
    scanf("%d", &n);

    graph.vertices = n;
    graph.edges = 0;
    graph.edges_array = malloc(graph.vertices * sizeof(Edge));

    fprintf(stdout, "Enter the number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        fprintf(stdout, "Enter the source vertex, destination vertex, and weight: ");
        int v1, v2, weight;
        scanf("%d%d%d", &v1, &v2, &weight);

        add_edge(&graph, v1, v2, weight);
    }

    print_graph(&graph);

    free(graph.edges_array);

    return 0;
}