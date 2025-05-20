//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum circuit size */
#define MAX_SIZE 10

/* Define a node for the circuit */
typedef struct node {
    int value;      /* The value of the node */
    int link;       /* The link to the next node in the circuit */
} NODE;

/* Define the circuit */
NODE circuit[MAX_SIZE];

/* Define the main function */
int main(void) {
    int size, i, j, input, output, temp;
    int num_inputs, num_outputs;
    int inputs[MAX_SIZE], outputs[MAX_SIZE];

    /* Get the size of the circuit */
    printf("Enter the size of the circuit (maximum %d): ", MAX_SIZE);
    scanf("%d", &size);

    /* Check that the size is within bounds */
    if (size < 2 || size > MAX_SIZE) {
        printf("Error: Invalid circuit size\n");
        return 1;
    }

    /* Get the number of inputs and outputs */
    printf("Enter the number of inputs: ");
    scanf("%d", &num_inputs);
    printf("Enter the number of outputs: ");
    scanf("%d", &num_outputs);

    /* Check that the number of inputs and outputs are valid */
    if (num_inputs < 1 || num_inputs > size-1 || num_outputs < 1 || num_outputs > size-1) {
        printf("Error: Invalid number of inputs or outputs\n");
        return 1;
    }

    /* Initialize the circuit */
    for (i = 0; i < size; i++) {
        circuit[i].value = 0;
        circuit[i].link = i+1;
    }
    circuit[size-1].link = -1; /* The last node points to the end of the circuit */

    /* Get the inputs */
    for (i = 0; i < num_inputs; i++) {
        printf("Enter input value %d (0 or 1): ", i);
        scanf("%d", &input);
        if (input != 0 && input != 1) {
            printf("Error: Invalid input value\n");
            return 1;
        }
        circuit[i].value = input;
    }

    /* Get the outputs */
    for (i = 0; i < num_outputs; i++) {
        printf("Enter output value %d (0 or 1): ", i);
        scanf("%d", &output);
        if (output != 0 && output != 1) {
            printf("Error: Invalid output value\n");
            return 1;
        }
        outputs[i] = size - num_outputs + i;
        circuit[outputs[i]].value = output;
    }

    /* Simulate the circuit */
    printf("\nSimulating the circuit...\n");
    for (i = 0; i < size; i++) {
        temp = circuit[i].value;
        if (i >= num_inputs) {
            /* Get the input values for this node */
            for (j = 0; circuit[j].link != i; j++) {
                /* Do nothing */
            }
            while (j != -1) {
                circuit[i].value = circuit[j].value;
                j = circuit[j].link;
            }
        }
        /* Perform the logic operation for this node */
        switch (i) {
            case 0:
                /* First node is always a buffer */
                break;
            case 1:
                /* Second node is always an inverter */
                circuit[i].value = !circuit[i].value;
                break;
            case 2:
                /* Third node is always a 2-input AND gate */
                circuit[i].value = circuit[i-2].value & circuit[i-1].value;
                break;
            case 3:
                /* Fourth node is always a 2-input OR gate */
                circuit[i].value = circuit[i-2].value | circuit[i-1].value;
                break;
            default:
                /* 5-input NAND gate */
                circuit[i].value = !(circuit[i-4].value & circuit[i-3].value & circuit[i-2].value & circuit[i-1].value & circuit[i].value);
                break;
        }
        printf("Node %d: %d -> %d\n", i, temp, circuit[i].value);
    }

    /* Print the outputs */
    printf("\nOutputs:\n");
    for (i = 0; i < num_outputs; i++) {
        printf("Output %d: %d\n", i, circuit[outputs[i]].value);
    }

    return 0;
}