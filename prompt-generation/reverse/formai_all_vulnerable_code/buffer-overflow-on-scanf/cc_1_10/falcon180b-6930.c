//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000

// Function to initialize the graph
void init_graph(int vertices, int edges[], int colors[]) {
    for (int i = 0; i < vertices; i++) {
        colors[i] = -1;
    }
}

// Function to check if a color is valid for a vertex
int is_valid_color(int vertex, int color, int colors[]) {
    for (int i = 0; i < vertex; i++) {
        if (colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Function to color a vertex and update the colors of its neighbors
int color_vertex(int vertex, int color, int colors[]) {
    colors[vertex] = color;
    for (int i = 0; i < vertex; i++) {
        if (colors[i] == -1) {
            return 0;
        }
    }
    return 1;
}

// Function to print the graph
void print_graph(int vertices, int edges[], int colors[]) {
    for (int i = 0; i < vertices; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

// Function to generate a random graph
void generate_graph(int vertices, int edges[], int colors[]) {
    srand(time(NULL));
    for (int i = 0; i < vertices; i++) {
        colors[i] = rand() % 6;
    }
    for (int i = 0; i < edges; i++) {
        int vertex1 = rand() % vertices;
        int vertex2 = rand() % vertices;
        while (!is_valid_color(vertex1, colors[vertex2], colors)) {
            vertex2 = rand() % vertices;
        }
        edges[i] = vertex1 * vertices + vertex2;
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int colors[MAX_VERTICES];
    init_graph(vertices, edges, colors);

    generate_graph(vertices, edges, colors);

    printf("Initial graph:\n");
    print_graph(vertices, edges, colors);

    int start_vertex = 0;
    int num_colors = 0;

    while (num_colors < vertices) {
        int vertex = start_vertex % vertices;
        while (colors[vertex]!= -1) {
            vertex = (vertex + 1) % vertices;
        }
        int color = (start_vertex + 1) % 6;
        if (color_vertex(vertex, color, colors)) {
            num_colors++;
            start_vertex++;
        } else {
            start_vertex = (start_vertex + 1) % vertices;
        }
    }

    printf("Colored graph:\n");
    print_graph(vertices, edges, colors);

    return 0;
}