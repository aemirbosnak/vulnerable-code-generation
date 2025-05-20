//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: Romeo and Juliet
/*
 * Romeo and Juliet Data Structures Visualization
 */
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the graph
typedef struct Node {
  int id;
  int value;
  struct Node* next;
} Node;

// Structure for the graph
typedef struct Graph {
  Node** adjacency_list;
  int num_nodes;
  int num_edges;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_nodes) {
  Graph* graph = malloc(sizeof(Graph));
  graph->adjacency_list = malloc(num_nodes * sizeof(Node*));
  graph->num_nodes = num_nodes;
  graph->num_edges = 0;
  for (int i = 0; i < num_nodes; i++) {
    graph->adjacency_list[i] = NULL;
  }
  return graph;
}

// Function to add an edge to the graph
void add_edge(Graph* graph, int from, int to, int value) {
  Node* node = malloc(sizeof(Node));
  node->id = to;
  node->value = value;
  node->next = graph->adjacency_list[from];
  graph->adjacency_list[from] = node;
  graph->num_edges++;
}

// Function to print the graph
void print_graph(Graph* graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    Node* node = graph->adjacency_list[i];
    printf("%d: ", i);
    while (node != NULL) {
      printf("%d ", node->id);
      node = node->next;
    }
    printf("\n");
  }
}

// Function to free the graph
void free_graph(Graph* graph) {
  for (int i = 0; i < graph->num_nodes; i++) {
    Node* node = graph->adjacency_list[i];
    while (node != NULL) {
      Node* next = node->next;
      free(node);
      node = next;
    }
  }
  free(graph->adjacency_list);
  free(graph);
}

int main() {
  Graph* graph = create_graph(5);
  add_edge(graph, 0, 1, 10);
  add_edge(graph, 0, 2, 11);
  add_edge(graph, 1, 2, 12);
  add_edge(graph, 1, 3, 13);
  add_edge(graph, 2, 3, 14);
  add_edge(graph, 2, 4, 15);
  add_edge(graph, 3, 4, 16);
  print_graph(graph);
  free_graph(graph);
  return 0;
}