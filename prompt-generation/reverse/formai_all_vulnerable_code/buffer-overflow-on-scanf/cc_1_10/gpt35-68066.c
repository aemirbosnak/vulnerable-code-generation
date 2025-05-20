//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: complete
#include <stdio.h>
#include <math.h>

#define MAX_NODES 10
#define MAX_GATES 10

struct gate {
    int in_node1;
    int in_node2;
    int out_node;
    char type;
};

void simulate_circuit(struct gate gates[], int num_gates, double node_volt[]);

int main(void) {
    struct gate gates[MAX_GATES];
    int num_gates;
    printf("Enter the number of gates in the circuit (up to %d): ", MAX_GATES);
    scanf("%d", &num_gates);
    printf("Enter the gates in the format <input node 1> <input node 2> <output node> <gate type>:\n");
    for (int i = 0; i < num_gates; i++) {
        scanf("%d %d %d %c", &gates[i].in_node1, &gates[i].in_node2, &gates[i].out_node, &gates[i].type);
    }
    double node_volt[MAX_NODES];
    printf("Enter the initial voltages of the nodes:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        scanf("%lf", &node_volt[i]);
    }
    simulate_circuit(gates, num_gates, node_volt);
    printf("Final voltages of the nodes after simulating the circuit:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        printf("%lf\n", node_volt[i]);
    }
    return 0;
}

void simulate_circuit(struct gate gates[], int num_gates, double node_volt[]) {
    int max_iter = 1000;
    double tol = 1e-6;
    double prev_volt[MAX_NODES];
    for (int iter = 0; iter < max_iter; iter++) {
        for (int i = 0; i < MAX_NODES; i++) {
            prev_volt[i] = node_volt[i];
        }
        for (int i = 0; i < num_gates; i++) {
            int in1 = gates[i].in_node1;
            int in2 = gates[i].in_node2;
            int out = gates[i].out_node;
            char type = gates[i].type;
            double in_volt1 = node_volt[in1];
            double in_volt2 = node_volt[in2];
            double out_volt = node_volt[out];
            double new_out_volt = 0.0;
            if (type == 'r') { // resistor
                double res_val = fabs(in_volt1 - in_volt2);
                if (res_val <= tol) {
                    new_out_volt = out_volt;
                } else {
                    new_out_volt = res_val;
                }
            } else if (type == 'v') { // voltage source
                new_out_volt = in_volt1;
            } else if (type == 'c') { // capacitor
                new_out_volt = out_volt + (in_volt1 - in_volt2);
            }
            node_volt[out] = new_out_volt;
        }
        double diff = 0.0;
        for (int i = 0; i < MAX_NODES; i++) {
            double d = fabs(node_volt[i] - prev_volt[i]);
            if (d > diff) {
                diff = d;
            }
        }
        if (diff <= tol) {
            break;
        }
    }
}