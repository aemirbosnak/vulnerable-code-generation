//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20

int nodeCount = 0; // Number of nodes in our network
int connections[MAX_NODES][MAX_NODES]; // 2D array representing connection graph
int visitCount[MAX_NODES]; // Track which nodes have already been visited

// Function to create a random network topology
void generateTopology() {
  int i, j;
  for (i = 0; i < nodeCount; i++) {
    for (j = i+1; j < nodeCount; j++) {
      connections[i][j] = rand() % 2;
      connections[j][i] = connections[i][j]; // Ensure symmetry
    }
  }
}

// Function to print the matrix of connections
void printTopology() {
  int i, j;
  printf("Connection Matrix:\n");
  printf("    ");
  for (i = 0; i < nodeCount; i++) printf("%c ", 'A' + i);
  printf("\n");
  for (i = 0; i < nodeCount; i++) {
    printf("%c   ", 'A' + i);
    for (j = 0; j < nodeCount; j++) printf("%d ", connections[i][j]);
    printf("\n");
  }
}

// Function to run a depth-first search from a given node
void DFS(int node) {
  int i;
  visitCount[node] = 1;
  printf(" -> %c", 'A' + node);
  for (i = 0; i < nodeCount; i++) {
    if (connections[node][i] && !visitCount[i]) {
      DFS(i);
    }
  }
}

// Function to print a list of connected components
void printComponents() {
  int i, j;
  printf("Connected Components:\n");
  for (i = 0; i < nodeCount; i++) {
    if (!visitCount[i]) {
      printf("%c", 'A' + i);
      DFS(i);
      printf("\n");
    }
  }
}

// Main function to generate and display network topology
int main() {
  int i;
  printf("Enter number of nodes in network (up to %d): ", MAX_NODES);
  scanf("%d", &nodeCount);
  generateTopology();
  printTopology();
  printf("\n");
  printComponents();
  return 0;
}