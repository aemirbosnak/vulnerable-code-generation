//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int num_vertices, num_colors;

bool isSafe(int vertex, int c) {
  for (int i = 0; i < num_vertices; i++) {
    if (graph[vertex][i] && c == color[i]) return false;
  }
  return true;
}

bool graphColoring(int vertex) {
  if (vertex == num_vertices) return true;

  for (int c = 1; c <= num_colors; c++) {
    if (isSafe(vertex, c)) {
      color[vertex] = c;
      if (graphColoring(vertex + 1)) return true;
      color[vertex] = 0;
    }
  }

  return false;
}

int main() {
  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);
  printf("Enter the number of colors: ");
  scanf("%d", &num_colors);

  printf("Enter the adjacency matrix of the graph:\n");
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  if (graphColoring(0)) {
    printf("The graph can be colored using %d colors as follows:\n", num_colors);
    for (int i = 0; i < num_vertices; i++) {
      printf("Vertex %d: Color %d\n", i + 1, color[i]);
    }
  } else {
    printf("The graph cannot be colored using %d colors.\n", num_colors);
  }

  return 0;
}