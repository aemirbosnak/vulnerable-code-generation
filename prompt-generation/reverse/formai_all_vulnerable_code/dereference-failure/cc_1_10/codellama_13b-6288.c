//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: thoughtful
// A thoughtful C Graph representation example program

#include <stdio.h>
#include <stdlib.h>

// Struct for a graph node
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Struct for a graph
typedef struct graph {
  node_t *head;
  int size;
} graph_t;

// Function to add a node to the graph
void add_node(graph_t *graph, int data) {
  node_t *node = malloc(sizeof(node_t));
  node->data = data;
  node->next = NULL;
  if (graph->head == NULL) {
    graph->head = node;
  } else {
    node_t *curr = graph->head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = node;
  }
  graph->size++;
}

// Function to print the graph
void print_graph(graph_t *graph) {
  node_t *curr = graph->head;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

// Function to free the graph
void free_graph(graph_t *graph) {
  node_t *curr = graph->head;
  while (curr != NULL) {
    node_t *next = curr->next;
    free(curr);
    curr = next;
  }
  free(graph);
}

int main() {
  graph_t *graph = malloc(sizeof(graph_t));
  graph->head = NULL;
  graph->size = 0;

  // Add nodes to the graph
  add_node(graph, 1);
  add_node(graph, 2);
  add_node(graph, 3);

  // Print the graph
  print_graph(graph);

  // Free the graph
  free_graph(graph);

  return 0;
}