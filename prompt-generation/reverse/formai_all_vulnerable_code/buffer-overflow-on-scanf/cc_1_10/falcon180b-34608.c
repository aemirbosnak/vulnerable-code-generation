//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_V 100
#define MAX_E 200
#define MAX_COLOR 7

int V, E;
int G[MAX_V][MAX_V];
int color[MAX_V];
int parent[MAX_V];
int visited[MAX_V];
int time_taken;

void init() {
  int i, j;
  for(i=0; i<MAX_V; i++) {
    for(j=0; j<MAX_V; j++) {
      G[i][j] = 0;
    }
  }
}

void add_edge(int u, int v) {
  G[u][v] = 1;
  G[v][u] = 1;
}

int dfs(int u) {
  int i, w;
  visited[u] = 1;
  for(i=0; i<MAX_V; i++) {
    if(G[u][i] == 1 && visited[i] == 0) {
      w = 1;
      while(w <= MAX_COLOR && color[i] == w) {
        w++;
      }
      color[i] = w;
      parent[i] = u;
      if(dfs(i) == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  int i, j, u, v;
  srand(time(NULL));
  printf("Enter the number of vertices: ");
  scanf("%d", &V);
  printf("Enter the number of edges: ");
  scanf("%d", &E);
  init();
  printf("Enter the edges (u v):\n");
  for(i=0; i<E; i++) {
    scanf("%d %d", &u, &v);
    add_edge(u, v);
  }
  memset(color, 0, sizeof(color));
  memset(visited, 0, sizeof(visited));
  memset(parent, -1, sizeof(parent));
  int start_time = clock();
  if(dfs(0) == 0) {
    printf("Graph cannot be colored with %d colors\n", MAX_COLOR);
  }
  else {
    printf("Vertex\tColor\n");
    for(i=0; i<V; i++) {
      printf("%d\t%d\n", i, color[i]);
    }
    time_taken = (clock() - start_time)/CLOCKS_PER_SEC;
    printf("Time taken: %.2f seconds\n", time_taken);
  }
  return 0;
}