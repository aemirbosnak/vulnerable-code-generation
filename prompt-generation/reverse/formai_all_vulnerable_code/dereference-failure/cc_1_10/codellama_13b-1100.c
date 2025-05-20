//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: romantic
// A romantic graph representation program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct node {
  char name[50];
  struct node *next;
} node;

// Graph structure
typedef struct graph {
  node *nodes;
  int num_nodes;
} graph;

// Function to add a node to the graph
void add_node(graph *g, char *name) {
  node *n = malloc(sizeof(node));
  strcpy(n->name, name);
  n->next = NULL;
  g->num_nodes++;
}

// Function to add an edge between two nodes
void add_edge(graph *g, char *name1, char *name2) {
  node *n1 = g->nodes;
  node *n2 = g->nodes;
  while (n1 != NULL) {
    if (strcmp(n1->name, name1) == 0) {
      break;
    }
    n1 = n1->next;
  }
  while (n2 != NULL) {
    if (strcmp(n2->name, name2) == 0) {
      break;
    }
    n2 = n2->next;
  }
  if (n1 != NULL && n2 != NULL) {
    n1->next = n2;
  }
}

// Function to print the graph
void print_graph(graph *g) {
  node *n = g->nodes;
  while (n != NULL) {
    printf("%s\n", n->name);
    n = n->next;
  }
}

// Main function
int main() {
  graph *g = malloc(sizeof(graph));
  g->num_nodes = 0;
  g->nodes = NULL;

  add_node(g, "Alice");
  add_node(g, "Bob");
  add_node(g, "Charlie");
  add_node(g, "David");
  add_node(g, "Eve");

  add_edge(g, "Alice", "Bob");
  add_edge(g, "Bob", "Charlie");
  add_edge(g, "Charlie", "David");
  add_edge(g, "David", "Eve");

  print_graph(g);

  return 0;
}