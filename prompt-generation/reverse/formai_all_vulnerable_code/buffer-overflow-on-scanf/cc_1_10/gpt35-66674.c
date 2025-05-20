//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 1000
#define COLORS 3

int graph[MAX_NODES + 1][MAX_NODES + 1];
int nodeColors[MAX_NODES + 1];
int nodeDegrees[MAX_NODES + 1];
int nodes, edges;

void readInput() {
  scanf("%d %d", &nodes, &edges);

  int i, j;
  for(i = 1; i <= edges; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    graph[x][y] = graph[y][x] = 1;
    nodeDegrees[x]++; nodeDegrees[y]++;
  }
}

int isSafe(int nodeId, int color) {
  int j;
  for(j = 1; j <= nodes; j++) {
    if(graph[nodeId][j] && nodeColors[j] == color) return 0;
  }
  return 1;
}

int graphColor(int nodeId) {
  if(nodeId == nodes + 1) {
    return 1;
  }

  int i;
  for(i = 1; i <= COLORS; i++) {
    if(isSafe(nodeId, i)) {
      nodeColors[nodeId] = i;
      if(graphColor(nodeId + 1)) return 1;
      nodeColors[nodeId] = 0;
    }
  }

  return 0;
}

void printColors() {
  int i;
  for(i = 1; i <= nodes; i++) {
    printf("Node %d: Color %d\n", i, nodeColors[i]);
  }
}

int main() {
  readInput();

  if(graphColor(1)) {
    printf("Graph colorable with %d colors:\n", COLORS);
    printColors();
  }
  else {
    printf("Graph is not colorable with %d colors.\n", COLORS);
  }

  return 0;
}