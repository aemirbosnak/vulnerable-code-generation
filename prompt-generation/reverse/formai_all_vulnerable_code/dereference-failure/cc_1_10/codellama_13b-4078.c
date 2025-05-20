//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: ephemeral
/*
 * A unique C Graph representation example program in a ephemeral style.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *label;
  struct node *next;
} node;

typedef struct graph {
  node *vertices;
  node *edges;
} graph;

void init_graph(graph *g) {
  g->vertices = NULL;
  g->edges = NULL;
}

void add_vertex(graph *g, char *label) {
  node *v = malloc(sizeof(node));
  v->label = strdup(label);
  v->next = g->vertices;
  g->vertices = v;
}

void add_edge(graph *g, char *src, char *dest) {
  node *e = malloc(sizeof(node));
  e->label = strdup(src);
  e->next = g->edges;
  g->edges = e;
}

void print_graph(graph *g) {
  printf("Vertices:\n");
  for (node *v = g->vertices; v != NULL; v = v->next) {
    printf("  %s\n", v->label);
  }
  printf("Edges:\n");
  for (node *e = g->edges; e != NULL; e = e->next) {
    printf("  %s -> %s\n", e->label, e->next->label);
  }
}

int main(void) {
  graph g;
  init_graph(&g);
  add_vertex(&g, "A");
  add_vertex(&g, "B");
  add_vertex(&g, "C");
  add_edge(&g, "A", "B");
  add_edge(&g, "B", "C");
  print_graph(&g);
  return 0;
}