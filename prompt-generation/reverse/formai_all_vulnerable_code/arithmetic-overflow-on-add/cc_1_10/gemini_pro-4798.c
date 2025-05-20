//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define the data structure for a vertex
typedef struct vertex {
  int value;  // The value of the vertex
  int degree;  // The number of edges connected to the vertex
  struct vertex *next;  // The next vertex in the adjacency list
} vertex;

// Define the data structure for an edge
typedef struct edge {
  int weight;  // The weight of the edge
  vertex *destination;  // The destination vertex of the edge
  struct edge *next;  // The next edge in the adjacency list
} edge;

// Define the data structure for a graph
typedef struct graph {
  int num_vertices;  // The number of vertices in the graph
  int num_edges;  // The number of edges in the graph
  vertex *vertices;  // The array of vertices
  edge *edges;  // The array of edges
} graph;

// Create a new graph
graph *create_graph() {
  graph *g = malloc(sizeof(graph));
  g->num_vertices = 0;
  g->num_edges = 0;
  g->vertices = NULL;
  g->edges = NULL;
  return g;
}

// Add a vertex to the graph
void add_vertex(graph *g, int value) {
  vertex *v = malloc(sizeof(vertex));
  v->value = value;
  v->degree = 0;
  v->next = g->vertices;
  g->vertices = v;
  g->num_vertices++;
}

// Add an edge to the graph
void add_edge(graph *g, vertex *source, vertex *destination, int weight) {
  edge *e = malloc(sizeof(edge));
  e->weight = weight;
  e->destination = destination;
  e->next = source->next;
  source->next = e;
  destination->degree++;
  g->num_edges++;
}

// Print the graph
void print_graph(graph *g) {
  printf("Vertices:\n");
  for (vertex *v = g->vertices; v != NULL; v = v->next) {
    printf("%d ", v->value);
  }
  printf("\n");

  printf("Edges:\n");
  for (vertex *v = g->vertices; v != NULL; v = v->next) {
    for (edge *e = v->next; e != NULL; e = e->next) {
      printf("%d -> %d (weight = %d)\n", v->value, e->destination->value, e->weight);
    }
  }
}

// Free the graph
void free_graph(graph *g) {
  for (vertex *v = g->vertices; v != NULL; v = v->next) {
    for (edge *e = v->next; e != NULL; e = e->next) {
      free(e);
    }
    free(v);
  }
  free(g);
}

// Driver code
int main() {
  // Create a new graph
  graph *g = create_graph();

  // Add some vertices to the graph
  add_vertex(g, 1);
  add_vertex(g, 2);
  add_vertex(g, 3);
  add_vertex(g, 4);
  add_vertex(g, 5);

  // Add some edges to the graph
  add_edge(g, g->vertices + 0, g->vertices + 1, 1);
  add_edge(g, g->vertices + 0, g->vertices + 2, 2);
  add_edge(g, g->vertices + 1, g->vertices + 2, 3);
  add_edge(g, g->vertices + 1, g->vertices + 4, 4);
  add_edge(g, g->vertices + 2, g->vertices + 4, 5);
  add_edge(g, g->vertices + 3, g->vertices + 4, 6);

  // Print the graph
  print_graph(g);

  // Free the graph
  free_graph(g);

  return 0;
}