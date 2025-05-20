//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_RESISTORS 2000
#define MAX_NAME_LEN 20
#define MAX_ITERATIONS 500
#define MIN_ITERATIONS 10
#define CONVERGENCE_THRESHOLD 0.00001

typedef struct resistor {
    char name[MAX_NAME_LEN];
    double resistance;
    int node1;
    int node2;
} Resistor;

int num_nodes;
int num_resistors;
int G[MAX_NODES][MAX_NODES];
double B[MAX_NODES][MAX_NODES];
double V[MAX_NODES];
double I[MAX_NODES];

void initialize_matrices() {
    int i, j;
    for (i = 0; i < num_nodes; i++) {
        V[i] = 0.0;
        I[i] = 0.0;
        for (j = 0; j < num_nodes; j++) {
            G[i][j] = 0;
            B[i][j] = 0.0;
        }
    }
}

void add_resistor(Resistor* r) {
    int node1 = r->node1;
    int node2 = r->node2;
    double resistance = r->resistance;
    G[node1][node1] += 1.0 / resistance;
    G[node1][node2] -= 1.0 / resistance;
    G[node2][node1] -= 1.0 / resistance;
    G[node2][node2] += 1.0 / resistance;
}

void read_input() {
    num_nodes = 0;
    num_resistors = 0;
    char input[MAX_NAME_LEN + 10];
    while (1) {
        scanf("%s", input);
        if (input[0] == '.') break;
        if (input[0] == 'r') {
            Resistor* r = (Resistor*) malloc(sizeof(Resistor));
            sscanf(input + 1, "%lf%*c%d%*c%d%*c%s", &(r->resistance), &(r->node1), &(r->node2), r->name);
            add_resistor(r);
            free(r);
            num_resistors++;
        }
        else if (input[0] == 'v') {
            sscanf(input + 1, "%lf%*c%d%*c%d", &V[num_nodes], &(G[num_nodes][num_nodes]), &(G[num_nodes][num_nodes + 1]));
            num_nodes += 2;
        }
    }
}

int jacobi_iterations(int max_iterations, double convergence_threshold) {
    int i, j, k;
    double max_change, d, sum, new_v;
    for (k = 0; k < max_iterations; k++) {
        max_change = 0.0;
        for (i = 0; i < num_nodes; i++) {
            d = 0.0;
            for (j = 0; j < num_nodes; j++) {
                if (i != j) d += B[i][j] * V[j];
            }
            new_v = (I[i] - d) / B[i][i];
            max_change = fmax(max_change, fabs(new_v - V[i]));
            V[i] = new_v;
        }
        if (max_change < convergence_threshold) return k;
    }
    return max_iterations;
}

int main() {
    initialize_matrices();
    read_input();
    int i, j, iterations;
    for (i = 0; i < num_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            B[i][j] = G[i][j];
            if (i == j) B[i][j] -= 1.0;
        }
    }
    iterations = jacobi_iterations(MAX_ITERATIONS, CONVERGENCE_THRESHOLD);
    if (iterations >= MIN_ITERATIONS) {
        for (i = 0; i < num_nodes - 1; i++) {
            printf("V_%d = %f\n", i, V[i]);
        }
    }
    else {
        printf("Could not find a solution in %d iterations.\n", MAX_ITERATIONS);
    }
    return 0;
}