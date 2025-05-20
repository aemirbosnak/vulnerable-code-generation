//Code Llama-13B DATASET v1.0 Category: Graph Coloring Problem ; Style: beginner-friendly
// Graph Coloring Problem Example Program

#include <stdio.h>

// Structure to represent a graph
typedef struct {
  int vertices; // Number of vertices in the graph
  int edges;   // Number of edges in the graph
  int** matrix; // Adjacency matrix representation of the graph
} Graph;

// Function to initialize a graph
void init_graph(Graph* g, int vertices, int edges) {
  g->vertices = vertices;
  g->edges = edges;
  g->matrix = (int**)malloc(vertices * sizeof(int*));
  for (int i = 0; i < vertices; i++) {
    g->matrix[i] = (int*)malloc(vertices * sizeof(int));
    for (int j = 0; j < vertices; j++) {
      g->matrix[i][j] = 0;
    }
  }
}

// Function to add an edge to a graph
void add_edge(Graph* g, int src, int dest) {
  g->matrix[src][dest] = 1;
  g->matrix[dest][src] = 1;
}

// Function to print a graph
void print_graph(Graph* g) {
  for (int i = 0; i < g->vertices; i++) {
    for (int j = 0; j < g->vertices; j++) {
      printf("%d ", g->matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to find the minimum degree of a graph
int min_degree(Graph* g) {
  int min_degree = 100;
  for (int i = 0; i < g->vertices; i++) {
    int degree = 0;
    for (int j = 0; j < g->vertices; j++) {
      degree += g->matrix[i][j];
    }
    if (degree < min_degree) {
      min_degree = degree;
    }
  }
  return min_degree;
}

// Function to find the maximum degree of a graph
int max_degree(Graph* g) {
  int max_degree = 0;
  for (int i = 0; i < g->vertices; i++) {
    int degree = 0;
    for (int j = 0; j < g->vertices; j++) {
      degree += g->matrix[i][j];
    }
    if (degree > max_degree) {
      max_degree = degree;
    }
  }
  return max_degree;
}

// Function to find the minimum degree of a graph using BFS
int min_degree_bfs(Graph* g) {
  int min_degree = 100;
  for (int i = 0; i < g->vertices; i++) {
    int degree = 0;
    for (int j = 0; j < g->vertices; j++) {
      if (g->matrix[i][j] == 1) {
        degree++;
      }
    }
    if (degree < min_degree) {
      min_degree = degree;
    }
  }
  return min_degree;
}

// Function to find the maximum degree of a graph using BFS
int max_degree_bfs(Graph* g) {
  int max_degree = 0;
  for (int i = 0; i < g->vertices; i++) {
    int degree = 0;
    for (int j = 0; j < g->vertices; j++) {
      if (g->matrix[i][j] == 1) {
        degree++;
      }
    }
    if (degree > max_degree) {
      max_degree = degree;
    }
  }
  return max_degree;
}

// Function to print the degree distribution of a graph
void print_degree_distribution(Graph* g) {
  int* degrees = (int*)malloc(g->vertices * sizeof(int));
  for (int i = 0; i < g->vertices; i++) {
    int degree = 0;
    for (int j = 0; j < g->vertices; j++) {
      degree += g->matrix[i][j];
    }
    degrees[i] = degree;
  }
  for (int i = 0; i < g->vertices; i++) {
    printf("%d ", degrees[i]);
  }
  printf("\n");
}

int main() {
  // Create a graph with 5 vertices and 5 edges
  Graph* g = (Graph*)malloc(sizeof(Graph));
  init_graph(g, 5, 5);
  add_edge(g, 0, 1);
  add_edge(g, 0, 2);
  add_edge(g, 1, 2);
  add_edge(g, 1, 3);
  add_edge(g, 2, 3);
  add_edge(g, 3, 4);

  // Print the graph
  printf("Graph:\n");
  print_graph(g);

  // Print the minimum degree of the graph
  printf("Minimum degree: %d\n", min_degree(g));

  // Print the maximum degree of the graph
  printf("Maximum degree: %d\n", max_degree(g));

  // Print the minimum degree of the graph using BFS
  printf("Minimum degree using BFS: %d\n", min_degree_bfs(g));

  // Print the maximum degree of the graph using BFS
  printf("Maximum degree using BFS: %d\n", max_degree_bfs(g));

  // Print the degree distribution of the graph
  printf("Degree distribution:\n");
  print_degree_distribution(g);

  return 0;
}