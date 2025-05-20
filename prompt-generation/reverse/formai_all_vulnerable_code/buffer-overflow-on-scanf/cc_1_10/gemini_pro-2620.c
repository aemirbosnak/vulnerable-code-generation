//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NMAX 100
#define COLORS 10

int n;
int graph[NMAX][NMAX];
int colors[NMAX];
bool used[COLORS];

bool is_safe(int v, int color) {
  for (int i = 0; i < n; i++) {
    if (graph[v][i] && colors[i] == color) {
      return false;
    }
  }
  return true;
}

bool graph_color(int v) {
  if (v == n) {
    return true;
  }
  for (int color = 1; color <= COLORS; color++) {
    if (!used[color] && is_safe(v, color)) {
      used[color] = true;
      colors[v] = color;
      if (graph_color(v + 1)) {
        return true;
      }
      used[color] = false;
    }
  }
  return false;
}

int main() {
  srand(time(NULL));
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = rand() % 2;
    }
  }
  for (int i = 0; i < n; i++) {
    colors[i] = 0;
    used[i] = false;
  }
  if (graph_color(0)) {
    printf("Graph coloring is possible.\n");
    for (int i = 0; i < n; i++) {
      printf("Vertex %d is colored with color %d.\n", i, colors[i]);
    }
  } else {
    printf("Graph coloring is not possible.\n");
  }
  return 0;
}