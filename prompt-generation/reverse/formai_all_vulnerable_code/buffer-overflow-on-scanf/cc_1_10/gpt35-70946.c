//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 50

// Define the adjacency matrix
int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

// Define the number of vertices and colors
int num_vertices;
int num_colors = 0;

// Keep track of the colored vertices
int colored_vertices[MAX_VERTICES];

// Check if a vertex can be colored with a given color
bool isSafe(int vertex, int color) {
    for(int i = 0; i < num_vertices; i++) {
        if(adjacency_matrix[vertex][i] && colored_vertices[i] == color) {
            return false;
        }
    }
    return true;
}

// Color the vertices of the graph
void color(int vertex) {
    if(vertex == num_vertices) {
        // all vertices have been colored successfully
        printf("\n\nHooray! We have successfully colored the graph with %d colors!\n\n", num_colors);
        for(int i = 0; i < num_vertices; i++) {
            printf("Vertex %d has color %d.\n", i, colored_vertices[i]);
        }
        return;
    }

    // color the vertex
    for(int i = 1; i <= num_colors; i++) {
        if(isSafe(vertex, i)) {
            colored_vertices[vertex] = i;
            color(vertex + 1);
            colored_vertices[vertex] = 0;
        }
    }
}

// Create a graph
void createGraph() {
    printf("\n\nYay! We're going to create a graph now!\n\n");

    printf("How many vertices does the graph have?\n");
    scanf("%d", &num_vertices);

    printf("\n\nAwesome! Enter the adjacency matrix for the graph:\n");

    for(int i = 0; i < num_vertices; i++) {
        printf("\nEnter row %d: ", i);
        for(int j = 0; j < num_vertices; j++) {
            scanf("%d", &adjacency_matrix[i][j]);
        }
    }
}

int main() {
    createGraph();

    while(num_colors < num_vertices) {
        num_colors++;

        for(int i = 0; i < num_vertices; i++) {
            colored_vertices[i] = 0;
        }

        printf("\n\nLet's try coloring the graph with %d colors!\n", num_colors);
        color(0);

        if(colored_vertices[0] == 0) {
            printf("\n\nOops! We can't color the graph with %d colors :( Let's try again with more colors.\n\n", num_colors + 1);
        }
        else {
            break;
        }
    }

    return 0;
}