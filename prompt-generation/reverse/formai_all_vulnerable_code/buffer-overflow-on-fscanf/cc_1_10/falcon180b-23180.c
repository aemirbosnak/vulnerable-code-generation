//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

//Defining the maximum number of nodes
#define MAX_NODES 1000

int main() {

    int num_nodes, num_elements, i, j, k;
    double resistance[MAX_NODES][MAX_NODES], voltage[MAX_NODES], current[MAX_NODES];
    char circuit_file[100];

    //Read in the number of nodes and elements from the user
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    //Initialize the resistance matrix to infinity
    for(i=0; i<num_nodes; i++) {
        for(j=0; j<num_nodes; j++) {
            resistance[i][j] = 1e9;
        }
    }

    //Read in the circuit file from the user
    printf("Enter the circuit file name: ");
    scanf("%s", circuit_file);

    //Open the circuit file
    FILE* circuit_file_ptr = fopen(circuit_file, "r");

    if(circuit_file_ptr == NULL) {
        printf("Error: Could not open circuit file.\n");
        exit(1);
    }

    //Read in the circuit elements from the file
    for(i=0; i<num_elements; i++) {
        fscanf(circuit_file_ptr, "%d %d %lf", &j, &k, &resistance[j][k]);
    }

    //Close the circuit file
    fclose(circuit_file_ptr);

    //Calculate the circuit voltages and currents
    for(i=0; i<num_nodes; i++) {
        voltage[i] = 0;
        current[i] = 0;
    }

    for(i=0; i<num_nodes; i++) {
        for(j=0; j<num_nodes; j++) {
            if(resistance[i][j]!= 1e9) {
                current[i] += voltage[j] * resistance[i][j];
            }
        }
    }

    //Print out the circuit voltages and currents
    printf("Node\tVoltage\tCurrent\n");
    for(i=0; i<num_nodes; i++) {
        printf("%d\t%lf\t%lf\n", i, voltage[i], current[i]);
    }

    return 0;
}