//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 1000
#define MAX_EDGES 10000

typedef struct {
    int id;
    char name[20];
} Vertex;

typedef struct {
    int from;
    int to;
    int weight;
} Edge;

Vertex *graph;
Edge *edges;
int num_vertices, num_edges;

void initialize() {
    graph = (Vertex*) malloc(MAX_VERTICES * sizeof(Vertex));
    edges = (Edge*) malloc(MAX_EDGES * sizeof(Edge));
    num_vertices = 0;
    num_edges = 0;
}

void add_vertex(int id, char name[20]) {
    graph[num_vertices].id = id;
    strcpy(graph[num_vertices].name, name);
    num_vertices++;
}

void add_edge(int from, int to, int weight) {
    edges[num_edges].from = from;
    edges[num_edges].to = to;
    edges[num_edges].weight = weight;
    num_edges++;
}

void print_graph() {
    printf("Graph:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d: %s\n", graph[i].id, graph[i].name);
    }
    printf("\nEdges:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d (%d)\n", edges[i].from, edges[i].to, edges[i].weight);
    }
}

int main() {
    initialize();

    add_vertex(1, "A");
    add_vertex(2, "B");
    add_vertex(3, "C");
    add_vertex(4, "D");

    add_edge(1, 2, 5);
    add_edge(2, 3, 10);
    add_edge(3, 4, 15);

    print_graph();

    return 0;
}