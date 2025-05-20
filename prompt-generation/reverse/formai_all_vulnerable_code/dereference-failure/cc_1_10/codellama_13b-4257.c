//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: happy
// Happy C Graph Representation Example Program

#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node* next;
};

struct graph {
  struct node** adjacency_list;
  int num_vertices;
  int num_edges;
};

void print_graph(struct graph* g) {
  for (int i = 0; i < g->num_vertices; i++) {
    struct node* curr = g->adjacency_list[i];
    printf("%d: ", i);
    while (curr != NULL) {
      printf("%d ", curr->value);
      curr = curr->next;
    }
    printf("\n");
  }
}

void add_edge(struct graph* g, int v1, int v2) {
  struct node* new_node = malloc(sizeof(struct node));
  new_node->value = v2;
  new_node->next = g->adjacency_list[v1];
  g->adjacency_list[v1] = new_node;
  g->num_edges++;
}

void remove_edge(struct graph* g, int v1, int v2) {
  struct node* curr = g->adjacency_list[v1];
  struct node* prev = NULL;
  while (curr != NULL) {
    if (curr->value == v2) {
      if (prev == NULL) {
        g->adjacency_list[v1] = curr->next;
      } else {
        prev->next = curr->next;
      }
      free(curr);
      g->num_edges--;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
}

int main() {
  struct graph* g = malloc(sizeof(struct graph));
  g->num_vertices = 5;
  g->num_edges = 0;
  g->adjacency_list = malloc(g->num_vertices * sizeof(struct node*));
  for (int i = 0; i < g->num_vertices; i++) {
    g->adjacency_list[i] = NULL;
  }

  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 3);
  add_edge(g, 2, 4);
  add_edge(g, 3, 4);

  print_graph(g);

  remove_edge(g, 0, 1);
  remove_edge(g, 3, 4);

  print_graph(g);

  return 0;
}