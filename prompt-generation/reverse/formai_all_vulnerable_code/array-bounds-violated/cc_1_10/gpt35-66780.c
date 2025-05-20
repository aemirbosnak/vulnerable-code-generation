//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define MAX_BRANCHES 20

int num_nodes;
int num_branches;

typedef struct {
    int node1;
    int node2;
    char type;
    float value;
    float voltage;
} Branch;

typedef struct {
    float **matrix;
    float *vector;
} Equation;

float **allocate_matrix(int num_rows, int num_cols) {
    float **matrix = (float **)malloc(num_rows * sizeof(float *));
    for (int i = 0; i < num_rows; i++) {
        matrix[i] = (float *)malloc(num_cols * sizeof(float));
        for (int j = 0; j < num_cols; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

float *allocate_vector(int num_rows) {
    float *vector = (float *)malloc(num_rows * sizeof(float));
    for (int i = 0; i < num_rows; i++) {
        vector[i] = 0;
    }
    return vector;
}

Equation *setup_equation(void) {
    Equation *eqn = (Equation *)malloc(sizeof(Equation));
    eqn->matrix = allocate_matrix(num_nodes, num_nodes);
    eqn->vector = allocate_vector(num_nodes);
    return eqn;
}

void add_element(Equation *eqn, Branch *branch, int row) {
    switch (branch->type) {
        case 'R':
            eqn->matrix[row][branch->node1] += 1/branch->value;
            eqn->matrix[row][branch->node2] -= 1/branch->value;
            break;
        case 'V':
            if (branch->node1 >= 0) eqn->matrix[row][branch->node1] += 1;
            if (branch->node2 >= 0) eqn->matrix[row][branch->node2] -= 1;
            eqn->vector[row] += branch->voltage;
            break;
        case 'I':
            eqn->vector[row] += branch->value;
            break;
        case 'G':
            eqn->matrix[row][branch->node1] += branch->value;
            eqn->matrix[row][branch->node2] -= branch->value;
            break;
    }
}

void solve_equation(Equation *eqn) {
    for (int i = 0; i < num_nodes; i++) {
        // find the nonzero pivot element in column i
        int max_row = i;
        for (int j = i; j < num_nodes; j++) {
            if (eqn->matrix[j][i] > eqn->matrix[max_row][i]) {
                max_row = j;
            }
        }
        // swap rows i and max_row
        if (i != max_row) {
            for (int j = i; j < num_nodes; j++) {
                float temp = eqn->matrix[i][j];
                eqn->matrix[i][j] = eqn->matrix[max_row][j];
                eqn->matrix[max_row][j] = temp;
            }
            float temp = eqn->vector[i];
            eqn->vector[i] = eqn->vector[max_row];
            eqn->vector[max_row] = temp;
        }
        // zero out the lower triangular part of column i
        for (int j = i + 1; j < num_nodes; j++) {
            float factor = eqn->matrix[j][i] / eqn->matrix[i][i];
            eqn->matrix[j][i] = 0;
            eqn->vector[j] -= factor * eqn->vector[i];
            for (int k = i + 1; k < num_nodes; k++) {
                eqn->matrix[j][k] -= factor * eqn->matrix[i][k];
            }
        }
    }
    // solve the upper triangular system
    for (int i = num_nodes - 1; i >= 0; i--) {
        for (int j = i + 1; j < num_nodes; j++) {
            eqn->vector[i] -= eqn->matrix[i][j] * eqn->vector[j];
        }
        eqn->vector[i] /= eqn->matrix[i][i];
    }
}

void print_equation(Equation *eqn) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%5.1f ", eqn->matrix[i][j]);
        }
        printf("| %5.1f\n", eqn->vector[i]);
    }
}

int main() {
    Branch branches[MAX_BRANCHES];
    num_nodes = 0;
    num_branches = 0;

    // add elements to the circuit
    branches[num_branches++] = (Branch){0, 1, 'R', 100};
    branches[num_branches++] = (Branch){1, 2, 'V', 5, 10};
    branches[num_branches++] = (Branch){2, -1, 'I', 2};
    branches[num_branches++] = (Branch){2, 3, 'R', 50};
    branches[num_branches++] = (Branch){3, -1, 'V', 2, 20};

    // find the number of nodes in the circuit and assign node numbers to all branches
    int node_map[MAX_NODES] = {-1};
    for (int i = 0; i < num_branches; i++) {
        if (node_map[branches[i].node1] < 0) {
            node_map[branches[i].node1] = num_nodes++;
        }
        if (node_map[branches[i].node2] < 0) {
            node_map[branches[i].node2] = num_nodes++;
        }
    }
    for (int i = 0; i < num_branches; i++) {
        branches[i].node1 = node_map[branches[i].node1];
        branches[i].node2 = node_map[branches[i].node2];
    }

    // set up and solve the equation
    Equation *eqn = setup_equation();
    for (int i = 0; i < num_branches; i++) {
        add_element(eqn, &branches[i], i);
    }
    printf("Circuit equation:\n");
    print_equation(eqn);
    solve_equation(eqn);

    // print the node voltages
    printf("Node voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("V%d = %5.1f\n", i, eqn->vector[i]);
    }
    return 0;
}