//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: mathematical
// Graph representation in a mathematical style

#include <stdio.h>

struct Graph {
  int V; // number of vertices
  int E; // number of edges
  int** adj; // adjacency matrix
};

// function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->adj = (int**)malloc(V * sizeof(int*));
  for (int i = 0; i < V; i++) {
    graph->adj[i] = (int*)malloc(V * sizeof(int));
    for (int j = 0; j < V; j++) {
      graph->adj[i][j] = 0;
    }
  }
  return graph;
}

// function to add an edge to a graph
void addEdge(struct Graph* graph, int v, int w) {
  graph->adj[v][w] = 1;
}

// function to print a graph
void printGraph(struct Graph* graph) {
  printf("Graph with %d vertices and %d edges\n", graph->V, graph->E);
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      if (graph->adj[i][j] == 1) {
        printf("%d -> %d\n", i, j);
      }
    }
  }
}

// driver code
int main() {
  struct Graph* graph = createGraph(5, 5);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  printGraph(graph);
  return 0;
}