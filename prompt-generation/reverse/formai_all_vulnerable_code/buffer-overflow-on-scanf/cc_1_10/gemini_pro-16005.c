//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

#define RED 1
#define BLUE 2
#define GREEN 3

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

int num_vertices;
int num_edges;

int is_safe(int v, int color) {
  for (int i = 0; i < num_vertices; i++) {
    if (graph[v][i] && colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

int color_graph(int v) {
  if (v == num_vertices) {
    return 1;
  }

  for (int color = 1; color <= 3; color++) {
    if (is_safe(v, color)) {
      colors[v] = color;

      if (color_graph(v + 1)) {
        return 1;
      }

      colors[v] = 0;
    }
  }

  return 0;
}

int main() {
  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);

  printf("Enter the number of edges: ");
  scanf("%d", &num_edges);

  printf("Enter the edges: ");
  for (int i = 0; i < num_edges; i++) {
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
  }

  if (color_graph(0)) {
    printf("The graph can be colored using 3 colors.\n");
    for (int i = 0; i < num_vertices; i++) {
      printf("Vertex %d is colored %d.\n", i, colors[i]);
    }
  } else {
    printf("The graph cannot be colored using 3 colors.\n");
  }

  return 0;
}