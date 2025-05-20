//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_INPUTS 10

typedef struct {
  int num_nodes;
  int num_inputs;
  int num_outputs;
  int nodes[MAX_NODES];
  int inputs[MAX_INPUTS];
  int outputs[MAX_INPUTS];
} circuit;

void print_circuit(circuit *c) {
  printf("Nodes: ");
  for (int i = 0; i < c->num_nodes; i++) {
    printf("%d ", c->nodes[i]);
  }
  printf("\n");

  printf("Inputs: ");
  for (int i = 0; i < c->num_inputs; i++) {
    printf("%d ", c->inputs[i]);
  }
  printf("\n");

  printf("Outputs: ");
  for (int i = 0; i < c->num_outputs; i++) {
    printf("%d ", c->outputs[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <circuit file>\n", argv[0]);
    return 1;
  }

  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  circuit c;
  fscanf(f, "%d %d %d", &c.num_nodes, &c.num_inputs, &c.num_outputs);

  for (int i = 0; i < c.num_nodes; i++) {
    fscanf(f, "%d", &c.nodes[i]);
  }

  for (int i = 0; i < c.num_inputs; i++) {
    fscanf(f, "%d", &c.inputs[i]);
  }

  for (int i = 0; i < c.num_outputs; i++) {
    fscanf(f, "%d", &c.outputs[i]);
  }

  fclose(f);

  print_circuit(&c);

  return 0;
}