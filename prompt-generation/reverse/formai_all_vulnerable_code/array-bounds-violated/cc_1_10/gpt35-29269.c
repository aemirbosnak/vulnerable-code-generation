//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 400

struct Edge {
    int source;
    int destination;
};

int num_vertices, num_edges;
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int vertex_colors[MAX_VERTICES];

void init_adjacency_matrix() {
    memset(adjacency_matrix, 0, sizeof(adjacency_matrix));
}

void add_edge(int source, int destination) {
    adjacency_matrix[source][destination] = 1;
    adjacency_matrix[destination][source] = 1;
}

void read_graph() {
    scanf("%d %d", &num_vertices, &num_edges);
    init_adjacency_matrix();
    for (int i=0; i<num_edges; i++) {
        int source, dest;
        scanf("%d %d", &source, &dest);
        add_edge(source, dest);
    }
}

int is_safe(int vertex, int color) {
    for (int i=0; i<num_vertices; i++) {
        if (adjacency_matrix[vertex][i] && vertex_colors[i] == color)
            return 0;
    }
    return 1;
}

int graph_coloring(int vertex) {
    if (vertex == num_vertices)
        return 1;
    for (int i=1; i<=num_vertices; i++) {
        if (is_safe(vertex, i)) {
            vertex_colors[vertex] = i;
            if (graph_coloring(vertex+1))
                return 1;
            vertex_colors[vertex] = 0;
        }
    }
    return 0;
}

void print_colors() {
    for (int i=0; i<num_vertices; i++)
        printf("Vertex %d is colored with %d\n", i, vertex_colors[i]);
}

int main() {
    read_graph();
    if (graph_coloring(0))
        print_colors();
    else
        printf("The graph cannot be colored with %d or fewer colors.\n", num_vertices);
    return 0;
}