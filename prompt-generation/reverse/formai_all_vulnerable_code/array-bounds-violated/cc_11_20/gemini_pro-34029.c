//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int main() {
  int graph[N][N], colors[N], visited[N], i, j, k, count = 0;
  srand(time(NULL));

  // Generate a random graph
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      graph[i][j] = rand() % 2;
    }
  }

  // Print the graph
  printf("Graph:\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  // Initialize the colors array
  for (i = 0; i < N; i++) {
    colors[i] = -1;
  }

  // Color the first vertex
  colors[0] = 0;

  // Iterate over the remaining vertices
  for (i = 1; i < N; i++) {
    // Find the first available color
    for (j = 0; j <= N; j++) {
      visited[j] = 0;
    }
    for (k = 0; k < N; k++) {
      if (graph[i][k] == 1) {
        visited[colors[k]] = 1;
      }
    }
    for (j = 0; j <= N; j++) {
      if (visited[j] == 0) {
        colors[i] = j;
        break;
      }
    }
  }

  // Print the colors
  printf("Colors:\n");
  for (i = 0; i < N; i++) {
    printf("%d ", colors[i]);
  }
  printf("\n");

  // Check if the graph is colored properly
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (graph[i][j] == 1 && colors[i] == colors[j]) {
        count++;
      }
    }
  }

  if (count == 0) {
    printf("The graph is colored properly.\n");
  } else {
    printf("The graph is not colored properly.\n");
  }

  return 0;
}