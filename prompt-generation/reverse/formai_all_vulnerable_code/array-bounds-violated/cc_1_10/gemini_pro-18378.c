//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
int num_nodes;

int is_safe(int node, int color) {
  for (int i = 0; i < num_nodes; i++) {
    if (graph[node][i] && colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

int graph_color(int node) {
  if (node == num_nodes) {
    return 1;
  }

  for (int color = 1; color <= num_nodes; color++) {
    if (is_safe(node, color)) {
      colors[node] = color;
      if (graph_color(node + 1)) {
        return 1;
      }
      colors[node] = 0;
    }
  }

  return 0;
}

int main() {
  int num_edges;
  scanf("%d %d", &num_nodes, &num_edges);

  for (int i = 0; i < num_edges; i++) {
    int node1, node2;
    scanf("%d %d", &node1, &node2);
    graph[node1][node2] = 1;
    graph[node2][node1] = 1;
  }

  if (graph_color(0)) {
    for (int i = 0; i < num_nodes; i++) {
      printf("%d ", colors[i]);
    }
    printf("\n");
  } else {
    printf("Graph cannot be colored.\n");
  }

  return 0;
}