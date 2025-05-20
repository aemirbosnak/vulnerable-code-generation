//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int n = 0; // number of nodes in the graph
int adj[MAX_NODES][MAX_NODES]; // adjacency matrix
int color[MAX_NODES]; // stores the color of each node

// function to check if two nodes can have same color
int isSafe(int node, int c) {
  for(int i=0; i<n; i++) {
    if(adj[node][i] && color[i]==c) {
      return 0;
    }
  }
  return 1;
}

// recursive function to assign colors to nodes
void colorGraph(int node) {
  if(node == n) { // all nodes have been colored
    printf("The coloring of the graph is: ");
    for(int i=0; i<n; i++) {
      printf("%d ", color[i]);
    }
    printf("\n");
    return;
  }
  for(int c=1; c<=n; c++) { // try all possible colors
    if(isSafe(node, c)) {
      color[node] = c; // assign color to the node
      colorGraph(node+1); // try coloring the next node
      color[node] = 0; // backtrack and remove the color from the node
    }
  }
}

int main() {
  printf("Enter the number of nodes in the graph: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix of the graph:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      scanf("%d", &adj[i][j]);
    }
  }

  colorGraph(0); // start with the first node

  return 0;
}