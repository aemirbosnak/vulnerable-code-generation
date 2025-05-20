//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph {
  int n;
  int **adj;
} graph;

typedef struct stack {
  int *items;
  int top;
  int size;
} stack;

void push(stack *s, int item) {
  if (s->top == s->size - 1) {
    s->size *= 2;
    s->items = realloc(s->items, s->size * sizeof(int));
  }
  s->items[++s->top] = item;
}

int pop(stack *s) {
  if (s->top == -1) {
    return -1;
  }
  return s->items[s->top--];
}

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

int is_safe(graph *g, int vertex, int color[], int c) {
  for (int i = 0; i < g->n; i++) {
    if (g->adj[vertex][i] && color[i] == c) {
      return 0;
    }
  }
  return 1;
}

int graph_color(graph *g, int vertex, int color[], int m) {
  if (vertex == g->n) {
    return 1;
  }

  for (int c = 1; c <= m; c++) {
    if (is_safe(g, vertex, color, c)) {
      color[vertex] = c;
      if (graph_color(g, vertex + 1, color, m)) {
        return 1;
      }
      color[vertex] = 0;
    }
  }

  return 0;
}

int main() {
  int n, m;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the number of colors: ");
  scanf("%d", &m);

  graph *g = create_graph(n);

  int u, v;
  printf("Enter the edges (u, v):\n");
  while (scanf("%d %d", &u, &v) != EOF) {
    add_edge(g, u, v);
  }

  int *color = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    color[i] = 0;
  }

  if (graph_color(g, 0, color, m)) {
    printf("The graph is colorable with %d colors:\n", m);
    for (int i = 0; i < n; i++) {
      printf("Vertex %d: Color %d\n", i, color[i]);
    }
  } else {
    printf("The graph is not colorable with %d colors.\n", m);
  }

  free(g->adj);
  free(g);
  free(color);

  return 0;
}