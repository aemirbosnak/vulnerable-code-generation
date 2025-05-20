//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: shape shifting
/*
 * Unique C Graph representation example program in a shape shifting style
 */

#include <stdio.h>
#include <stdlib.h>

struct Graph {
  int num_vertices;
  int** adjacency_matrix;
};

struct Graph* create_graph(int num_vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->num_vertices = num_vertices;
  graph->adjacency_matrix = malloc(num_vertices * sizeof(int*));
  for (int i = 0; i < num_vertices; i++) {
    graph->adjacency_matrix[i] = malloc(num_vertices * sizeof(int));
    for (int j = 0; j < num_vertices; j++) {
      graph->adjacency_matrix[i][j] = 0;
    }
  }
  return graph;
}

void add_edge(struct Graph* graph, int vertex1, int vertex2) {
  graph->adjacency_matrix[vertex1][vertex2] = 1;
  graph->adjacency_matrix[vertex2][vertex1] = 1;
}

void remove_edge(struct Graph* graph, int vertex1, int vertex2) {
  graph->adjacency_matrix[vertex1][vertex2] = 0;
  graph->adjacency_matrix[vertex2][vertex1] = 0;
}

void print_graph(struct Graph* graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      printf("%d ", graph->adjacency_matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = create_graph(4);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 3);
  print_graph(graph);
  return 0;
}