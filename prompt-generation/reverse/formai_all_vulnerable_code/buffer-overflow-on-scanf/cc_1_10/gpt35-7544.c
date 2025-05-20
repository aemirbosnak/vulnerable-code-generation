//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100 // maximum number of nodes

int n; // number of nodes
int color[MAX_N]; // color array
int graph[MAX_N][MAX_N]; // adjacency matrix

// function to check if node can be colored with given color
int is_safe(int node, int c) {
  for (int i = 0; i < n; i++) {
    if (graph[node][i] && color[i] == c) {
      return 0;
    }
  }
  return 1;
}

// recursive function to solve graph coloring problem
int graph_color(int node) {
  if (node == n) {
    return 1;
  }

  for (int i = 1; i <= 3; i++) {
    if (is_safe(node, i)) {
      color[node] = i;
      if (graph_color(node + 1)) {
        return 1;
      }
      color[node] = 0;
    }
  }
  return 0;
}

int main() {
  printf("Enter the number of nodes in the graph: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix:\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  memset(color, 0, sizeof(color));

  if (graph_color(0)) {
    printf("The coloring of graph with minimum number of colors is:\n");
    for (int i = 0; i < n; i++) {
      printf("Node %d is colored with %d.\n", i, color[i]);
    }
  } else {
    printf("Graph cannot be colored with 3 colors or less.\n");
  }

  return 0;
}