//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
  int id;
  int distance;
  struct node* next;
} node;

typedef struct {
  int id;
  struct node* nodes[MAX_NODES];
} graph;

void init_graph(graph* g) {
  for (int i = 0; i < MAX_NODES; i++) {
    g->nodes[i] = NULL;
  }
}

void add_node(graph* g, int id) {
  node* new_node = malloc(sizeof(node));
  new_node->id = id;
  new_node->distance = 0;
  new_node->next = NULL;

  g->nodes[id] = new_node;
}

void add_edge(graph* g, int from, int to) {
  node* from_node = g->nodes[from];
  node* to_node = g->nodes[to];

  if (from_node == NULL || to_node == NULL) {
    printf("Invalid node\n");
    return;
  }

  to_node->distance = from_node->distance + 1;
  to_node->next = from_node;
}

void print_graph(graph* g) {
  for (int i = 0; i < MAX_NODES; i++) {
    node* current_node = g->nodes[i];
    if (current_node != NULL) {
      printf("%d -> %d\n", i, current_node->id);
    }
  }
}

int main() {
  graph* g = malloc(sizeof(graph));
  init_graph(g);

  add_node(g, 1);
  add_node(g, 2);
  add_node(g, 3);
  add_node(g, 4);
  add_node(g, 5);
  add_node(g, 6);

  add_edge(g, 1, 2);
  add_edge(g, 2, 3);
  add_edge(g, 3, 4);
  add_edge(g, 4, 5);
  add_edge(g, 5, 6);
  add_edge(g, 6, 1);

  print_graph(g);

  return 0;
}