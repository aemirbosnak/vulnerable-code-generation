//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: real-life
// Graph representation in a real-life style
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a node in the graph
typedef struct {
  int data;
  struct node* next;
} node;

// Define a struct for the graph
typedef struct {
  int num_vertices;
  int num_edges;
  node** adjacency_list;
} graph;

// Initialize the graph
graph* init_graph(int num_vertices) {
  graph* g = (graph*)malloc(sizeof(graph));
  g->num_vertices = num_vertices;
  g->num_edges = 0;
  g->adjacency_list = (node**)malloc(num_vertices * sizeof(node*));
  for (int i = 0; i < num_vertices; i++) {
    g->adjacency_list[i] = NULL;
  }
  return g;
}

// Add an edge to the graph
void add_edge(graph* g, int src, int dest) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = dest;
  new_node->next = g->adjacency_list[src];
  g->adjacency_list[src] = new_node;
  g->num_edges++;
}

// Print the graph
void print_graph(graph* g) {
  for (int i = 0; i < g->num_vertices; i++) {
    node* curr = g->adjacency_list[i];
    printf("%d: ", i);
    while (curr != NULL) {
      printf("%d ", curr->data);
      curr = curr->next;
    }
    printf("\n");
  }
}

int main() {
  // Create a graph with 5 vertices and 4 edges
  graph* g = init_graph(5);
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 2);
  add_edge(g, 1, 3);
  add_edge(g, 3, 4);

  // Print the graph
  print_graph(g);

  return 0;
}