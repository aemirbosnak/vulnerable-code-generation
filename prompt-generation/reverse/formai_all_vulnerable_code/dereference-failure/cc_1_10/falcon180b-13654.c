//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 1000
#define MAX_EDGE 10000

typedef struct Edge {
    int from;
    int to;
} Edge;

typedef struct Graph {
    int num_vertex;
    int num_edge;
    Edge *edges;
} Graph;

Graph *graph_create(int num_vertex) {
    Graph *g = malloc(sizeof(Graph));
    g->num_vertex = num_vertex;
    g->num_edge = 0;
    g->edges = malloc(sizeof(Edge) * MAX_EDGE);
    return g;
}

void graph_add_edge(Graph *g, int from, int to) {
    Edge *e = malloc(sizeof(Edge));
    e->from = from;
    e->to = to;
    g->edges[g->num_edge++] = *e;
}

void graph_destroy(Graph *g) {
    free(g->edges);
    free(g);
}

void graph_print(Graph *g) {
    printf("Graph: %d vertices, %d edges\n", g->num_vertex, g->num_edge);
    for (int i = 0; i < g->num_edge; i++) {
        printf("Edge %d: (%d, %d)\n", i, g->edges[i].from, g->edges[i].to);
    }
}

int main() {
    Graph *g = graph_create(5);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 3, 4);
    graph_add_edge(g, 4, 0);
    graph_print(g);
    graph_destroy(g);
    return 0;
}