//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 10000

int num_nodes, num_edges;
int edge_source[MAX_EDGES], edge_destination[MAX_EDGES];
double edge_weight[MAX_EDGES];
double node_voltage[MAX_NODES];
double node_current[MAX_NODES];
double node_resistance[MAX_NODES];
int ground_node;

int main() {
  // Read input data
  scanf("%d %d %d", &num_nodes, &num_edges, &ground_node);
  for (int i = 0; i < num_edges; i++) {
    scanf("%d %d %lf", &edge_source[i], &edge_destination[i], &edge_weight[i]);
  }

  // Initialize arrays
  for (int i = 0; i < num_nodes; i++) {
    node_voltage[i] = 0;
    node_current[i] = 0;
    node_resistance[i] = 0;
  }

  // Perform DC analysis
  for (int i = 0; i < num_edges; i++) {
    int source = edge_source[i];
    int dest = edge_destination[i];
    double weight = edge_weight[i];
    node_resistance[source] += weight;
    node_resistance[dest] += weight;
  }

  // Set current source value to 1
  node_current[ground_node] = 1;

  // Solve for node voltages
  for (int k = 0; k < 100; k++) {
    for (int i = 0; i < num_nodes; i++) {
      double sum = 0;
      for (int j = 0; j < num_edges; j++) {
        int source = edge_source[j];
        int dest = edge_destination[j];
        double weight = edge_weight[j];
        if (source == i) {
          sum += (node_voltage[i] - node_voltage[dest]) / weight;
        } else if (dest == i) {
          sum += (node_voltage[i] - node_voltage[source]) / weight;
        }
      }
      node_voltage[i] = (node_current[i] - sum) / node_resistance[i];
    }
  }

  // Print node voltages
  for (int i = 0; i < num_nodes; i++) {
    printf("Node %d: Voltage = %lf\n", i, node_voltage[i]);
  }

  return 0;
}