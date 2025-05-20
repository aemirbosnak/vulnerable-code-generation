//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Graph structure
typedef struct {
    int num_vertices;
    int *adjacency_list;
} Graph;

// Graph operations
void init_graph(Graph *g, int n) {
    g->num_vertices = n;
    g->adjacency_list = calloc(n, sizeof(int));
}

void add_edge(Graph *g, int u, int v) {
    g->adjacency_list[u] = (g->adjacency_list[u] << 1) + (v & 1);
}

void print_graph(Graph g) {
    for (int i = 0; i < g.num_vertices; i++) {
        printf("vertex %d: ", i);
        for (int j = 0; j < (1 << g.adjacency_list[i]); j++) {
            if (j & 1) {
                printf("%d ", g.adjacency_list[i] + j);
            }
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    init_graph(&g, 10);

    // Add edges
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 4);
    add_edge(&g, 3, 5);
    add_edge(&g, 4, 6);
    add_edge(&g, 5, 7);
    add_edge(&g, 6, 8);
    add_edge(&g, 7, 9);

    // Print the graph
    print_graph(g);

    return 0;
}