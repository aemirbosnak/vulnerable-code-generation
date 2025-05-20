//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: real-life
// Graph representation example program in a real-life style

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a graph node
struct node {
  int value;
  struct node* next;
};

// Define a structure for a graph
struct graph {
  struct node** nodes;
  int num_nodes;
};

// Create a new graph with n nodes
struct graph* create_graph(int n) {
  struct graph* graph = malloc(sizeof(struct graph));
  graph->nodes = malloc(n * sizeof(struct node*));
  graph->num_nodes = n;

  for (int i = 0; i < n; i++) {
    graph->nodes[i] = malloc(sizeof(struct node));
    graph->nodes[i]->value = i;
    graph->nodes[i]->next = NULL;
  }

  return graph;
}

// Add an edge between two nodes in a graph
void add_edge(struct graph* graph, int node1, int node2) {
  struct node* current = graph->nodes[node1];
  struct node* new_node = malloc(sizeof(struct node));
  new_node->value = node2;
  new_node->next = NULL;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}

// Print the graph
void print_graph(struct graph* graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    struct node* current = graph->nodes[i];
    printf("Node %d: ", i);

    while (current != NULL) {
      printf("%d ", current->value);
      current = current->next;
    }

    printf("\n");
  }
}

int main() {
  // Create a graph with 4 nodes
  struct graph* graph = create_graph(4);

  // Add edges to the graph
  add_edge(graph, 0, 1);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 0);

  // Print the graph
  print_graph(graph);

  return 0;
}