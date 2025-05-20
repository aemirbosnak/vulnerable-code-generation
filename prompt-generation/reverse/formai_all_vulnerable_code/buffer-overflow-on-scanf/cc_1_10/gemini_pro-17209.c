//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
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

int graph_color(int v) {
  if (v == num_vertices) {
    return 1;
  }

  for (int c = 1; c <= num_colors; c++) {
    if (is_safe(v, c)) {
      colors[v] = c;
      if (graph_color(v + 1)) {
        return 1;
      }
      colors[v] = 0;
    }
  }

  return 0;
}

int main() {
  int i, j;

  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);

  printf("Enter the number of colors: ");
  scanf("%d", &num_colors);

  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < num_vertices; i++) {
    for (j = 0; j < num_vertices; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  if (graph_color(0)) {
    printf("Graph can be colored with %d colors: ", num_colors);
    for (i = 0; i < num_vertices; i++) {
      printf("%d ", colors[i]);
    }
    printf("\n");
  } else {
    printf("Graph cannot be colored with %d colors.\n", num_colors);
  }

  return 0;
}