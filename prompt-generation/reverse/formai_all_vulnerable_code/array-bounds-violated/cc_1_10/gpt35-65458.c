//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Shape shifter functions
void rot90(int x[], int y[]) {
    int temp = x[0];
    x[0] = y[1];
    y[1] = y[0];
    y[0] = x[1];
    x[1] = temp;
}

void flip(int x[], int y[]) {
    int temp = x[0];
    x[0] = x[1];
    x[1] = temp;
    temp = y[0];
    y[0] = y[1];
    y[1] = temp;
}

// Main simulation function
void simulate(int circuit[][2], int n, int inputs[], int outputs[]) {
    // Initialize all nodes to 0
    int nodes[n];
    memset(nodes, 0, n * sizeof(int));

    // Bind inputs to node 1 and 2
    nodes[0] = inputs[0];
    nodes[1] = inputs[1];

    // Loop through circuit logic
    for (int i = 0; i < n; i++) {
        int gate = circuit[i][0];
        int inputs[2], outputs[2];

        // Retrieve inputs and outputs based on gate type
        switch (gate) {
            case 0:
                inputs[0] = circuit[i][1];
                inputs[1] = circuit[i][2];
                outputs[0] = circuit[i][3];
                break;
            case 1:
                inputs[0] = inputs[1] = circuit[i][1];
                outputs[0] = circuit[i][2];
                break;
            case 2:
                inputs[0] = circuit[i][1];
                outputs[0] = circuit[i][2];
                break;
            case 3:
                inputs[0] = circuit[i][1];
                outputs[0] = circuit[i][2];
                break;
        }

        // Apply shape shifting to input and output nodes
        int x[] = {inputs[0], outputs[0]};
        int y[] = {inputs[1], outputs[1]};
        rot90(x, y);
        flip(x, y);
        rot90(x, y);

        // Perform logic gate operation on input nodes and update output node
        switch (gate) {
            case 0:
                nodes[outputs[0] - 1] = nodes[inputs[0] - 1] && nodes[inputs[1] - 1];
                break;
            case 1:
                nodes[outputs[0] - 1] = nodes[inputs[0] - 1] || nodes[inputs[1] - 1];
                break;
            case 2:
                nodes[outputs[0] - 1] = !nodes[inputs[0] - 1];
                break;
            case 3:
                nodes[outputs[0] - 1] = nodes[inputs[0] - 1] ^ nodes[inputs[1] - 1];
                break;
        }

        // Apply shape shifting to output node
        int temp = x[1];
        x[1] = y[0];
        y[0] = y[1];
        y[1] = x[0];
        x[0] = temp;
        rot90(x, y);
        flip(x, y);
        rot90(x, y);
        nodes[outputs[0] - 1] = x[1];
    }

    // Set output values based on node states
    outputs[0] = nodes[n - 2];
    outputs[1] = nodes[n - 1];
}

int main() {
    // Define circuit components
    int circuit[6][4] = {
        {0, 1, 2, 3},
        {1, 3},
        {2, 4},
        {1, 2},
        {0, 3, 4, 5},
        {1, 4}
    };

    // Define input and output values
    int inputs[2] = {1, 0};
    int outputs[2];

    simulate(circuit, 6, inputs, outputs);

    printf("Output: [%d, %d]", outputs[0], outputs[1]);

    return 0;
}