//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: sophisticated
// Graph representation in C
#include <stdio.h>
#include <stdlib.h>

// Structure for a graph node
struct node {
  int value;
  struct node* next;
};

// Structure for a graph
struct graph {
  int num_nodes;
  int num_edges;
  struct node** nodes;
};

// Function to create a new graph
struct graph* create_graph(int num_nodes) {
  struct graph* graph = malloc(sizeof(struct graph));
  graph->num_nodes = num_nodes;
  graph->num_edges = 0;
  graph->nodes = malloc(sizeof(struct node*) * num_nodes);
  for (int i = 0; i < num_nodes; i++) {
    graph->nodes[i] = NULL;
  }
  return graph;
}

// Function to add a new node to the graph
void add_node(struct graph* graph, int value) {
  struct node* node = malloc(sizeof(struct node));
  node->value = value;
  node->next = NULL;
  graph->nodes[graph->num_nodes] = node;
  graph->num_nodes++;
}

// Function to add a new edge between two nodes
void add_edge(struct graph* graph, int src, int dest) {
  struct node* src_node = graph->nodes[src];
  struct node* dest_node = graph->nodes[dest];
  src_node->next = dest_node;
  graph->num_edges++;
}

// Function to print the graph
void print_graph(struct graph* graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    struct node* node = graph->nodes[i];
    printf("%d: ", i);
    while (node != NULL) {
      printf("%d ", node->value);
      node = node->next;
    }
    printf("\n");
  }
}

// Example usage
int main() {
  struct graph* graph = create_graph(5);
  add_node(graph, 1);
  add_node(graph, 2);
  add_node(graph, 3);
  add_node(graph, 4);
  add_node(graph, 5);
  add_edge(graph, 0, 1);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);
  add_edge(graph, 4, 0);
  print_graph(graph);
  return 0;
}