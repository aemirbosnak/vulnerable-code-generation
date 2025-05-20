//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int nodes[MAX_NODES];
int colors[MAX_COLORS];
int adjacency_matrix[MAX_NODES][MAX_NODES];
int num_nodes, num_colors;

void print_coloring() {
  for (int i = 0; i < num_nodes; i++) {
    printf("Node %d: Color %d\n", i + 1, colors[nodes[i]]);
  }
}

int is_safe(int node, int color) {
  for (int i = 0; i < num_nodes; i++) {
    if (adjacency_matrix[node][i] == 1 && colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

int graph_coloring(int node) {
  if (node == num_nodes) {
    return 1;
  }

  for (int color = 0; color < num_colors; color++) {
    if (is_safe(node, color)) {
      colors[nodes[node]] = color;
      if (graph_coloring(node + 1)) {
        return 1;
      }
      colors[nodes[node]] = -1;
    }
  }

  return 0;
}

int main() {
  FILE *fp;
  char filename[100];

  printf("Enter the input file name: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  fscanf(fp, "%d %d", &num_nodes, &num_colors);

  for (int i = 0; i < num_nodes; i++) {
    fscanf(fp, "%d", &nodes[i]);
  }

  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      fscanf(fp, "%d", &adjacency_matrix[i][j]);
    }
  }

  fclose(fp);

  memset(colors, -1, sizeof(colors));

  if (graph_coloring(0)) {
    printf("Graph coloring solution:\n");
    print_coloring();
  } else {
    printf("No solution exists!\n");
  }

  return 0;
}