//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

int graph[MAX_VERTICES][MAX_VERTICES];
int color_arr[MAX_VERTICES];

/* Function to check if the current vertex can be colored with the given color */
int can_color_vertex(int vertex, int color, int num_vertices) {
    int i;
    for (i = 0; i < num_vertices; i++) {
        if (graph[vertex][i] && color_arr[i] == color) {
            return 0;
        }
    }
    return 1;
}

/* Function to color the graph recursively */
int color_graph(int vertex, int num_vertices, int num_colors) {
    int color;
    if (vertex == num_vertices) {
        return 1; // Base case: If all vertices are colored, return true
    }
    for (color = 1; color <= num_colors; color++) {
        if (can_color_vertex(vertex, color, num_vertices)) {
            color_arr[vertex] = color;
            if (color_graph(vertex + 1, num_vertices, num_colors)) {
                return 1; // Check if the next vertex can be colored with the given color. If yes, recur for the next vertex.
            }
            color_arr[vertex] = 0; // Backtrack
        }
    }
    return 0; // Return false if no color can be assigned to this vertex
}

/* Main function */
int main() {
    int num_vertices, num_edges, vertex1, vertex2, i;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &num_edges);
    for (i = 0; i < num_edges; i++) {
        printf("Enter the vertices of edge %d: ", i+1);
        scanf("%d%d", &vertex1, &vertex2);
        graph[vertex1][vertex2] = 1;
        graph[vertex2][vertex1] = 1;
    }
    int num_colors;
    printf("Enter the number of colors you want to use: ");
    scanf("%d", &num_colors);
    if (color_graph(0, num_vertices, num_colors)) {
        printf("The graph can be colored with %d colors as follows:\n", num_colors);
        for (i = 0; i < num_vertices; i++) {
            printf("Vertex %d: Color %d\n", i, color_arr[i]);
        }
    } else {
        printf("The graph cannot be colored with %d colors.\n", num_colors);
    }
    return 0;
}