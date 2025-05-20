//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_RES 100

typedef struct {
    char name[20];
    double value;
} Resistor;

typedef struct {
    char name[20];
    int nodes[2];
    double value;
} Component;

int main() {
    int num_nodes, num_resistors, num_components;
    char input[50];
    Component components[MAX_NODES];
    Resistor resistors[MAX_RES];

    // get number of nodes and components from user
    printf("Enter the number of nodes: ");
    fgets(input, 50, stdin);
    num_nodes = atoi(input);

    printf("Enter the number of resistors: ");
    fgets(input, 50, stdin);
    num_resistors = atoi(input);

    printf("Enter the number of other components: ");
    fgets(input, 50, stdin);
    num_components = atoi(input);

    // get resistors
    for (int i = 1; i <= num_resistors; i++) {
        printf("Enter name and resistance value of resistor %d: ", i);
        fgets(input, 50, stdin);
        sscanf(input, "%s %lf", resistors[i-1].name, &resistors[i-1].value);
    }

    // get other components
    for (int i = 1; i <= num_components; i++) {
        printf("Enter name and values of other component %d (Format: name node1 node2 value): ", i);
        fgets(input, 50, stdin);
        sscanf(input, "%s %d %d %lf", components[i-1].name, &components[i-1].nodes[0], &components[i-1].nodes[1], &components[i-1].value);
    }

    // print components
    printf("\nResistors:\n");
    for (int i = 0; i < num_resistors; i++) {
        printf("%s %lf\n", resistors[i].name, resistors[i].value);
    }

    printf("\nOther components:\n");
    for (int i = 0; i < num_components; i++) {
        printf("%s %d %d %lf\n", components[i].name, components[i].nodes[0], components[i].nodes[1], components[i].value);
    }

    // calculate admittance matrix
    double y[num_nodes][num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            y[i][j] = 0;
        }
    }

    for (int i = 0; i < num_components; i++) {
        int node1 = components[i].nodes[0] - 1;
        int node2 = components[i].nodes[1] - 1;

        if (node1 != -1 && node2 != -1) {
            double value = components[i].value;
            double conductance = 1 / value;

            y[node1][node1] += conductance;
            y[node2][node2] += conductance;
            y[node1][node2] -= conductance;
            y[node2][node1] -= conductance;
        }
    }

    // add resistors to admittance matrix
    for (int i = 0; i < num_resistors; i++) {
        int node1, node2;
        double value = resistors[i].value;
        char *name = resistors[i].name;

        sscanf(name, "R%d_%d", &node1, &node2);
        node1--;
        node2--;

        if (node1 != -1 && node2 != -1) {
            double conductance = 1 / value;

            y[node1][node1] += conductance;
            y[node2][node2] += conductance;
            y[node1][node2] -= conductance;
            y[node2][node1] -= conductance;
        }
    }

    // print admittance matrix
    printf("\nAdmittance matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            printf("%lf ", y[i][j]);
        }
        printf("\n");
    }

    // solve for node voltages
    double b[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        b[i] = 0;
    }
    b[0] = 1;

    double x[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        x[i] = 0;
    }

    for (int k = 0; k < num_nodes; k++) {    
        for (int i = k+1; i < num_nodes; i++) {  
            double factor = y[i][k]/y[k][k];
            for (int j = k+1; j < num_nodes; j++) {  
                y[i][j] = y[i][j] - factor * y[k][j];
            }
            b[i] = b[i] - factor*b[k];
        }
    }

    for (int i = num_nodes-1; i >= 0; i--) {
        double sum = 0;
        for (int j = i+1; j < num_nodes; j++) {
            sum += y[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / y[i][i];
    }

    // print node voltages
    printf("\nNode voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("V%d: %lf\n", i+1, x[i]);
    }

    return 0;
}