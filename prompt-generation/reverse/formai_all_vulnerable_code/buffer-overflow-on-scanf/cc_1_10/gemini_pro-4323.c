//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

int **graph;
int *colors;
int num_vertices;
int num_colors;

int is_safe(int v, int color) {
  for (int i = 0; i < num_vertices; i++) {
    if (graph[v][i] && colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

int graph_coloring(int v) {
  if (v == num_vertices) {
    return 1;
  }

  for (int i = 0; i < num_colors; i++) {
    if (is_safe(v, i)) {
      colors[v] = i;
      if (graph_coloring(v + 1)) {
        return 1;
      }
      colors[v] = -1;
    }
  }
  return 0;
}

int main() {
  int edges;
  int v1, v2;

  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);
  printf("Enter the number of colors: ");
  scanf("%d", &num_colors);

  graph = (int **)malloc(sizeof(int *) * num_vertices);
  for (int i = 0; i < num_vertices; i++) {
    graph[i] = (int *)malloc(sizeof(int) * num_vertices);
    memset(graph[i], 0, sizeof(int) * num_vertices);
  }

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < edges; i++) {
    printf("Enter the vertices of edge %d: ", i + 1);
    scanf("%d %d", &v1, &v2);
    graph[v1][v2] = graph[v2][v1] = 1;
  }

  colors = (int *)malloc(sizeof(int) * num_vertices);
  memset(colors, -1, sizeof(int) * num_vertices);

  if (graph_coloring(0)) {
    printf("Graph can be colored with %d colors\n", num_colors);
    for (int i = 0; i < num_vertices; i++) {
      printf("Vertex %d is colored with color %d\n", i, colors[i]);
    }
  } else {
    printf("Graph cannot be colored with %d colors\n", num_colors);
  }

  for (int i = 0; i < num_vertices; i++) {
    free(graph[i]);
  }
  free(graph);
  free(colors);

  return 0;
}