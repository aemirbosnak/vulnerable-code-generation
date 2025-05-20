//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

int n, m;
int graph[N][N];
int colors[N];
int visited[N];

int valid_color(int v, int color) {
  for (int i = 0; i < n; i++) {
    if (graph[v][i] && colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

int solve(int v, int k) {
  if (v == n) {
    return 1;
  }

  for (int color = 0; color < k; color++) {
    if (valid_color(v, color)) {
      colors[v] = color;
      if (solve(v + 1, k)) {
        return 1;
      }
    }
  }

  return 0;
}

int main() {
  printf("Enter the number of vertices and edges: ");
  scanf("%d %d", &n, &m);

  printf("Enter the edges: ");
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    graph[u][v] = 1;
    graph[v][u] = 1;
  }

  printf("Enter the number of colors: ");
  int k;
  scanf("%d", &k);

  if (solve(0, k)) {
    printf("The graph is colorable with %d colors.\n", k);
  } else {
    printf("The graph is not colorable with %d colors.\n", k);
  }

  return 0;
}