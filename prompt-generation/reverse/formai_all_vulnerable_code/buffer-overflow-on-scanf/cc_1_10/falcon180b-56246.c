//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

void init_graph(int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

void add_edge(int vertex1, int vertex2) {
    adj_matrix[vertex1][vertex2] = 1;
    adj_matrix[vertex2][vertex1] = 1;
}

int *color_graph(int num_vertices) {
    int *colors = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++) {
        colors[i] = -1;
    }
    int num_colors = 0;
    for (int i = 0; i < num_vertices; i++) {
        if (colors[i] == -1) {
            colors[i] = num_colors;
            num_colors++;
        }
    }
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (adj_matrix[i][j] == 1 && colors[i]!= -1 && colors[j] == -1) {
                colors[j] = colors[i];
            }
        }
    }
    return colors;
}

int main(int argc, char *argv[]) {
    int num_vertices, num_edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    init_graph(num_vertices);
    for (int i = 0; i < num_edges; i++) {
        int vertex1, vertex2;
        printf("Enter the vertices for edge %d: ", i+1);
        scanf("%d %d", &vertex1, &vertex2);
        add_edge(vertex1, vertex2);
    }
    int *colors = color_graph(num_vertices);
    printf("Vertex\tColor\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d\t%d\n", i, colors[i]);
    }
    return 0;
}