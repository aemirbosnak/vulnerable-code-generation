//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void graphColoring(int **graph, int n, int k) {
  int i, j, color, conflict = 0;
  int *visited = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      if (visited[j] && graph[i][j] == 1) {
        conflict = 1;
      }
    }
    visited[color] = 1;
  }

  if (conflict) {
    printf("No solution found.\n");
  } else {
    printf("Solution found.\n");
  }

  free(visited);
}

int main() {
  int n, k, i, j;
  int **graph;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the number of colors: ");
  scanf("%d", &k);

  graph = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    graph[i] = (int *)malloc(k * sizeof(int));
  }

  printf("Enter the adjacency matrix: ");
  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  graphColoring(graph, n, k);

  return 0;
}