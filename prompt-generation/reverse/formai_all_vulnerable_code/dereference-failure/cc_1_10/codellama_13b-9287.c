//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

typedef struct {
  int vertex;
  int weight;
} Edge;

typedef struct {
  int num_vertices;
  int num_edges;
  Edge* edges;
  int* colors;
} Graph;

void print_graph(Graph* graph) {
  printf("Graph with %d vertices and %d edges\n", graph->num_vertices, graph->num_edges);
  for (int i = 0; i < graph->num_edges; i++) {
    printf("(%d, %d) ", graph->edges[i].vertex, graph->edges[i].weight);
  }
  printf("\n");
}

void color_graph(Graph* graph) {
  // Initialize colors array
  graph->colors = malloc(graph->num_vertices * sizeof(int));
  for (int i = 0; i < graph->num_vertices; i++) {
    graph->colors[i] = 0;
  }

  // Iterate over all edges and color the vertices
  for (int i = 0; i < graph->num_edges; i++) {
    int vertex1 = graph->edges[i].vertex;
    int vertex2 = graph->edges[i].weight;
    int color1 = graph->colors[vertex1];
    int color2 = graph->colors[vertex2];

    // If the colors of the two vertices are the same, then the graph is not colorable
    if (color1 == color2) {
      printf("Graph is not colorable.\n");
      return;
    }

    // If the colors are different, then the graph is colorable
    if (color1 != color2) {
      printf("Graph is colorable.\n");
      return;
    }
  }
}

int main() {
  // Create a graph with 4 vertices and 5 edges
  Graph graph = {4, 5, NULL, NULL};
  graph.edges = malloc(graph.num_edges * sizeof(Edge));
  graph.edges[0].vertex = 0;
  graph.edges[0].weight = 1;
  graph.edges[1].vertex = 0;
  graph.edges[1].weight = 2;
  graph.edges[2].vertex = 1;
  graph.edges[2].weight = 2;
  graph.edges[3].vertex = 1;
  graph.edges[3].weight = 3;
  graph.edges[4].vertex = 2;
  graph.edges[4].weight = 3;

  // Print the graph
  print_graph(&graph);

  // Color the graph
  color_graph(&graph);

  // Free memory
  free(graph.edges);
  free(graph.colors);

  return 0;
}