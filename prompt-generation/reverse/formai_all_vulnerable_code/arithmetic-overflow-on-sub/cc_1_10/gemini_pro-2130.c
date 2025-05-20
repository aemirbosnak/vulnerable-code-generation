//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Graph data structure
typedef struct graph {
  int num_vertices;
  int num_edges;
  int **adj_matrix;
} graph;

// Function to create a new graph
graph *create_graph(int num_vertices) {
  graph *g = (graph *)malloc(sizeof(graph));
  g->num_vertices = num_vertices;
  g->num_edges = 0;
  g->adj_matrix = (int **)malloc(num_vertices * sizeof(int *));
  for (int i = 0; i < num_vertices; i++) {
    g->adj_matrix[i] = (int *)malloc(num_vertices * sizeof(int));
    for (int j = 0; j < num_vertices; j++) {
      g->adj_matrix[i][j] = 0;
    }
  }
  return g;
}

// Function to add an edge to a graph
void add_edge(graph *g, int v1, int v2) {
  g->adj_matrix[v1][v2] = 1;
  g->adj_matrix[v2][v1] = 1;
  g->num_edges++;
}

// Function to print a graph
void print_graph(graph *g) {
  printf("Graph:\n");
  for (int i = 0; i < g->num_vertices; i++) {
    for (int j = 0; j < g->num_vertices; j++) {
      printf("%d ", g->adj_matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to check if a graph is bipartite
int is_bipartite(graph *g) {
  int *colors = (int *)malloc(g->num_vertices * sizeof(int));
  for (int i = 0; i < g->num_vertices; i++) {
    colors[i] = -1;
  }
  colors[0] = 0;
  for (int i = 0; i < g->num_vertices; i++) {
    if (colors[i] == -1) {
      if (!dfs(g, i, colors)) {
        return 0; // Graph is not bipartite
      }
    }
  }
  return 1; // Graph is bipartite
}

// Function to perform DFS and color the vertices
int dfs(graph *g, int v, int *colors) {
  for (int i = 0; i < g->num_vertices; i++) {
    if (g->adj_matrix[v][i] == 1) {
      if (colors[i] == -1) {
        colors[i] = 1 - colors[v];
        if (!dfs(g, i, colors)) {
          return 0;
        }
      } else if (colors[i] == colors[v]) {
        return 0; // Graph is not bipartite
      }
    }
  }
  return 1;
}

// Function to main
int main() {
  // Wow! Let's dive into the wonderful world of graphs!
  // Let's start by grabbing the number of vertices and edges in our graph:
  int num_vertices, num_edges;
  printf("Oho! How many vertices will be dancing in our graph? ");
  scanf("%d", &num_vertices);
  printf("Splendid! And how many edges will be connecting them? ");
  scanf("%d", &num_edges);

  // Time to create our very own graph!
  graph *g = create_graph(num_vertices);

  // Now, let's add those edges!
  int v1, v2;
  for (int i = 0; i < num_edges; i++) {
    printf("Connect the vertices (%d, %d): ", i + 1, i + 2);
    scanf("%d %d", &v1, &v2);
    add_edge(g, v1 - 1, v2 - 1);
  }

  // Ta-da! Our graph is ready to rock! Let's see what it looks like:
  print_graph(g);

  // Oh, but there's something special we want to know. Is this graph bipartite? Let's find out!
  int is_bipart = is_bipartite(g);

  // Drumroll, please! The result is...
  if (is_bipart) {
    printf("Hurray! Our graph is bipartite!\n");
  } else {
    printf("Oops! Our graph is not bipartite.\n");
  }

  return 0;
}