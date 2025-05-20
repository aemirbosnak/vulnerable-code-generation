//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10
#define MAX_NODES 100

int nodes[MAX_NODES];
int colors[MAX_NODES];

int num_colors;
int num_nodes;

// Check if a color is valid for a node
int is_valid_color(int node, int color) {
  for (int i = 0; i < num_nodes; i++) {
    if (nodes[i] == node) {
      if (colors[i] == color) {
        return 0;
      }
    }
  }
  return 1;
}

// Find the next uncolored node
int find_next_uncolored_node() {
  for (int i = 0; i < num_nodes; i++) {
    if (colors[i] == -1) {
      return i;
    }
  }
  return -1;
}

// Color a node
int color_node(int node, int color) {
  if (is_valid_color(node, color)) {
    colors[node] = color;
    return 1;
  }
  return 0;
}

// Solve the graph coloring problem
int solve_graph_coloring() {
  int next_node = find_next_uncolored_node();
  if (next_node == -1) {
    return 1;
  }
  for (int i = 0; i < num_colors; i++) {
    if (color_node(next_node, i)) {
      if (solve_graph_coloring()) {
        return 1;
      }
      colors[next_node] = -1;
    }
  }
  return 0;
}

int main() {
  // Read the graph from the input
  scanf("%d %d", &num_nodes, &num_colors);
  for (int i = 0; i < num_nodes; i++) {
    scanf("%d", &nodes[i]);
  }

  // Initialize the colors array
  for (int i = 0; i < num_nodes; i++) {
    colors[i] = -1;
  }

  // Solve the graph coloring problem
  int result = solve_graph_coloring();

  // Print the result
  if (result) {
    printf("Yes, the graph can be colored using %d colors.\n", num_colors);
    for (int i = 0; i < num_nodes; i++) {
      printf("%d ", colors[i]);
    }
    printf("\n");
  } else {
    printf("No, the graph cannot be colored using %d colors.\n", num_colors);
  }

  return 0;
}