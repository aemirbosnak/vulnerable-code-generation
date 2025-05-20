//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: interoperable
#include <stdio.h>
#include <math.h>

#define MAX_NODES 10
#define MAX_BRANCHES 10

typedef struct {
    int node1;
    int node2;
    double resistance;
} Branch;

typedef struct {
    int node;
    double voltage;
} NodeV;

int main() {
    int num_nodes, num_branches, num_vsrc;
    double g[MAX_NODES][MAX_NODES], b[MAX_NODES][MAX_NODES], v[MAX_NODES][1];
    Branch branches[MAX_BRANCHES];
    NodeV node_v[MAX_NODES];
    
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    
    printf("Enter the number of branches: ");
    scanf("%d", &num_branches);
    
    printf("Enter the number of voltage sources: ");
    scanf("%d", &num_vsrc);
    
    for(int i=0; i<num_branches; i++) {
        printf("Enter details of branch %d (node1, node2, resistance in ohms): ", i+1);
        scanf("%d %d %lf", &branches[i].node1, &branches[i].node2, &branches[i].resistance);
        branches[i].node1--;
        branches[i].node2--;
        g[branches[i].node1][branches[i].node2] -= 1/branches[i].resistance;
        g[branches[i].node2][branches[i].node1] -= 1/branches[i].resistance;
        g[branches[i].node1][branches[i].node1] += 1/branches[i].resistance;
        g[branches[i].node2][branches[i].node2] += 1/branches[i].resistance;
    }
    
    for(int i=0; i<num_vsrc; i++) {
        printf("Enter details of voltage source %d (node, voltage in volts): ", i+1);
        scanf("%d %lf", &node_v[i].node, &node_v[i].voltage);
        node_v[i].node--;
    }
    
    // Apply KCL at each node
    for(int i=0; i<num_nodes; i++) {
        for(int j=0; j<num_branches; j++) {
            if(branches[j].node1 == i) {
                b[i][num_branches] += 1/branches[j].resistance;
            }
            else if(branches[j].node2 == i) {
                b[i][num_branches] -= 1/branches[j].resistance;
            }
        }
        for(int j=0; j<num_vsrc; j++) {
            if(node_v[j].node == i) {
                v[i][0] = node_v[j].voltage;
            }
        }
    }
    
    // Solve for voltages using Gaussian elimination
    for(int k=0; k<num_nodes; k++) {
        for(int i=k+1; i<num_nodes; i++) {
            double factor = g[i][k]/g[k][k];
            for(int j=k+1; j<num_nodes; j++) {
                g[i][j] -= factor * g[k][j];
            }
            for(int j=0; j<=num_branches; j++) {
                b[i][j] -= factor * b[k][j];
            }
            v[i][0] -= factor * v[k][0];
        }
    }
    
    for(int k=num_nodes-1; k>=0; k--) {
        v[k][0] = b[k][num_branches];
        for(int i=k+1; i<num_nodes; i++) {
            v[k][0] -= g[k][i] * v[i][0];
        }
        v[k][0] /= g[k][k];
    }
    
    printf("\n");
    for(int i=0; i<num_nodes; i++) {
        printf("Voltage at node %d relative to ground: %lf V\n", i+1, v[i][0]);
    }
    
    return 0;
}