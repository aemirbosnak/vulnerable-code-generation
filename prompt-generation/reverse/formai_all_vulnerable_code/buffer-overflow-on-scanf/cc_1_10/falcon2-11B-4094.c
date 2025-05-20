//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vertex;
    int color;
} Vertex;

void initialize_colors(Vertex *vertices, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        vertices[i].color = i;
    }
}

void dfs_color(Vertex *vertices, int *colors, int *num_colors, int *visited, int num_vertices, int vertex) {
    int color = -1;
    int i;

    for (i = 0; i < num_vertices; i++) {
        if (!visited[i]) {
            color = i;
            break;
        }
    }

    if (color == -1) {
        return;
    }

    vertices[vertex].color = color;

    visited[color] = 1;

    for (i = 0; i < num_vertices; i++) {
        if (!visited[i] && vertices[i].color == vertices[vertex].color) {
            dfs_color(vertices, colors, num_colors, visited, num_vertices, i);
        }
    }

    if (vertices[vertex].color!= colors[vertex]) {
        return;
    }

    num_colors[vertex] = colors[vertex];
}

int main() {
    int num_vertices, num_edges, i, j, edge_vertex1, edge_vertex2;
    Vertex *vertices, *edges;
    int *colors, *num_colors;
    int *visited;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    vertices = (Vertex*)malloc(num_vertices * sizeof(Vertex));
    edges = (Vertex*)malloc(num_edges * sizeof(Vertex));
    colors = (int*)malloc(num_vertices * sizeof(int));
    num_colors = (int*)malloc(num_vertices * sizeof(int));
    visited = (int*)calloc(num_vertices, sizeof(int));

    for (i = 0; i < num_vertices; i++) {
        vertices[i].vertex = i;
    }

    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &edge_vertex1, &edge_vertex2);

        vertices[edge_vertex1].color = vertices[edge_vertex2].color = i;
    }

    initialize_colors(vertices, num_vertices);

    dfs_color(vertices, colors, num_colors, visited, num_vertices, 0);

    for (i = 0; i < num_vertices; i++) {
        printf("%d ", num_colors[i]);
    }
    printf("\n");

    free(vertices);
    free(edges);
    free(colors);
    free(num_colors);
    free(visited);

    return 0;
}