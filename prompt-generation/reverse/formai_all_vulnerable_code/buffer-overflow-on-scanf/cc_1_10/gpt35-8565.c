//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 10

struct circuit_node {
    int node_num;
    float voltage;
    float current;
    float capacitance;
    float inductance;
};

float capacitance_flow(struct circuit_node nodes[], int node1, int node2, float time_step) {
    float current_flow = (nodes[node1].voltage - nodes[node2].voltage) / nodes[node1].capacitance;
    nodes[node1].current -= current_flow * time_step;
    nodes[node2].current += current_flow * time_step;
    return current_flow;
}

float inductance_flow(struct circuit_node nodes[], int node1, int node2, float time_step) {
    float current_flow = (nodes[node1].voltage - nodes[node2].voltage) / nodes[node1].inductance;
    nodes[node1].current -= current_flow * time_step;
    nodes[node2].current += current_flow * time_step;
    return current_flow;
}

void simulate_circuit(struct circuit_node nodes[], int num_nodes, float time_step, int num_steps) {
    for(int i = 0; i < num_steps; i++) {
        printf("Time Step: %d\n", i + 1);
        for(int j = 0; j < num_nodes; j++) {
            printf("Node %d: Voltage = %.2fV, Current = %.2fA\n", nodes[j].node_num, nodes[j].voltage, nodes[j].current);
            if(j < num_nodes - 1) {
                float current_flow = capacitance_flow(nodes, j, j+1, time_step);
                inductance_flow(nodes, j, j+1, time_step);
                printf("    Capacitance Flow = %.2fA\n", current_flow);
            }
        }
        printf("\n");
    }
}

int main() {
    struct circuit_node nodes[MAX_NODES] = {0};
    int num_nodes, num_steps;
    float time_step;
    printf("Enter the number of circuit nodes (maximum %d): ", MAX_NODES);
    scanf("%d", &num_nodes);
    for(int i = 0; i < num_nodes; i++) {
        printf("Enter voltage (V) for node %d: ", i+1);
        scanf("%f", &nodes[i].voltage);
        printf("Enter capacitance (F) for node %d: ", i+1);
        scanf("%f", &nodes[i].capacitance);
        printf("Enter inductance (H) for node %d: ", i+1);
        scanf("%f", &nodes[i].inductance);
        nodes[i].node_num = i+1;
    }
    printf("Enter the time step (s): ");
    scanf("%f", &time_step);
    printf("Enter the number of simulation steps: ");
    scanf("%d", &num_steps);
    printf("\nStarting Circuit Simulation...\n\n");
    simulate_circuit(nodes, num_nodes, time_step, num_steps);
    return 0;
}