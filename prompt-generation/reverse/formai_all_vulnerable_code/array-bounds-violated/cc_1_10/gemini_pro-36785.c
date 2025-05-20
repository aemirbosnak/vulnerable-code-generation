//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the number of colors
#define NUM_COLORS 4

// Define the maximum number of nodes
#define MAX_NODES 100

// Create a graph structure
typedef struct graph {
  int num_nodes;
  int num_edges;
  int adj_matrix[MAX_NODES][MAX_NODES];
} graph_t;

// Create a node structure
typedef struct node {
  int color;
  int visited;
} node_t;

// Create a graph coloring function
int graph_coloring(graph_t *graph, node_t *nodes) {
  // Initialize the colors of all nodes to -1
  for (int i = 0; i < graph->num_nodes; i++) {
    nodes[i].color = -1;
  }

  // Iterate over all nodes
  for (int i = 0; i < graph->num_nodes; i++) {
    // If the node has not been visited, color it
    if (!nodes[i].visited) {
      // Get the list of adjacent nodes
      int adj_nodes[MAX_NODES];
      int num_adj_nodes = 0;
      for (int j = 0; j < graph->num_nodes; j++) {
        if (graph->adj_matrix[i][j] == 1) {
          adj_nodes[num_adj_nodes] = j;
          num_adj_nodes++;
        }
      }

      // Create a list of available colors
      int available_colors[NUM_COLORS];
      for (int j = 0; j < NUM_COLORS; j++) {
        available_colors[j] = 1;
      }

      // Mark the colors of the adjacent nodes as unavailable
      for (int j = 0; j < num_adj_nodes; j++) {
        available_colors[nodes[adj_nodes[j]].color] = 0;
      }

      // Find the first available color
      int color = -1;
      for (int j = 0; j < NUM_COLORS; j++) {
        if (available_colors[j] == 1) {
          color = j;
          break;
        }
      }

      // Color the node
      nodes[i].color = color;
      nodes[i].visited = 1;
    }
  }

  // Return 1 if the graph is colored successfully, otherwise return 0
  return 1;
}

// Create a main function
int main() {
  // Create a graph
  graph_t graph;
  graph.num_nodes = 4;
  graph.num_edges = 4;
  graph.adj_matrix[0][1] = 1;
  graph.adj_matrix[1][0] = 1;
  graph.adj_matrix[1][2] = 1;
  graph.adj_matrix[2][1] = 1;
  graph.adj_matrix[2][3] = 1;
  graph.adj_matrix[3][2] = 1;

  // Create the nodes
  node_t nodes[MAX_NODES];

  // Color the graph
  int success = graph_coloring(&graph, nodes);

  // Print the result
  if (success) {
    printf("The graph was colored successfully.\n");
    for (int i = 0; i < graph.num_nodes; i++) {
      printf("Node %d: Color %d\n", i, nodes[i].color);
    }
  } else {
    printf("The graph could not be colored.\n");
  }

  return 0;
}