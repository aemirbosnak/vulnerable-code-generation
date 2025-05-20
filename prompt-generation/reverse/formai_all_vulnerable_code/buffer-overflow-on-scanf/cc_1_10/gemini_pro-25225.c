//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100
#define MAX_C 10

int adj[MAX_V][MAX_V];
int colors[MAX_V];
int n, m;

int get_color(int v) {
  for (int i = 0; i < n; i++) {
    if (adj[v][i] && colors[i] != 0) {
      return colors[i];
    }
  }
  return 0;
}

int can_color(int v, int color) {
  for (int i = 0; i < n; i++) {
    if (adj[v][i] && colors[i] == color) {
      return 0;
    }
  }
  return 1;
}

int color_graph(int v) {
  if (v == n) {
    return 1;
  }

  int color = get_color(v);
  for (int i = 1; i <= m; i++) {
    if (can_color(v, i)) {
      colors[v] = i;
      if (color_graph(v + 1)) {
        return 1;
      }
      colors[v] = 0;
    }
  }
  return 0;
}

int main() {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &adj[i][j]);
    }
  }

  if (color_graph(0)) {
    for (int i = 0; i < n; i++) {
      printf("%d ", colors[i]);
    }
    printf("\n");
  } else {
    printf("No solution\n");
  }

  return 0;
}