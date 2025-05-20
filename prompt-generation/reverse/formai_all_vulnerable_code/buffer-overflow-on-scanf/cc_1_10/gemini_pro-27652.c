//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define N 5 // Number of nodes
#define M 4 // Number of colors

// Graph is represented using adjacency matrix
int adj[N][N];

// Function to check if the graph is bipartite
int isBipartite(int n, int m) {
  // Create an array to store the colors of the nodes
  int colors[n];

  // Initialize all nodes to uncolored
  for (int i = 0; i < n; i++) {
    colors[i] = -1;
  }

  // Queue to store the nodes to be colored
  int queue[n];
  int front = 0;
  int rear = 0;

  // Color the first node with color 0
  colors[0] = 0;
  queue[rear++] = 0;

  // While there are nodes to be colored
  while (front != rear) {
    // Dequeue a node from the queue
    int u = queue[front++];

    // Iterate over all adjacent nodes of u
    for (int v = 0; v < n; v++) {
      // If there is an edge between u and v
      if (adj[u][v]) {
        // If v is not colored
        if (colors[v] == -1) {
          // Color v with the opposite color of u
          colors[v] = 1 - colors[u];
          queue[rear++] = v;
        }
        // If v is already colored and it has the same color as u
        else if (colors[v] == colors[u]) {
          // Graph is not bipartite
          return 0;
        }
      }
    }
  }

  // Graph is bipartite
  return 1;
}

// Main function
int main() {
  // Input the adjacency matrix
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &adj[i][j]);
    }
  }

  // Check if the graph is bipartite
  int result = isBipartite(N, M);

  // Print the result
  if (result) {
    printf("Graph is bipartite.\n");
  } else {
    printf("Graph is not bipartite.\n");
  }

  return 0;
}