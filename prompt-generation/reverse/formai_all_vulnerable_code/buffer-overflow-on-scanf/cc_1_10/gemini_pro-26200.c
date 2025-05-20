//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// A 2D array to represent the graph
int graph[100][100];

// An array to store the colors of the vertices
int colors[100];

// The number of vertices in the graph
int num_vertices;

// The number of colors to use
int num_colors;

// A function to check if a vertex is safe to color with a given color
int is_safe(int vertex, int color) {
  // Loop through all the adjacent vertices
  for (int i = 0; i < num_vertices; i++) {
    // If there is an edge between the vertex and the adjacent vertex
    if (graph[vertex][i] == 1) {
      // If the adjacent vertex is already colored with the given color
      if (colors[i] == color) {
        // The vertex is not safe to color with the given color
        return 0;
      }
    }
  }

  // The vertex is safe to color with the given color
  return 1;
}

// A function to color the graph using the backtracking algorithm
int color_graph(int vertex) {
  // If all the vertices have been colored
  if (vertex == num_vertices) {
    // The graph has been successfully colored
    return 1;
  }

  // Loop through all the colors
  for (int i = 0; i < num_colors; i++) {
    // If the vertex is safe to color with the given color
    if (is_safe(vertex, i)) {
      // Color the vertex with the given color
      colors[vertex] = i;

      // Recursively color the remaining vertices
      if (color_graph(vertex + 1)) {
        // The graph has been successfully colored
        return 1;
      }

      // The graph has not been successfully colored
      // Reset the color of the vertex
      colors[vertex] = -1;
    }
  }

  // The graph has not been successfully colored
  return 0;
}

// A function to print the colors of the vertices
void print_colors() {
  printf("The colors of the vertices are:\n");
  for (int i = 0; i < num_vertices; i++) {
    printf("Vertex %d: %d\n", i, colors[i]);
  }
}

// The main function
int main() {
  // Get the number of vertices and the number of colors
  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);

  printf("Enter the number of colors: ");
  scanf("%d", &num_colors);

  // Get the graph input
  printf("Enter the graph input:\n");
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  // Color the graph
  if (color_graph(0)) {
    // The graph has been successfully colored
    printf("The graph has been successfully colored.\n");
    print_colors();
  } else {
    // The graph has not been successfully colored
    printf("The graph cannot be colored with the given number of colors.\n");
  }

  return 0;
}