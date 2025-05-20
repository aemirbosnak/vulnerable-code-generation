//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Graph coloring problem */

/* Graph represented as an adjacency matrix */
int graph[100][100];
int n, m;  /* Number of nodes and edges */

/* Colors represented as an array of integers */
int colors[100];

/* Flag to indicate if the graph is colored */
int colored;

/* Function to check if the graph is colored */
int is_colored() {
  for (int i = 0; i < n; i++) {
    if (colors[i] == -1) {
      return 0;
    }
  }
  return 1;
}

/* Function to check if the graph is valid */
int is_valid() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] == 1 && colors[i] == colors[j]) {
        return 0;
      }
    }
  }
  return 1;
}

/* Function to color the graph */
int color_graph(int node) {
  if (node == n) {
    if (is_valid()) {
      colored = 1;
      return 1;
    } else {
      return 0;
    }
  }

  for (int i = 0; i < m; i++) {
    if (graph[node][i] == 1) {
      if (colors[i] == -1) {
        colors[i] = colors[node];
        if (color_graph(node + 1)) {
          return 1;
        }
        colors[i] = -1;
      }
    }
  }

  return 0;
}

/* Function to print the graph */
void print_graph() {
  printf("Graph:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}

/* Function to print the colors */
void print_colors() {
  printf("Colors:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", colors[i]);
  }
  printf("\n");
}

/* Main function */
int main() {
  /* Get the input */
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  printf("Enter the number of edges: ");
  scanf("%d", &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    printf("Enter the edge (u, v): ");
    scanf("%d %d", &u, &v);
    graph[u][v] = 1;
    graph[v][u] = 1;
  }

  /* Initialize the colors */
  for (int i = 0; i < n; i++) {
    colors[i] = -1;
  }

  /* Color the graph */
  colored = 0;
  color_graph(0);

  /* Print the graph and the colors */
  print_graph();
  print_colors();

  /* Check if the graph is colored */
  if (colored) {
    printf("The graph is colored\n");
  } else {
    printf("The graph cannot be colored\n");
  }

  return 0;
}