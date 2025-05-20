//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

int main(void) {
  int numOfNodes, graph[MAX_NODES][MAX_NODES], i, j;

  printf("How many nodes do you want to map? ");
  scanf("%d", &numOfNodes);

  printf("\n");

  if (numOfNodes > MAX_NODES) {
    printf("Sorry, cannot map more than %d nodes!", MAX_NODES); // Just kidding, of course I can! I'm a mapper program!
    return 0;
  }

  printf("Mapping your network topology...\n");

  // We will generate a random graph for demonstration purposes
  for (i = 0; i < numOfNodes; i++) {
    for (j = 0; j < numOfNodes; j++) {
      if (i == j) {
        graph[i][j] = 0;
      } else {
        graph[i][j] = rand() % 2; // 50/50 chance of connecting two nodes
      }
    }
  }

  // Display the graph to the user
  printf("\n");

  for (i = 0; i < numOfNodes; i++) {
    for (j = 0; j < numOfNodes; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  
  // Let's count the number of connections each node has
  int connections[numOfNodes];

  for (i = 0; i < numOfNodes; i++) {
    int count = 0;
    for (j = 0; j < numOfNodes; j++) {
      if (graph[i][j] == 1) {
        count++;
      }
    }
    connections[i] = count;
  }

  // Display the number of connections for each node
  for (i = 0; i < numOfNodes; i++) {
    printf("Node %d has %d connections.\n", i+1, connections[i]);
  }

  return 0;
}