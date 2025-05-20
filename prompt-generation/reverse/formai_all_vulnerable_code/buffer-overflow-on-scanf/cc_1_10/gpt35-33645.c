//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: detailed
#include <stdio.h>
#define MAX_NODES 100
#define MAX_VALUES 100
#define MIN_NODES 2

int main(){

    // variable declarations
    int num_nodes;
    int num_values[MAX_NODES];
    int input_node[MAX_VALUES];
    int output_node[MAX_VALUES];
    int value[MAX_VALUES];

    // take number of nodes as input
    printf("Enter number of nodes in the circuit: ");
    scanf("%d", &num_nodes);

    // check if the number of nodes is greater than or equal to the minimum value
    if(num_nodes < MIN_NODES){
        printf("Invalid number of nodes! Please enter at least 2 nodes.\n");
        return 1;
    }

    // take values for each node as input
    for(int i=0; i<num_nodes; i++){
        printf("Enter number of values for node %d: ", i+1);
        scanf("%d", &num_values[i]);

        // take input and output nodes and values for each value
        for(int j=0; j<num_values[i]; j++){
            printf("For node %d value %d:\n", i+1, j+1);
            printf("Enter input node: ");
            scanf("%d", &input_node[j]);
            printf("Enter output node: ");
            scanf("%d", &output_node[j]);
            printf("Enter value: ");
            scanf("%d", &value[j]);
        }
    }

    // print the circuit information
    printf("\nCircuit Information:\n");
    printf("--------------------\n");
    for(int i=0; i<num_nodes; i++){
        printf("Node %d:\n", i+1);
        for(int j=0; j<num_values[i]; j++){
            printf("Value %d:\n", j+1);
            printf("Input Node: %d\n", input_node[j]);
            printf("Output Node: %d\n", output_node[j]);
            printf("Value: %d\n", value[j]);
        }
    }

    return 0; // program execution completed successfully
}