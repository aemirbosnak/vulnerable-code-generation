//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ken Thompson
#include<stdio.h>
#define MAX 50

int G[MAX][MAX], color[MAX], n;

void printSolution() {
  printf("The assigned colors are:\n");
  for (int i = 0; i < n; i++) {
    printf("Node %d: Color %d\n", i+1, color[i]);
  }
}

int isSafe(int node, int c) {
  for (int i = 0; i < n; i++) {
    if (G[node][i] && c == color[i]) {
      return 0;
    }
  }
  return 1;
}

int graphColoring(int node) {
  if (node == n) {
    return 1;
  }
  for (int i = 1; i <= n; i++) {
    if (isSafe(node, i)) {
      color[node] = i;
      if (graphColoring(node+1)) {
        return 1;
      }
      color[node] = 0;
    }
  }
  return 0;
}

void input() {
  printf("Enter number of nodes: ");
  scanf("%d", &n);
  printf("Enter Adjacency Matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &G[i][j]);
    }
  }
}

int main() {
  input();
  if (graphColoring(0)) {
    printSolution();
  }
  else {
    printf("Solution does not exist\n");
  }
  return 0;
}