//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int num_resistor, num_capacitor, num_inductor;  // parameters of the circuit
int num_node;  // number of nodes in the circuit
double time_step, end_time;  // simulation time parameters
double node_voltage[MAX_NODES];  // node voltages
double node_current[MAX_NODES];  // node currents

// data structure for a circuit element
typedef struct {
  int node1;  // first node of the element
  int node2;  // second node of the element
  char type;  // type of the element (R, C, or L)
  double value;  // value of the element (in ohms, farads, or henries)
} circuit_element;

circuit_element *circuit;  // array of circuit elements

// function to simulate the circuit and print the results
void simulate_circuit() {
  int i, j;
  double time = 0.0;
  
  // simulate the circuit
  while (time < end_time) {
    // calculate node currents
    for (i = 0; i < num_node; i++) {
      node_current[i] = 0.0;
      for (j = 0; j < num_resistor + num_capacitor + num_inductor; j++) {
        if (circuit[j].node1 == i) {
          node_current[i] += (node_voltage[i] - node_voltage[circuit[j].node2]) / circuit[j].value;
        }
        else if (circuit[j].node2 == i) {
          node_current[i] += (node_voltage[i] - node_voltage[circuit[j].node1]) / circuit[j].value;
        } 
      }
    }
    
    // update node voltages
    for (i = 1; i < num_node; i++) {
      node_voltage[i] += node_current[i] * time_step;
    }
    
    // print node voltages
    printf("Time: %f\n", time);
    for (i = 1; i < num_node; i++) {
      printf("V%d: %f\n", i, node_voltage[i]);
    }
    
    // increment time
    time += time_step;
  }
}

int main() {
  int i;
  
  // read circuit parameters
  printf("Enter the number of resistors, capacitors, and inductors in the circuit:\n");
  scanf("%d %d %d", &num_resistor, &num_capacitor, &num_inductor);
  
  printf("Enter the number of nodes in the circuit:\n");
  scanf("%d", &num_node);
  
  printf("Enter the simulation time parameters (time step and end time):\n");
  scanf("%lf %lf", &time_step, &end_time);
  
  // create circuit elements array
  circuit = (circuit_element*)malloc((num_resistor + num_capacitor + num_inductor) * sizeof(circuit_element));
  
  // read circuit elements
  printf("Enter the circuit elements:\n");
  for (i = 0; i < num_resistor + num_capacitor + num_inductor; i++) {
    scanf("%d %d %c %lf", &circuit[i].node1, &circuit[i].node2, &circuit[i].type, &circuit[i].value);
  }
  
  // initialize node voltages to 0
  for (i = 0; i < num_node; i++) {
    node_voltage[i] = 0.0;
  }
  
  // simulate the circuit and print the results
  simulate_circuit();
  
  // free allocated memory
  free(circuit);
  
  return 0;
}