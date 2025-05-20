//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
  double v;
  double i;
  double r;
};

int main() {
  int numNodes = 4;
  struct Node *nodes = (struct Node *) malloc(numNodes * sizeof(struct Node));
  int **adjacencyMatrix = (int **) malloc(numNodes * sizeof(int *));
  for(int i = 0; i < numNodes; i++) {
    adjacencyMatrix[i] = (int *) malloc(numNodes * sizeof(int));
    for(int j = 0; j < numNodes; j++) {
      adjacencyMatrix[i][j] = 0;
    }
  }

  // Set up the circuit
  nodes[0].v = 5.0;
  nodes[0].i = 0.0;
  nodes[0].r = 100.0;
  nodes[1].v = 0.0;
  nodes[1].i = 0.0;
  nodes[1].r = 200.0;
  nodes[2].v = 0.0;
  nodes[2].i = 0.0;
  nodes[2].r = 300.0;
  nodes[3].v = 0.0;
  nodes[3].i = 0.0;
  nodes[3].r = 400.0;

  // Connect the circuit
  adjacencyMatrix[0][1] = 1;
  adjacencyMatrix[1][2] = 1;
  adjacencyMatrix[2][3] = 1;

  // Simulate the circuit
  for(int t = 0; t < 100; t++) {
    for(int i = 0; i < numNodes; i++) {
      if(adjacencyMatrix[i][i] == 1) {
        nodes[i].v -= 5.0;
      }
      for(int j = 0; j < numNodes; j++) {
        if(adjacencyMatrix[i][j] == 1) {
          nodes[i].i += (nodes[j].v - nodes[i].v) / nodes[j].r;
        }
      }
      nodes[i].v += (nodes[i].i * nodes[i].r);
    }
  }

  // Print the results
  for(int i = 0; i < numNodes; i++) {
    printf("Node %d: V = %.2f, I = %.2f\n", i, nodes[i].v, nodes[i].i);
  }

  free(nodes);
  for(int i = 0; i < numNodes; i++) {
    free(adjacencyMatrix[i]);
  }
  free(adjacencyMatrix);

  return 0;
}