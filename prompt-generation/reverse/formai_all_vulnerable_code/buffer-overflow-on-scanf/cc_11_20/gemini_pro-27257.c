//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Romeo and Juliet graph coloring problem
// Given a graph with n nodes and m edges, find a coloring of the nodes such that no two adjacent nodes have the same color.

// The graph is represented as an adjacency matrix.
// The number of colors is represented by k.
// The coloring is represented by an array of size n, where each element represents the color of the corresponding node.
int main() {
  // The graph is represented as an adjacency matrix.
  int **adjMatrix;

  // Number of nodes.
  int n;

  // Number of colors.
  int k;

  // The coloring is represented by an array of size n, where each element represents the color of the corresponding node.
  int *coloring;

  // Read the input.
  scanf("%d %d", &n, &k);

  // Allocate memory for the adjacency matrix.
  adjMatrix = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    adjMatrix[i] = (int *)malloc(n * sizeof(int));
  }

  // Read the adjacency matrix.
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &adjMatrix[i][j]);
    }
  }

  // Allocate memory for the coloring.
  coloring = (int *)malloc(n * sizeof(int));

  // Initialize the coloring to -1.
  for (int i = 0; i < n; i++) {
    coloring[i] = -1;
  }

  // Color the graph.
  for (int i = 0; i < n; i++) {
    // If the node is not colored, color it with the first available color.
    if (coloring[i] == -1) {
      coloring[i] = 0;

      // Color the adjacent nodes with a different color.
      for (int j = 0; j < n; j++) {
        if (adjMatrix[i][j] == 1) {
          coloring[j] = (coloring[j] + 1) % k;
        }
      }
    }
  }

  // Print the coloring.
  for (int i = 0; i < n; i++) {
    printf("%d ", coloring[i]);
  }

  printf("\n");

  // Free the memory.
  for (int i = 0; i < n; i++) {
    free(adjMatrix[i]);
  }
  free(adjMatrix);
  free(coloring);

  return 0;
}