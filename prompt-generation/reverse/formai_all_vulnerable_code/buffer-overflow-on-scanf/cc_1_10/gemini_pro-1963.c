//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_COLORS 10

// Graph represented as an adjacency matrix
int graph[MAX_NODES][MAX_NODES];

// Colors assigned to each node
int colors[MAX_NODES];

// Number of nodes in the graph
int num_nodes;

// Number of colors used
int num_colors;

// Function to check if a given color can be assigned to a node
int is_safe(int node, int color) {
  // Check if any adjacent node has the same color
  for (int i = 0; i < num_nodes; i++) {
    if (graph[node][i] && colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

// Recursive function to color the graph
int color_graph(int node) {
  // Base case: all nodes have been colored
  if (node == num_nodes) {
    return 1;
  }

  // Try all possible colors for the current node
  for (int color = 1; color <= num_colors; color++) {
    // Check if the color is safe to assign
    if (is_safe(node, color)) {
      // Assign the color to the node
      colors[node] = color;

      // Recursively color the remaining nodes
      if (color_graph(node + 1)) {
        return 1;
      }

      // If the recursive call fails, backtrack and try another color
      colors[node] = 0;
    }
  }

  // If no color can be assigned to the current node, return 0
  return 0;
}

int main() {
  // Read the number of nodes and edges from the user
  printf("Enter the number of nodes and edges: ");
  scanf("%d %d", &num_nodes, &num_colors);

  // Read the edges of the graph
  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  // Color the graph
  if (color_graph(0)) {
    printf("Graph colored successfully!\n");
    for (int i = 0; i < num_nodes; i++) {
      printf("Node %d is colored %d\n", i, colors[i]);
    }
  } else {
    printf("Graph cannot be colored with the given number of colors!\n");
  }

  return 0;
}