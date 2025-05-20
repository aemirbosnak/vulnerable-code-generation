//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXNODES 2048
#define MAXCOMMANDS 10000

struct gate {
    int type;
    int input1, input2;
    double value;
};

struct command {
    int type;
    int node;
    int gate;
};

int numNodes = 0;
struct gate gates[MAXNODES];
struct command commands[MAXCOMMANDS];
int numCommands = 0;

void addGate(int type, int input1, int input2, double value) {
    struct gate g;
    g.type = type;
    g.input1 = input1;
    g.input2 = input2;
    g.value = value;
    gates[numNodes++] = g;
}

void addCommand(int type, int node, int gate) {
    struct command c;
    c.type = type;
    c.node = node;
    c.gate = gate;
    commands[numCommands++] = c;
}

double getVoltage(int node) {
    int i, j;
    double voltage[MAXNODES];
    for (i = 0; i < numNodes; i++) {
        voltage[i] = 0;
    }
    for (i = 0; i < numCommands; i++) {
        if (commands[i].type == 0) {
            voltage[commands[i].node] = gates[commands[i].gate].value;
        } else {
            switch (gates[commands[i].gate].type) {
                case 0:
                    voltage[commands[i].node] = voltage[gates[commands[i].gate].input1] + voltage[gates[commands[i].gate].input2];
                    break;
                case 1:
                    voltage[commands[i].node] = voltage[gates[commands[i].gate].input1] - voltage[gates[commands[i].gate].input2];
                    break;
                case 2:
                    voltage[commands[i].node] = voltage[gates[commands[i].gate].input1] * voltage[gates[commands[i].gate].input2];
                    break;
                case 3:
                    voltage[commands[i].node] = voltage[gates[commands[i].gate].input1] / voltage[gates[commands[i].gate].input2];
                    break;
                case 4:
                    voltage[commands[i].node] = exp(voltage[gates[commands[i].gate].input1]*voltage[gates[commands[i].gate].input2]);
                    break;
            }
        }
    }
    return voltage[node];
}

int main() {
    addGate(0, 0, 1, 0);
    addGate(0, 1, 2, 0);
    addGate(1, 3, 0, 0);
    addGate(1, 4, 1, 0);
    addGate(2, 5, 2, 0);
    addGate(3, 6, 3, 0);
    addGate(4, 7, 4, 0);
    addCommand(0, 0, 0);
    addCommand(0, 1, 0);
    addCommand(0, 2, 0);
    addCommand(0, 3, 1);
    addCommand(0, 4, 1);
    addCommand(0, 5, 2);
    addCommand(1, 6, 3);
    addCommand(2, 7, 4);
    printf("Input 1: ");
    scanf("%lf", &gates[1].value);
    printf("Input 2: ");
    scanf("%lf", &gates[2].value);
    printf("Input 3: ");
    scanf("%lf", &gates[5].value);
    printf("Output: %f\n", getVoltage(7));
    return 0;
}