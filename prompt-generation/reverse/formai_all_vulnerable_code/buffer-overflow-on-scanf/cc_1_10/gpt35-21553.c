//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

struct node {
  int node_number;
  int voltage;
};

struct component {
  char type;
  int node1, node2;
};

int main() {
  struct node nodes[MAX_NODES];
  struct component components[MAX_NODES];
  int num_nodes = 0, num_components = 0;
  char input;

  printf("Welcome to the Classical Circuit Simulator.\n");

  while (1) {
    printf("\nWhat would you like to do (a)dd component, (q)uit)? ");
    scanf(" %c", &input);

    if (input == 'q') {
      break;
    }

    if (input == 'a') {
      char type;
      int node1, node2;

      printf("\nComponent type ((r)esistor, (c)apacitor, (i)nductor): ");
      scanf(" %c", &type);

      printf("Node 1 number: ");
      scanf("%d", &node1);

      printf("Node 2 number: ");
      scanf("%d", &node2);

      nodes[node1].node_number = node1;
      nodes[node2].node_number = node2;

      components[num_components].type = type;
      components[num_components].node1 = node1;
      components[num_components].node2 = node2;

      num_components++;

      printf("Component added.\n");
    }
  }

  printf("\nCircuit summary:\n");
  printf("Number of nodes: %d\n", num_nodes);
  printf("Number of components: %d\n", num_components);

  for (int i = 0; i < num_components; i++) {
    struct component c = components[i];

    printf("\nComponent %d: Type: %c, Nodes: %d, %d\n", i+1, c.type, c.node1, c.node2);
  }

  return 0;
}