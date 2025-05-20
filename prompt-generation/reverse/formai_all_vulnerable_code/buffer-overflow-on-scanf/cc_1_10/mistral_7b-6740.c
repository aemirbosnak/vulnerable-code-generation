//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} graph;

void create_graph(graph *g, int num_vertices) {
    g->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->vertices[i][j] = 0;
        }
    }
}

void add_edge(graph *g, int src, int dest) {
    g->vertices[src][dest] = 1;
    g->vertices[dest][src] = 1;
}

void print_graph(graph g) {
    printf("Adjacency Matrix Representation of Graph:\n");
    for (int i = 0; i < g.num_vertices; i++) {
        printf("\nVertex %d: ", i);
        for (int j = 0; j < g.num_vertices; j++) {
            printf(" %d", g.vertices[i][j]);
        }
    }
}

int main() {
    graph g;
    int num_vertices, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    create_graph(&g, num_vertices);

    printf("Enter the number of edges and their endpoints:\n");
    for (int i = 0; i < num_vertices; i++) {
        scanf("%d%d", &src, &dest);
        add_edge(&g, src, dest);
    }

    print_graph(g);

    return 0;
}