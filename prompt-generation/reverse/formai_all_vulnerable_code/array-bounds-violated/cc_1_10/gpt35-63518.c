//FormAI DATASET v1.0 Category: Graph representation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void dfs(int vertex, int numVertices) {
  visited[vertex] = 1;
  printf("Vertex %d visited.\n", vertex);

  for(int i = 0; i < numVertices; i++) {
    if(adjMatrix[vertex][i] && !visited[i]) {
      dfs(i, numVertices);
    }
  }
}

int main() {
  int numVertices, numEdges;
  printf("Enter the number of vertices: ");
  scanf("%d", &numVertices);
  
  printf("Enter the number of edges: ");
  scanf("%d", &numEdges);

  for(int i = 0; i < numVertices; i++) {
    visited[i] = 0;
    for(int j = 0; j < numVertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }

  printf("Enter the edges:\n");
  for(int i = 0; i < numEdges; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
  }

  printf("Graph representation (Adjacency Matrix):\n");
  for(int i = 0; i < numVertices; i++) {
    for(int j = 0; j < numVertices; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }

  printf("Depth First Traversal (DFS) of the graph:\n");
  dfs(0, numVertices);

  return 0;
}