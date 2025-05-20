//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct {
  int node;
  int color;
} node_t;

int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];

void print_graph(int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}

void print_colors(int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", colors[i]);
  }
  printf("\n");
}

int color_node(int node, int color) {
  colors[node] = color;
  return 1;
}

int is_color_safe(int node, int color) {
  int i;
  for (i = 0; i < MAX_NODES; i++) {
    if (colors[i] == color && graph[node][i] == 1) {
      return 0;
    }
  }
  return 1;
}

int color_graph(int n) {
  int i, j, color;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (graph[i][j] == 1) {
        color = colors[j];
        if (is_color_safe(i, color)) {
          color_node(i, color);
          break;
        }
      }
    }
  }
  return 1;
}

int main() {
  int n, i, j, k;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
    colors[i] = 0;
  }
  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }
  color_graph(n);
  print_graph(n);
  print_colors(n);
  return 0;
}