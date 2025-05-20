//FormAI DATASET v1.0 Category: Graph representation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// define constants for the maximum number of vertices and edges possible
#define MAX_VERTICES 20
#define MAX_EDGES 25

int vertices[MAX_VERTICES]; // array to store vertices
int edges[MAX_EDGES][2]; // array to store edges

// function to add a vertex to the graph
void add_vertex(int v_index) {
    vertices[v_index] = 1;
}

// function to add an edge to the graph
void add_edge(int e_index, int u, int v) {
    edges[e_index][0] = u;
    edges[e_index][1] = v;
}

// function to display the graph
void display_graph(int num_vertices, int num_edges) {
    printf("Vertices: ");
    for (int i = 0; i < num_vertices; i++) {
        if (vertices[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Edges: ");
    for (int i = 0; i < num_edges; i++) {
        printf("(%d, %d) ", edges[i][0], edges[i][1]);
    }
    printf("\n");
}

int main() {
    int num_vertices, num_edges;
    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &num_vertices);

    if (num_vertices > MAX_VERTICES) {
        printf("Error: Number of vertices cannot exceed %d.\n", MAX_VERTICES);
        exit(1);
    }

    printf("Enter the number of edges in the graph (maximum %d): ", MAX_EDGES);
    scanf("%d", &num_edges);

    if (num_edges > MAX_EDGES) {
        printf("Error: Number of edges cannot exceed %d.\n", MAX_EDGES);
        exit(1);
    }

    printf("Enter the edges of the graph in the format 'u v':\n");

    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // add vertices to the graph
        add_vertex(u);
        add_vertex(v);

        // add edges to the graph
        add_edge(i, u, v);
    }

    // display the graph
    display_graph(num_vertices, num_edges);

    return 0;
}