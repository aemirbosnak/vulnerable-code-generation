//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define INFTY 999999999

int main() {
  int n, m, i, j, k;
  int dist[100][100];

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the number of edges: ");
  scanf("%d", &m);

  // Initialize the distance matrix to infinity
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      dist[i][j] = INFTY;
    }
  }

  // Set the diagonal elements to 0
  for (i = 0; i < n; i++) {
    dist[i][i] = 0;
  }

  // Read the edges
  for (i = 0; i < m; i++) {
    int u, v, w;
    printf("Enter the source node, destination node, and weight: ");
    scanf("%d %d %d", &u, &v, &w);
    dist[u][v] = w;
  }

  // Print the original distance matrix
  printf("The original distance matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (dist[i][j] == INFTY) {
        printf("INF ");
      } else {
        printf("%d ", dist[i][j]);
      }
    }
    printf("\n");
  }

  // Floyd-Warshall algorithm to find the shortest paths
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (dist[i][k] != INFTY && dist[k][j] != INFTY) {
          if (dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
  }

  // Print the shortest path matrix
  printf("The shortest path matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (dist[i][j] == INFTY) {
        printf("INF ");
      } else {
        printf("%d ", dist[i][j]);
      }
    }
    printf("\n");
  }

  return 0;
}