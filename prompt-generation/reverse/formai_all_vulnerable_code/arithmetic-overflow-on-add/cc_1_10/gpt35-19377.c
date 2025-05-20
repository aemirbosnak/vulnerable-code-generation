//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// define the maximum number of nodes and elements allowed
#define MAX_NODES 100
#define MAX_ELEMENTS 200

// struct to store node properties
struct node {
    int name;
    int vol;
};

// struct to store element properties
struct element {
    int name;
    int src;
    int dest;
    int val;
};

// function to initialize nodes with default values
void init_nodes(struct node* nodes, int n) {
    for(int i=0; i<n; i++) {
        nodes[i].name = i+1;  // node name starts from 1
        nodes[i].vol = 0;  // initialize node voltage to 0
    }
}

// function to add an element to the circuit
void add_element(struct element* elements, int* count, int src, int dest, int val) {
    elements[*count].name = *count+1;  // element name starts from 1
    elements[*count].src = src;
    elements[*count].dest = dest;
    elements[*count].val = val;
    (*count)++;  // increment element count
}

// function to print the circuit
void print_circuit(struct node* nodes, struct element* elements, int n, int count) {
    printf("Circuit:\n");
    for(int i=0; i<n; i++) {
        printf("Node %d, V = %d\n", nodes[i].name, nodes[i].vol);
    }
    for(int i=0; i<count; i++) {
        printf("Element %d: %d -> %d, R = %d\n", elements[i].name, elements[i].src, elements[i].dest, elements[i].val);
    }
}

// function to simulate the circuit for a given time interval
void simulate_circuit(struct node* nodes, struct element* elements, int n, int count, double t, double dt) {
    int iterations = t / dt;  // number of iterations
    for(int i=0; i<iterations; i++) {
        // simulate each element in the circuit
        for(int j=0; j<count; j++) {
            double volts = (nodes[elements[j].src-1].vol - nodes[elements[j].dest-1].vol) / (double)elements[j].val;
            nodes[elements[j].src-1].vol -= volts * dt;
            nodes[elements[j].dest-1].vol += volts * dt;
        }
    }
    printf("Circuit simulation complete!\n");
}

int main() {
    struct node nodes[MAX_NODES];
    struct element elements[MAX_ELEMENTS];
    int n, count = 0;
    double t, dt;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    init_nodes(nodes, n);  // initialize nodes

    printf("Enter the time interval and time step: ");
    scanf("%lf%lf", &t, &dt);

    printf("Enter the number of elements: ");
    scanf("%d", &count);

    // add each element to the circuit
    for(int i=0; i<count; i++) {
        int src, dest, val;
        printf("Enter the source and destination nodes, and resistance: ");
        scanf("%d%d%d", &src, &dest, &val);
        add_element(elements, &count, src, dest, val);
    }

    print_circuit(nodes, elements, n, count);  // print the circuit
    
    simulate_circuit(nodes, elements, n, count, t, dt);  // simulate the circuit
    
    return 0;
}