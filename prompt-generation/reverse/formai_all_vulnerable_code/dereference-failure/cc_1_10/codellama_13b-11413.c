//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: brave
// Graph Representation in C
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct graph {
  int num_vertices;
  struct node **adjacency_list;
};

void print_graph(struct graph *g) {
  int i;
  for (i = 0; i < g->num_vertices; i++) {
    printf("%d: ", i);
    struct node *curr = g->adjacency_list[i];
    while (curr != NULL) {
      printf("%d ", curr->data);
      curr = curr->next;
    }
    printf("\n");
  }
}

int main() {
  struct graph *g = (struct graph *)malloc(sizeof(struct graph));
  g->num_vertices = 5;
  g->adjacency_list = (struct node **)malloc(g->num_vertices * sizeof(struct node *));
  int i;
  for (i = 0; i < g->num_vertices; i++) {
    g->adjacency_list[i] = NULL;
  }
  struct node *n1 = (struct node *)malloc(sizeof(struct node));
  n1->data = 1;
  n1->next = NULL;
  struct node *n2 = (struct node *)malloc(sizeof(struct node));
  n2->data = 2;
  n2->next = NULL;
  struct node *n3 = (struct node *)malloc(sizeof(struct node));
  n3->data = 3;
  n3->next = NULL;
  struct node *n4 = (struct node *)malloc(sizeof(struct node));
  n4->data = 4;
  n4->next = NULL;
  struct node *n5 = (struct node *)malloc(sizeof(struct node));
  n5->data = 5;
  n5->next = NULL;
  g->adjacency_list[0] = n1;
  g->adjacency_list[1] = n2;
  g->adjacency_list[2] = n3;
  g->adjacency_list[3] = n4;
  g->adjacency_list[4] = n5;
  print_graph(g);
  return 0;
}