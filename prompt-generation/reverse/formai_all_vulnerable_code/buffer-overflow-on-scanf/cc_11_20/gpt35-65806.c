//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 10

int main(int argc, char* argv[]) {
  int n;
  char node_labels[MAX_NODES][20];
  int node_coords[MAX_NODES][2];
  int edges[MAX_EDGES][2];
  
  printf("Enter number of nodes: ");
  scanf("%d", &n);
  
  printf("Enter node labels and coordinates (x y):\n");
  for (int i = 0; i < n; i++) {
    scanf("%s %d %d", node_labels[i], &node_coords[i][0], &node_coords[i][1]);
  }
  
  printf("Enter number of edges: ");
  int m;
  scanf("%d", &m);
  
  printf("Enter edge connections:\n");
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &edges[i][0], &edges[i][1]);
  }
  
  // Print adjacency matrix
  printf("\nAdjacency matrix:\n\n");
  printf("   ");
  for (int i = 0; i < n; i++) {
    printf("%s ", node_labels[i]);
  }
  printf("\n");
  
  for (int i = 0; i < n; i++) {
    printf("%s ", node_labels[i]);
    for (int j = 0; j < n; j++) {
      int connected = 0;
      for (int k = 0; k < m; k++) {
        if (edges[k][0] == i && edges[k][1] == j) {
          connected = 1;
          break;
        }
      }
      printf("%d  ", connected);
    }
    printf("\n");
  }
  
  // Draw network diagram
  printf("\nNetwork diagram:\n\n");
  for (int i = 0; i < n; i++) {
    printf("%s (%d, %d): ", node_labels[i], node_coords[i][0], node_coords[i][1]);
    for (int j = 0; j < m; j++) {
      if (edges[j][0] == i) {
        printf("%s ", node_labels[edges[j][1]]);
      } else if (edges[j][1] == i) {
        printf("%s ", node_labels[edges[j][0]]);
      }
    }
    printf("\n");
  }
  
  return 0;
}