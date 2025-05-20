//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
  int n;
  int **adj;
} graph;

graph *create_graph(int n) {
  graph *g = malloc(sizeof(graph));
  g->n = n;
  g->adj = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    g->adj[i] = malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
      g->adj[i][j] = 0;
    }
  }
  return g;
}

void add_edge(graph *g, int u, int v) {
  g->adj[u][v] = 1;
  g->adj[v][u] = 1;
}

int is_safe(graph *g, int v, int c, int *color) {
  for (int i = 0; i < g->n; i++) {
    if (g->adj[v][i] && color[i] == c) {
      return 0;
    }
  }
  return 1;
}

int graph_color(graph *g, int *color, int v) {
  if (v == g->n) {
    return 1;
  }
  for (int c = 1; c <= 4; c++) {
    if (is_safe(g, v, c, color)) {
      color[v] = c;
      if (graph_color(g, color, v + 1)) {
        return 1;
      }
      color[v] = 0;
    }
  }
  return 0;
}

int main() {
  int n;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  graph *g = create_graph(n);
  int edges;
  printf("Enter the number of edges: ");
  scanf("%d", &edges);
  for (int i = 0; i < edges; i++) {
    int u, v;
    printf("Enter the edge (u, v): ");
    scanf("%d %d", &u, &v);
    add_edge(g, u, v);
  }
  int color[n];
  for (int i = 0; i < n; i++) {
    color[i] = 0;
  }
  if (graph_color(g, color, 0)) {
    printf("Graph colored successfully: ");
    for (int i = 0; i < n; i++) {
      printf("%d ", color[i]);
    }
    printf("\n");
  } else {
    printf("Graph cannot be colored.\n");
  }
  return 0;
}