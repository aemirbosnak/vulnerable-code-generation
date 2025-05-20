//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_COLORS 10

// Structure to represent a node in the graph
typedef struct node {
  int id;
  int color;
  struct node* next;
} node_t;

// Structure to represent a graph
typedef struct graph {
  int num_nodes;
  int num_edges;
  node_t* nodes[MAX_NODES];
} graph_t;

// Function to create a new node
node_t* create_node(int id, int color) {
  node_t* new_node = malloc(sizeof(node_t));
  new_node->id = id;
  new_node->color = color;
  new_node->next = NULL;
  return new_node;
}

// Function to create a new graph
graph_t* create_graph(int num_nodes, int num_edges) {
  graph_t* new_graph = malloc(sizeof(graph_t));
  new_graph->num_nodes = num_nodes;
  new_graph->num_edges = num_edges;
  for (int i = 0; i < num_nodes; i++) {
    new_graph->nodes[i] = NULL;
  }
  return new_graph;
}

// Function to add an edge to the graph
void add_edge(graph_t* graph, int src, int dest) {
  node_t* new_node = create_node(dest, 0);
  new_node->next = graph->nodes[src];
  graph->nodes[src] = new_node;
}

// Function to color a node
void color_node(graph_t* graph, int node, int color) {
  node_t* current_node = graph->nodes[node];
  while (current_node != NULL) {
    current_node->color = color;
    current_node = current_node->next;
  }
}

// Function to check if a node is safe to color
int is_safe_to_color(graph_t* graph, int node, int color) {
  node_t* current_node = graph->nodes[node];
  while (current_node != NULL) {
    if (current_node->color == color) {
      return 0;
    }
    current_node = current_node->next;
  }
  return 1;
}

// Function to color the graph
void color_graph(graph_t* graph) {
  int num_colors = 1;
  for (int i = 0; i < graph->num_nodes; i++) {
    int color = 1;
    while (!is_safe_to_color(graph, i, color)) {
      color++;
    }
    color_node(graph, i, color);
    num_colors = color;
  }
  printf("The graph is colored with %d colors.\n", num_colors);
}

int main() {
  graph_t* graph = create_graph(5, 6);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 3);
  add_edge(graph, 1, 4);
  add_edge(graph, 2, 4);
  add_edge(graph, 3, 4);
  color_graph(graph);
  return 0;
}