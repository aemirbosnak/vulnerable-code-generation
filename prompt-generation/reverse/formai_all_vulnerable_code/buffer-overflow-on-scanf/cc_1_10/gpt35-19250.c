//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

struct node {
    int n;
    int *p;
} *circuit;

void read_circuit_input() {
    int i, j, n_inputs, n_gates;

    printf("Please enter the number of inputs: ");
    scanf("%d", &n_inputs);

    printf("Please enter the number of gates: ");
    scanf("%d", &n_gates);

    circuit = (struct node*) malloc((n_inputs + n_gates + 1) * sizeof(struct node));

    for(i = 1; i <= n_inputs + n_gates; i++) { //Initialize all the nodes to zero
        circuit[i].n = 0; 
        circuit[i].p = NULL;
    }

    for(i = 1; i <= n_inputs; i++) { //Get the inputs from the user
        printf("Please enter the value of input %d: ", i);
        scanf("%d", &circuit[i].n);
    }

    for(i = n_inputs + 1; i <= n_inputs + n_gates; i++) { //Get the gates from the user
        int type, num_inputs;

        printf("Please enter the type of gate %d (1 for AND, 2 for OR): ", i - n_inputs);
        scanf("%d", &type);

        printf("Please enter the number of inputs for gate %d: ", i - n_inputs);
        scanf("%d", &num_inputs);

        circuit[i].p = (int*) malloc(num_inputs * sizeof(int));

        for(j = 0; j < num_inputs; j++) {
            printf("Please enter the input node number for input %d of gate %d: ", j + 1, i - n_inputs);
            scanf("%d", &circuit[i].p[j]);
        }

        circuit[i].n = type; //Set the type of the gate
    }
}

int compute(int node) {
    int i, result;

    if(circuit[node].p == NULL) { //The node is an input
        return circuit[node].n;
    }
    else { //The node is a gate
        if(circuit[node].n == 1) { //AND gate
            result = 1;

            for(i = 0; i < sizeof(circuit[node].p) / sizeof(int); i++) {
                result = result && compute(circuit[node].p[i]);
            }

            return result;
        }
        else { //OR gate
            result = 0;

            for(i = 0; i < sizeof(circuit[node].p) / sizeof(int); i++) {
                result = result || compute(circuit[node].p[i]);
            }

            return result;
        }
    }
}

int main() {
    int i, n_inputs, n_gates, output;

    read_circuit_input();

    n_inputs = sizeof(circuit) / sizeof(struct node) - 1 - n_gates;

    printf("The truth table for this circuit is:\n\n");

    for(i = 0; i < (1 << n_inputs); i++) {
        int j;

        for(j = 0; j < n_inputs; j++) {
            circuit[j + 1].n = (i >> (n_inputs - j - 1)) & 1;
        }

        output = compute(n_inputs + 1);

        for(j = 0; j < n_inputs; j++) {
            printf("%d ", circuit[j + 1].n);
        }

        printf(": %d\n", output);
    }

    return 0;
}