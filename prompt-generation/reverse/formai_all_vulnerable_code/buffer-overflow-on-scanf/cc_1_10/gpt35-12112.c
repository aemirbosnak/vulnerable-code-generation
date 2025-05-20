//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 10000

struct component {
    char type;
    int node1;
    int node2;
    double value;
};

struct node {
    double voltage;
    int visited;
};

struct component circuit[MAXSIZE];
struct node nodes[MAXSIZE];
int num_nodes = 0;
int num_components = 0;

void simulate() {
    int i, j, k;
    for(i = 1; i <= num_nodes; ++i) {
        nodes[i].visited = 0;
    }
    for(i = 0; i < num_components; ++i) {
        if(circuit[i].type == 'R') {
            int node1 = circuit[i].node1;
            int node2 = circuit[i].node2;
            double value = circuit[i].value;
            nodes[node1].voltage -= (nodes[node1].voltage - nodes[node2].voltage) * value / (value + 1);
            nodes[node2].voltage -= (nodes[node2].voltage - nodes[node1].voltage) * value / (value + 1);
        }
        else if(circuit[i].type == 'C') {
            int node1 = circuit[i].node1;
            int node2 = circuit[i].node2;
            double value = circuit[i].value;
            double current = nodes[node1].voltage - nodes[node2].voltage;
            nodes[node1].voltage -= current / (value + 1);
            nodes[node2].voltage += current / (value + 1);
        }
        else if(circuit[i].type == 'L') {
            int node1 = circuit[i].node1;
            int node2 = circuit[i].node2;
            double value = circuit[i].value;
            double current = nodes[node1].voltage - nodes[node2].voltage;
            nodes[node1].voltage -= current * value;
            nodes[node2].voltage += current * value;
        }
        else if(circuit[i].type == 'V') {
            int node1 = circuit[i].node1;
            int node2 = circuit[i].node2;
            double value = circuit[i].value;
            double voltage = value;
            nodes[node1].voltage -= voltage;
            nodes[node2].voltage += voltage;
        }
        else if(circuit[i].type == 'I') {
            int node1 = circuit[i].node1;
            int node2 = circuit[i].node2;
            double value = circuit[i].value;
            double current = value;
            nodes[node1].voltage -= current;
            nodes[node2].voltage += current;
        }
    }
    for(i = 1; i <= num_nodes; ++i) {
        if(!nodes[i].visited) {
            double voltage = nodes[i].voltage;
            for(j = i + 1; j <= num_nodes; ++j) {
                if(!nodes[j].visited) {
                    double diff = fabs(voltage - nodes[j].voltage);
                    if(diff < 1e-6) {
                        nodes[j].visited = 1;
                        nodes[j].voltage = voltage;
                    }
                }
            }
            nodes[i].visited = 1;
        }
    }
}

int main() {
    char type;
    int node1, node2;
    double value;
    while(scanf("%c %d %d %lf", &type, &node1, &node2, &value) == 4) {
        circuit[num_components].type = type;
        circuit[num_components].node1 = node1;
        circuit[num_components].node2 = node2;
        circuit[num_components].value = value;
        if(node1 > num_nodes) num_nodes = node1;
        if(node2 > num_nodes) num_nodes = node2;
        ++num_components;
    }
    int i;
    for(i = 1; i <= num_nodes; ++i) {
        nodes[i].voltage = 0;
    }
    for(i = 1; i <= 1000; ++i) {
        simulate();
    }
    printf("Circuit simulation complete!\n");
    for(i = 1; i <= num_nodes; ++i) {
        printf("Node %d voltage: %lf\n", i, nodes[i].voltage);
    }
    return 0;
}