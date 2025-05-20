//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void graph_coloring(int **graph, int n, int k) {
  int i, j, color, visited = 0, conflict = 0;
  int *colors = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    colors[i] = -1;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < graph[i][0]; j++) {
      if (colors[graph[i][j]] == colors[i]) {
        conflict = 1;
      }
    }
  }
  if (conflict) {
    printf("No solution\n");
  } else {
    for (i = 0; i < n; i++) {
      printf("Vertex %d colored with %d\n", i + 1, colors[i] + 1);
    }
  }
  free(colors);
}

int main() {
  int **graph = NULL;
  int n, k;

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the number of colors: ");
  scanf("%d", &k);

  graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    graph[i] = (int *)malloc(2 * sizeof(int));
  }

  printf("Enter the adjacency list: ");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d ", &graph[i][j]);
    }
  }

  graph_coloring(graph, n, k);

  return 0;
}