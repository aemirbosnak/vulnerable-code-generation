//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graphColoring(int **graph, int n, int k) {
  int i, j, color, bestColor = -1, currentColor = -1;
  int *visited = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }

  for (i = 0; i < k; i++) {
    for (j = 0; j < n; j++) {
      if (visited[j] == 0 && graph[j][i] == 1) {
        color = 1;
        while (visited[color] || graph[j][color] == 1) {
          color++;
        }
        visited[j] = color;
        if (color > bestColor) {
          bestColor = color;
        }
      }
    }
  }

  free(visited);
  return bestColor;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);

  int **graph = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    graph[i] = malloc(k * sizeof(int));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  int result = graphColoring(graph, n, k);

  printf("%d", result);

  free(graph);

  return 0;
}