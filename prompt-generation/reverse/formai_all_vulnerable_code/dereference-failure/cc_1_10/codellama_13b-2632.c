//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Graph structure
struct Graph {
  int V; // Number of vertices
  int E; // Number of edges
  int** adj; // Adjacency matrix
};

// Creates a new graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->adj = (int**)malloc(V * sizeof(int*));
  for (int i = 0; i < V; i++) {
    graph->adj[i] = (int*)malloc(V * sizeof(int));
  }
  return graph;
}

// Adds an edge to the graph
void addEdge(struct Graph* graph, int v1, int v2) {
  graph->adj[v1][v2] = 1;
  graph->adj[v2][v1] = 1;
}

// Checks if a graph is bipartite
int isBipartite(struct Graph* graph) {
  int* color = (int*)malloc(graph->V * sizeof(int));
  for (int i = 0; i < graph->V; i++) {
    color[i] = 0;
  }
  for (int i = 0; i < graph->V; i++) {
    if (color[i] == 0) {
      if (!dfs(graph, i, 1, color)) {
        return 0;
      }
    }
  }
  return 1;
}

// DFS traversal for checking bipartiteness
int dfs(struct Graph* graph, int v, int c, int* color) {
  color[v] = c;
  for (int i = 0; i < graph->V; i++) {
    if (graph->adj[v][i] && color[i] == color[v]) {
      return 0;
    }
    if (graph->adj[v][i] && color[i] == 0 && !dfs(graph, i, -c, color)) {
      return 0;
    }
  }
  return 1;
}

int main() {
  struct Graph* graph = createGraph(4, 4);
  addEdge(graph, 0, 1);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 0);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 0);

  if (isBipartite(graph)) {
    printf("Graph is bipartite\n");
  } else {
    printf("Graph is not bipartite\n");
  }

  return 0;
}