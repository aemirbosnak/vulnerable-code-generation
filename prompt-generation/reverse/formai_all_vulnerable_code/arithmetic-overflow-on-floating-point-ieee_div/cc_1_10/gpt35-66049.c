//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000 // maximum number of nodes in the circuit
#define MAX_EDGES 10000 // maximum number of edges in the circuit

// An edge in the circuit is represented by a struct
typedef struct {
    int from_node; // index of the node at the start of the edge
    int to_node; // index of the node at the end of the edge
    double capacitance; // value of the capacitor associated with the edge
    double resistance; // value of the resistor associated with the edge
} Edge;

// A node in the circuit is represented by a struct
typedef struct {
    double voltage; // voltage at the node
    double current; // current flowing through the node
    double capacitance; // total capacitance of all edges connected to the node
    double resistance; // total resistance of all edges connected to the node
    int num_edges; // number of edges connected to the node
    int edges[MAX_EDGES]; // indices of the edges connected to the node
} Node;

// main function
int main() {
    int num_nodes, num_edges, i, j;
    double time_step, total_time;

    // read input from user
    printf("Enter number of nodes in circuit: ");
    scanf("%d", &num_nodes);
    printf("Enter number of edges in circuit: ");
    scanf("%d", &num_edges);
    printf("Enter time step for simulation: ");
    scanf("%lf", &time_step);
    printf("Enter total time for simulation: ");
    scanf("%lf", &total_time);

    // allocate memory for nodes and edges
    Node *nodes = malloc(num_nodes * sizeof(Node));
    Edge *edges = malloc(num_edges * sizeof(Edge));

    // initialize nodes and edges
    for (i = 0; i < num_nodes; i++) {
        nodes[i].voltage = 0.0;
        nodes[i].current = 0.0;
        nodes[i].capacitance = 0.0;
        nodes[i].resistance = 0.0;
        nodes[i].num_edges = 0;
    }
    for (i = 0; i < num_edges; i++) {
        edges[i].from_node = 0;
        edges[i].to_node = 0;
        edges[i].capacitance = 0.0;
        edges[i].resistance = 0.0;
    }

    // read input for nodes and edges
    for (i = 0; i < num_edges; i++) {
        printf("Enter from_node, to_node, capacitance, and resistance for edge %d: ", i+1);
        scanf("%d %d %lf %lf", &edges[i].from_node, &edges[i].to_node,
              &edges[i].capacitance, &edges[i].resistance);
        nodes[edges[i].from_node-1].edges[nodes[edges[i].from_node-1].num_edges] = i;
        nodes[edges[i].from_node-1].num_edges++;
        nodes[edges[i].to_node-1].edges[nodes[edges[i].to_node-1].num_edges] = i;
        nodes[edges[i].to_node-1].num_edges++;
    }

    // initialize random voltage at node 1
    srand(time(NULL));
    nodes[0].voltage = rand() % 100;

    // simulate circuit
    int num_steps = total_time / time_step;
    for (i = 0; i < num_steps; i++) {
        for (j = 0; j < num_edges; j++) {
            double delta_v = (nodes[edges[j].from_node-1].voltage - nodes[edges[j].to_node-1].voltage)
                             / edges[j].resistance * time_step;
            double delta_q = edges[j].capacitance * delta_v;
            nodes[edges[j].from_node-1].current += delta_q / time_step;
            nodes[edges[j].to_node-1].current -= delta_q / time_step;
        }
        for (j = 0; j < num_nodes; j++) {
            nodes[j].voltage += nodes[j].current / nodes[j].capacitance * time_step;
            nodes[j].current = 0.0;
        }
    }

    // print final voltage at each node
    printf("\nFinal voltages:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("Node %d: %lf\n", i+1, nodes[i].voltage);
    }

    // free memory
    free(nodes);
    free(edges);

    return 0;
}