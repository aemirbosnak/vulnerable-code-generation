//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The number of vertices in the graph
#define V 4

// A utility function to find the minimum of two numbers
int min(int a, int b) {
  return (a < b) ? a : b;
}

// A utility function to find the maximum of two numbers
int max(int a, int b) {
  return (a > b) ? a : b;
}

// A utility function to check if the graph is bipartite
bool isBipartite(int adj[][V], int src) {
  // Create a queue of vertices and enqueue the source vertex
  int queue[V];
  int front = -1;
  int rear = -1;
  queue[++rear] = src;

  // Create a color array to store the colors assigned to the vertices
  int color[V];
  for (int i = 0; i < V; i++) {
    color[i] = -1;
  }

  // Assign the source vertex to color 1
  color[src] = 1;

  // While the queue is not empty
  while (front <= rear) {
    // Dequeue a vertex from the queue
    int u = queue[++front];

    // For each adjacent vertex of the dequeued vertex
    for (int v = 0; v < V; v++) {
      // If there is an edge between u and v and v is not visited
      if (adj[u][v] == 1 && color[v] == -1) {
        // Assign v to the opposite color of u
        color[v] = 1 - color[u];

        // Enqueue v
        queue[++rear] = v;
      }

      // If there is an edge between u and v and u and v have the same color
      else if (adj[u][v] == 1 && color[v] == color[u]) {
        return false;
      }
    }
  }

  // If all vertices have been colored without any conflicts, then the graph is bipartite
  return true;
}

// A utility function to print the graph
void printGraph(int adj[][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }
}

// The main function
int main() {
  // Create an adjacency matrix for the graph
  int adj[][V] = {
    {0, 1, 1, 0},
    {1, 0, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 1, 0}
  };

  // Check if the graph is bipartite
  if (isBipartite(adj, 0)) {
    printf("The graph is bipartite\n");
  } else {
    printf("The graph is not bipartite\n");
  }

  // Print the adjacency matrix
  printGraph(adj);

  return 0;
}