//Gemma-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <pthread.h>

int graph[50][50];
int color[50];
int visited[50];

void dfs(int current) {
  visited[current] = 1;
  for (int i = 0; i < 50; i++) {
    if (graph[current][i] && !visited[i]) {
      color[i] = color[current] ^ 1;
      dfs(i);
    }
  }
}

int main() {
  int n, m, i, j;
  scanf("Enter the number of nodes and edges: ", &n);
  scanf("Enter the number of edges: ", &m);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      graph[i][j] = 0;
    }
  }

  for (i = 0; i < m; i++) {
    scanf("Enter the two nodes connected by an edge: ", &i);
    scanf("Enter the third node connected by an edge: ", &j);
    graph[i][j] = 1;
    graph[j][i] = 1;
  }

  for (i = 0; i < n; i++) {
    visited[i] = 0;
  }

  dfs(0);

  for (i = 0; i < n; i++) {
    printf("Node %d has color %d\n", i, color[i]);
  }

  return 0;
}