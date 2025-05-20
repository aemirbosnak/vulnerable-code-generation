//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

/* configurable parameters */
#define MAX_NODES 100 /* maximum number of nodes */
#define MAX_VOLTAGE 10.0 /* maximum voltage allowed */
#define SIM_TIME 10.0 /* time interval for simulation */
#define STEP_SIZE 0.01 /* step size for simulation */

/* circuit and simulation variables */
double g_matrix[MAX_NODES][MAX_NODES], b_matrix[MAX_NODES][MAX_NODES], c_matrix[MAX_NODES][1], v_matrix[MAX_NODES][1], x_matrix[MAX_NODES][1];
double node_voltage[MAX_NODES];
int node_type[MAX_NODES];
int num_nodes;

/* function prototypes */
void initialize_circuit();
void update_matrices(double time_interval);
void perform_simulation();

/* main program */
int main(void) {
    /* initialize the circuit */
    initialize_circuit();

    /* perform simulation */
    perform_simulation();

    /* print out final node voltages */
    printf("Final node voltages:\n");
    int i;
    for (i=0; i<num_nodes; i++) {
        printf("Node %d: %f\n", i, x_matrix[i][0]);
    }

    return 0;
}

/* initializes circuit parameters */
void initialize_circuit() {
    /* set up node voltages and types */
    num_nodes = 4;
    node_voltage[0] = 0.0; node_type[0] = 0; /* ground node */
    node_voltage[1] = 0.0; node_type[1] = 1; /* voltage source node */
    node_voltage[2] = 5.0; node_type[2] = 2; /* resistor node */
    node_voltage[3] = 0.0; node_type[3] = 3; /* capacitor node */

    /* set up circuit elements (conductances and susceptances) */
    g_matrix[0][0] = 1.0; /* connection to ground */
    g_matrix[1][1] = 1.0; /* voltage source */
    g_matrix[2][2] = 1.0/1000.0; /* resistor */
    b_matrix[3][3] = 1.0/0.00001; /* capacitor */

    /* set up initial matrices */
    int i, j;
    for (i=0; i<num_nodes; i++) {
        for (j=0; j<num_nodes; j++) {
            if (i!=j) {
                g_matrix[i][j] = 0.0;
                b_matrix[i][j] = 0.0;
            }
        }
    }

    /* set up initial voltage matrix */
    v_matrix[1][0] = 10.0; /* voltage source */
}

/* updates circuit matrices for given time interval */
void update_matrices(double time_interval) {
    int i, j;

    /* update conductance matrix */
    g_matrix[1][2] = -1.0/1000.0*time_interval; /* resistor */
    g_matrix[2][1] = -1.0/1000.0*time_interval;

    /* update susceptance matrix */
    b_matrix[3][3] = -1.0/0.00001/time_interval; /* capacitor */

    /* update voltage matrix */
    v_matrix[3][0] = -1.0/0.00001*time_interval*(x_matrix[3][0]); /* capacitor */

    /* update current vector */
    c_matrix[2][0] = v_matrix[1][0]/1000.0; /* resistor current */

    /* calculate new node voltages */
    double y_matrix[MAX_NODES][MAX_NODES], z_matrix[MAX_NODES][1];
    for (i=0; i<num_nodes; i++) {
        z_matrix[i][0] = c_matrix[i][0]/g_matrix[i][i];
        for (j=0; j<num_nodes; j++) {
            if (i!=j) {
                y_matrix[i][j] = g_matrix[i][j]/g_matrix[i][i];
                z_matrix[i][0] -= y_matrix[i][j]*x_matrix[j][0];
            }
        }
    }
    for (i=0; i<num_nodes; i++) {
        x_matrix[i][0] = z_matrix[i][0];
    }
}

/* performs simulation */
void perform_simulation() {
    double time_interval = 0.0;
    while (time_interval <= SIM_TIME) {
        /* update matrices and perform simulation step */
        update_matrices(time_interval);
        time_interval += STEP_SIZE;
    }
}