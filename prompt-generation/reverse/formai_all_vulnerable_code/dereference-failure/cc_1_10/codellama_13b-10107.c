//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: detailed
/*
 * A unique C Graph representation example program
 */
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a graph node
typedef struct {
  int value;
  struct node *next;
} node;

// Define the structure for a graph
typedef struct {
  node *head;
  node *tail;
  int size;
} graph;

// Function to create a new graph
graph *create_graph() {
  graph *g = (graph *)malloc(sizeof(graph));
  g->head = NULL;
  g->tail = NULL;
  g->size = 0;
  return g;
}

// Function to add a new node to the graph
void add_node(graph *g, int value) {
  node *n = (node *)malloc(sizeof(node));
  n->value = value;
  n->next = NULL;
  if (g->head == NULL) {
    g->head = n;
    g->tail = n;
  } else {
    g->tail->next = n;
    g->tail = n;
  }
  g->size++;
}

// Function to remove a node from the graph
void remove_node(graph *g, int value) {
  node *curr = g->head;
  node *prev = NULL;
  while (curr != NULL && curr->value != value) {
    prev = curr;
    curr = curr->next;
  }
  if (curr == NULL) {
    return;
  }
  if (curr == g->head) {
    g->head = curr->next;
  } else {
    prev->next = curr->next;
  }
  free(curr);
  g->size--;
}

// Function to print the graph
void print_graph(graph *g) {
  node *curr = g->head;
  while (curr != NULL) {
    printf("%d ", curr->value);
    curr = curr->next;
  }
  printf("\n");
}

// Function to free the graph
void free_graph(graph *g) {
  node *curr = g->head;
  while (curr != NULL) {
    node *next = curr->next;
    free(curr);
    curr = next;
  }
  free(g);
}

int main() {
  // Create a new graph
  graph *g = create_graph();

  // Add some nodes to the graph
  add_node(g, 1);
  add_node(g, 2);
  add_node(g, 3);
  add_node(g, 4);

  // Print the graph
  print_graph(g);

  // Remove a node from the graph
  remove_node(g, 2);

  // Print the graph again
  print_graph(g);

  // Free the graph
  free_graph(g);

  return 0;
}