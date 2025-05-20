//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: cheerful
// Graph representation example program in a cheerful style
#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct {
  int num_vertices;
  int num_edges;
  int** edges;
} Graph;

// Add vertex to graph
void add_vertex(Graph* graph) {
  graph->num_vertices++;
  graph->edges = realloc(graph->edges, graph->num_vertices * sizeof(int*));
  graph->edges[graph->num_vertices - 1] = malloc(graph->num_vertices * sizeof(int));
  for (int i = 0; i < graph->num_vertices; i++) {
    graph->edges[graph->num_vertices - 1][i] = 0;
  }
}

// Add edge to graph
void add_edge(Graph* graph, int vertex1, int vertex2) {
  graph->edges[vertex1][vertex2] = 1;
  graph->edges[vertex2][vertex1] = 1;
  graph->num_edges++;
}

// Remove vertex from graph
void remove_vertex(Graph* graph, int vertex) {
  for (int i = 0; i < graph->num_vertices; i++) {
    graph->edges[i][vertex] = 0;
    graph->edges[vertex][i] = 0;
  }
  free(graph->edges[vertex]);
  for (int i = vertex; i < graph->num_vertices - 1; i++) {
    graph->edges[i] = graph->edges[i + 1];
  }
  graph->num_vertices--;
  graph->num_edges -= graph->edges[vertex][vertex];
}

// Remove edge from graph
void remove_edge(Graph* graph, int vertex1, int vertex2) {
  graph->edges[vertex1][vertex2] = 0;
  graph->edges[vertex2][vertex1] = 0;
  graph->num_edges--;
}

// Print graph
void print_graph(Graph* graph) {
  printf("Graph:\n");
  for (int i = 0; i < graph->num_vertices; i++) {
    for (int j = 0; j < graph->num_vertices; j++) {
      if (graph->edges[i][j] == 1) {
        printf("%d -> %d\n", i, j);
      }
    }
  }
}

int main() {
  Graph* graph = malloc(sizeof(Graph));
  graph->num_vertices = 0;
  graph->num_edges = 0;
  graph->edges = NULL;

  add_vertex(graph);
  add_vertex(graph);
  add_vertex(graph);
  add_edge(graph, 0, 1);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 0);
  print_graph(graph);

  remove_vertex(graph, 1);
  print_graph(graph);

  remove_edge(graph, 0, 2);
  print_graph(graph);

  free(graph->edges);
  free(graph);
  return 0;
}