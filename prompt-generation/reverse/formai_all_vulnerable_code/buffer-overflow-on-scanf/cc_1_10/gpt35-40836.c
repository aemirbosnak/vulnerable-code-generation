//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_VAL 1000000000.0

typedef struct branch {
    int node1;
    int node2;
    double value;
} branch;

typedef struct node {
    int num;
    int visited;
    double voltage;
    int nbr_count;
    int nbrs[MAX_NODES];
    double weights[MAX_NODES];
} node;

node nodes[MAX_NODES];
int node_count = 0;
branch branches[MAX_NODES];
int branch_count = 0;

void add_branch(int node1, int node2, double value) {
    branches[branch_count].node1 = node1;
    branches[branch_count].node2 = node2;
    branches[branch_count].value = value;
    branch_count++;
}

void add_node(int num) {
    nodes[node_count].num = num;
    nodes[node_count].visited = 0;
    nodes[node_count].voltage = 0.0;
    nodes[node_count].nbr_count = 0;
    node_count++;
}

void add_nbr(node *n, int nbr, double weight) {
    n->nbrs[n->nbr_count] = nbr;
    n->weights[n->nbr_count] = weight;
    n->nbr_count++;
}

void build_network() {
    int i, j;
    for (i = 0; i < node_count; i++) {
        for (j = 0; j < node_count; j++) {
            if (i == j) continue;
            if (nodes[i].num == nodes[j].num) {
                printf("Error: Duplicate node names found\n");
                exit(1);
            }
        }
    }
    for (i = 0; i < branch_count; i++) {
        int node1 = branches[i].node1;
        int node2 = branches[i].node2;
        double value = branches[i].value;
        if (node1 >= node_count || node2 >= node_count) {
            printf("Error: Invalid node number specified in branch\n");
            exit(1);
        }
        add_nbr(&nodes[node1], node2, value);
        add_nbr(&nodes[node2], node1, value); 
    }
}

void print_network() {
    int i, j;
    for (i = 0; i < node_count; i++) {
        printf("Node %d: ", nodes[i].num);
        for (j = 0; j < nodes[i].nbr_count; j++) {
            printf("%d (%lf) ", nodes[i].nbrs[j], nodes[i].weights[j]);
        }
        printf("\n");
    }
}

void dfs(int node, double voltage) {
    nodes[node].visited = 1;
    nodes[node].voltage = voltage;
    int i;
    for (i = 0; i < nodes[node].nbr_count; i++) {
        int nbr = nodes[node].nbrs[i];
        if (!nodes[nbr].visited) {
            dfs(nbr, voltage - nodes[node].weights[i]);
        }
    }
}

int main(void) {
    int num_nodes, num_branches, i;
    printf("Enter the number of nodes and branches: ");
    scanf("%d%d", &num_nodes, &num_branches);
    for (i = 0; i < num_nodes; i++) {
        int num;
        printf("Enter the node number: ");
        scanf("%d", &num);
        add_node(num);
    }
    for (i = 0; i < num_branches; i++) {
        int node1, node2;
        double value;
        printf("Enter the nodes and value for branch %d: ", i + 1);
        scanf("%d%d%lf", &node1, &node2, &value);
        add_branch(node1, node2, value);
    }
    build_network();
    print_network();
    dfs(0, 0.0);
    printf("\nNode voltages:\n");
    for (i = 0; i < node_count; i++) {
        printf("Node %d: %lf\n", nodes[i].num, nodes[i].voltage);
    }
    return 0;
}