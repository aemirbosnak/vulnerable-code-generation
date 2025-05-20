//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: brave
// Brave Graph Coloring Problem
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
  int num_vertices;
  int num_edges;
  int** adjacency_matrix;
} Graph;

bool is_safe(Graph* graph, int vertex, int color) {
  for (int i = 0; i < graph->num_vertices; i++) {
    if (graph->adjacency_matrix[vertex][i] == 1 && color == graph->adjacency_matrix[i][vertex]) {
      return false;
    }
  }
  return true;
}

bool graph_coloring(Graph* graph, int vertex, int color) {
  if (vertex == graph->num_vertices) {
    return true;
  }

  for (int i = 1; i <= MAX_COLORS; i++) {
    if (is_safe(graph, vertex, i)) {
      graph->adjacency_matrix[vertex][i] = 1;
      if (graph_coloring(graph, vertex + 1, color + 1)) {
        return true;
      }
      graph->adjacency_matrix[vertex][i] = 0;
    }
  }
  return false;
}

int main() {
  int num_vertices, num_edges;
  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);
  printf("Enter the number of edges: ");
  scanf("%d", &num_edges);

  Graph graph = {
    .num_vertices = num_vertices,
    .num_edges = num_edges,
    .adjacency_matrix = malloc(num_vertices * sizeof(int*))
  };

  for (int i = 0; i < num_vertices; i++) {
    graph.adjacency_matrix[i] = malloc(num_vertices * sizeof(int));
    memset(graph.adjacency_matrix[i], 0, num_vertices * sizeof(int));
  }

  for (int i = 0; i < num_edges; i++) {
    int vertex1, vertex2;
    printf("Enter the vertices of the edge (%d): ", i + 1);
    scanf("%d %d", &vertex1, &vertex2);
    graph.adjacency_matrix[vertex1 - 1][vertex2 - 1] = 1;
    graph.adjacency_matrix[vertex2 - 1][vertex1 - 1] = 1;
  }

  if (graph_coloring(&graph, 0, 1)) {
    printf("The graph can be colored using %d colors.\n", MAX_COLORS);
  } else {
    printf("The graph cannot be colored using %d colors.\n", MAX_COLORS);
  }

  for (int i = 0; i < num_vertices; i++) {
    free(graph.adjacency_matrix[i]);
  }
  free(graph.adjacency_matrix);

  return 0;
}