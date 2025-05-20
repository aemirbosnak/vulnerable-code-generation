//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: creative
// Graph representation example program in a creative style
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a graph
typedef struct {
  int num_vertices;
  int num_edges;
  int* edges;
} Graph;

// Function to create a new graph
Graph* create_graph(int num_vertices, int num_edges) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;
  graph->num_edges = num_edges;
  graph->edges = (int*)malloc(num_edges * sizeof(int));
  return graph;
}

// Function to add an edge to a graph
void add_edge(Graph* graph, int source, int destination) {
  graph->edges[graph->num_edges] = destination;
  graph->num_edges++;
}

// Function to print a graph
void print_graph(Graph* graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("Vertex %d: ", i);
    for (int j = 0; j < graph->num_edges; j++) {
      if (graph->edges[j] == i) {
        printf("%d ", j);
      }
    }
    printf("\n");
  }
}

// Driver code
int main() {
  Graph* graph = create_graph(5, 6);
  add_edge(graph, 0, 1);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 4);
  add_edge(graph, 4, 0);
  add_edge(graph, 1, 4);
  print_graph(graph);
  return 0;
}