//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 150

typedef struct {
    int vertex;
    int weight;
    struct vertex *next;
} vertex;

typedef struct {
    int num_vertices;
    int num_edges;
    vertex *vertices[MAX_VERTICES];
} graph;

graph *create_graph(int num_vertices) {
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->num_edges = 0;
    for (int i = 0; i < num_vertices; i++) {
        g->vertices[i] = NULL;
    }
    return g;
}

void add_edge(graph *g, int from, int to, int weight) {
    vertex *v1 = g->vertices[from];
    vertex *v2 = g->vertices[to];
    if (v1 == NULL) {
        v1 = (vertex *)malloc(sizeof(vertex));
        v1->vertex = from;
        v1->weight = weight;
        v1->next = NULL;
        g->vertices[from] = v1;
    } else {
        v1->weight = weight;
    }
    if (v2 == NULL) {
        v2 = (vertex *)malloc(sizeof(vertex));
        v2->vertex = to;
        v2->weight = weight;
        v2->next = NULL;
        g->vertices[to] = v2;
    } else {
        v2->weight = weight;
    }
    g->num_edges++;
}

void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        vertex *v = g->vertices[i];
        printf("%d: ", i);
        while (v!= NULL) {
            printf("(%d, %d) ", v->vertex, v->weight);
            v = v->next;
        }
        printf("\n");
    }
}

int main() {
    graph *g = create_graph(5);
    add_edge(g, 0, 1, 5);
    add_edge(g, 0, 2, 2);
    add_edge(g, 1, 2, 4);
    add_edge(g, 1, 3, 3);
    add_edge(g, 2, 3, 1);
    add_edge(g, 2, 4, 2);
    print_graph(g);
    return 0;
}