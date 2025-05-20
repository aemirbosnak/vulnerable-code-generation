//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void graph_coloring(int **graph, int n) {
  int *colors = (int *)malloc(n * sizeof(int));
  int i, j, k, color = 0;

  for (i = 0; i < n; i++) {
    colors[i] = -1;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < graph[i][0]; j++) {
      if (colors[graph[i][j]] != -1) {
        color = colors[graph[i][j]] + 1;
      }
    }
    colors[i] = color;
  }

  for (i = 0; i < n; i++) {
    printf("Vertex %d colored with %d\n", i + 1, colors[i]);
  }
}

int main() {
  int **graph = (int **)malloc(MAX * sizeof(int *));
  int n, i, j, k;

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  graph = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    graph[i] = (int *)malloc(MAX * sizeof(int));
  }

  printf("Enter the number of edges: ");
  scanf("%d", &k);

  for (i = 0; i < k; i++) {
    printf("Enter the source vertex: ");
    scanf("%d", &i);

    printf("Enter the destination vertex: ");
    scanf("%d", &j);

    graph[i][0]++;
    graph[i][j] = j;
  }

  graph_coloring(graph, n);

  return 0;
}