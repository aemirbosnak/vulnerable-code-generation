//Code Llama-13B DATASET v1.0 Category: Classical Circuit Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_GATES 100
#define MAX_WIRES 100

typedef struct {
  int id;
  int input[2];
  int output;
  int type; // 0 for AND, 1 for OR, 2 for NOT
} Gate;

typedef struct {
  int id;
  int value;
} Wire;

void init_circuit(int n_gates, int n_wires, Gate* gates, Wire* wires) {
  srand(time(NULL));
  for (int i = 0; i < n_gates; i++) {
    gates[i].id = i;
    gates[i].type = rand() % 3;
    gates[i].input[0] = rand() % n_wires;
    gates[i].input[1] = rand() % n_wires;
    gates[i].output = rand() % n_wires;
  }
  for (int i = 0; i < n_wires; i++) {
    wires[i].id = i;
    wires[i].value = rand() % 2;
  }
}

void simulate_circuit(int n_gates, int n_wires, Gate* gates, Wire* wires) {
  for (int i = 0; i < n_gates; i++) {
    if (gates[i].type == 0) { // AND
      wires[gates[i].output].value = wires[gates[i].input[0]].value & wires[gates[i].input[1]].value;
    } else if (gates[i].type == 1) { // OR
      wires[gates[i].output].value = wires[gates[i].input[0]].value | wires[gates[i].input[1]].value;
    } else { // NOT
      wires[gates[i].output].value = !wires[gates[i].input[0]].value;
    }
  }
}

int main() {
  int n_gates = 100;
  int n_wires = 100;
  Gate* gates = (Gate*)malloc(n_gates * sizeof(Gate));
  Wire* wires = (Wire*)malloc(n_wires * sizeof(Wire));
  init_circuit(n_gates, n_wires, gates, wires);
  simulate_circuit(n_gates, n_wires, gates, wires);
  for (int i = 0; i < n_wires; i++) {
    printf("Wire %d has value %d\n", wires[i].id, wires[i].value);
  }
  return 0;
}