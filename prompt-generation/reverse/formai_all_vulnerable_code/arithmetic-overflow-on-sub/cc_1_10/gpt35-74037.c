//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_NODES 1000  /*maximum number of nodes*/
#define MAX_VAL 1000     /*maximum value*/

double resistors[MAX_NODES][MAX_NODES];  /*Resistance matrix*/
double currents[MAX_NODES];              /*Current vector*/
double voltages[MAX_NODES];              /*Voltage vector*/
double admittance[MAX_NODES][MAX_NODES]; /*Admittance matrix*/

int nodes;   /*Number of nodes*/
int edges;   /*Number of edges*/

/*Function for adding edges*/
void addEdge(int start, int end, double resistance) {
    resistors[start][start] += 1.0 / resistance;
    resistors[end][end] += 1.0 / resistance;
    resistors[start][end] -= 1.0 / resistance;
    resistors[end][start] -= 1.0 / resistance;
}

/*Function for solving the circuit using Gaussian elimination*/
void solveCircuit() {
    int i, j, k, max_index;
    double max_value, temp;

    for (i = 0; i < nodes; i++) {
        max_index = i;
        max_value = fabs(resistors[i][i]);
        for (j = i + 1; j < nodes; j++) {
            if (fabs(resistors[j][i]) > max_value) {
                max_index = j;
                max_value = fabs(resistors[j][i]);
            }
        }
        for (j = 0; j <= nodes; j++) {
            temp = resistors[i][j];
            resistors[i][j] = resistors[max_index][j];
            resistors[max_index][j] = temp;
        }
        for (j = i + 1; j < nodes; j++) {
            temp = resistors[j][i] / resistors[i][i];
            for (k = i; k <= nodes; k++) {
                resistors[j][k] -= resistors[i][k] * temp;
            }
        }
    }

    for (i = nodes - 1; i >= 0; i--) {
        temp = resistors[i][nodes];
        for (j = nodes - 1; j > i; j--) {
            temp -= resistors[i][j] * voltages[j];
        }
        voltages[i] = temp / resistors[i][i];
    }
}

int main() {
    int i, j, start, end;
    double resistance;

    /*Get the number of nodes and edges from the user*/
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    /*Initialize the matrices to zero*/
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            resistors[i][j] = 0.0;
            admittance[i][j] = 0.0;
        }
        currents[i] = 0.0;
        voltages[i] = 0.0;
    }

    /*Get the resistances and edges from the user*/
    for (i = 0; i < edges; i++) {
        printf("Enter the start node, end node, and resistance (separated by spaces): ");
        scanf("%d %d %lf", &start, &end, &resistance);
        addEdge(start - 1, end - 1, resistance);
    }

    /*Solve the circuit*/
    solveCircuit();

    /*Print the voltages*/
    printf("\nVoltages:\n");
    for (i = 0; i < nodes; i++) {
        printf("V%d = %lf\n", i + 1, voltages[i]);
    }

    return 0;
}