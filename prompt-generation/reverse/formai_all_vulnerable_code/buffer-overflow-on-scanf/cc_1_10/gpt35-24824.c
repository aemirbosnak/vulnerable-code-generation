//FormAI DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>

int main() {
  // Let us create a graph for demonstration purpose
  int n = 6; // number of vertices
  int m = 7; // number of edges

  // Adjacency List Representation
  int V = n;
  int E = m;
  int head[V+1], nxt[E+1], to[E+1];
  int idx = 0;
  for (int i = 1; i <= V; i++) head[i] = -1;
  for (int i = 1; i <= E; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      nxt[idx] = head[u], to[idx] = v, head[u] = idx++;
      nxt[idx] = head[v], to[idx] = u, head[v] = idx++;
  }

  // Print adjacency list representation of graph
  printf("Adjacency List Representation:\n");
  for (int i = 1; i <= V; i++) {
      printf("%d: ", i);
      for (int j = head[i]; j != -1; j = nxt[j]) printf("%d ", to[j]);
      printf("\n");
  }

  // Adjacency Matrix Representation
  int graph[V+1][V+1];
  for (int i = 1; i <= V; i++)
    for (int j = 1; j <= V; j++)
      graph[i][j] = 0;
  for (int i = 1; i <= E; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      graph[u][v] = graph[v][u] = 1;
  }

  // Print adjacency matrix representation of graph
  printf("\nAdjacency Matrix Representation:\n");
  for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= V; j++) {
          printf("%d ", graph[i][j]);
      }
      printf("\n");
  }

  return 0;
}