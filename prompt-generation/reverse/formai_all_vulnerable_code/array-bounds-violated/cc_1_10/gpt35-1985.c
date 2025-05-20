//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include <stdio.h>

#define MAX 100

void graph_coloring(int, int [MAX][MAX], int);

int main() {
  int n, e, i, j, v1, v2;
  int graph[MAX][MAX];

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the number of edges: ");
  scanf("%d", &e);

  //initializing the graph
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
  }

  //getting the edges
  for (i = 0; i < e; i++) {
    printf("Enter the vertices of edge %d: ", i+1);
    scanf("%d%d", &v1, &v2);

    //adding edges to the graph
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
  }

  graph_coloring(n, graph, 0);

  return 0;
}

void graph_coloring(int n, int graph[MAX][MAX], int v) {
  int i, j, c;
  int color_count = n;
  int colored[n];

  // initializing the colors
  int colors[n];
  for (i = 0; i < n; i++) {
    colors[i] = 0;
  }

  if (v == n) {
    printf("Solution exists:\n");

    for (i = 0; i < n; i++) {
      printf("Vertex %d -> Color %d\n", i, colors[i]);
    }

    return;
  }

  // check possible colors for current vertex
  for (c = 1; c <= color_count; c++) {
    int ok = 1;

    for (i = 0; i < n; i++) {
      if (graph[v][i] && colors[i] == c) {
        ok = 0;
        break;
      }
    }

    // check next vertex if current color is invalid
    if (ok) {
      colors[v] = c;
      graph_coloring(n, graph, v+1);
      colors[v] = 0;
    }
  }
}