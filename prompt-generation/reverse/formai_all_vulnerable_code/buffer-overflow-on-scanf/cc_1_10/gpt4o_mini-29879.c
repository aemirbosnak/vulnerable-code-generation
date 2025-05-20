//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GATES 10
#define MAX_PLAYERS 2

typedef enum { AND, OR, NOT } GateType;

typedef struct {
    GateType type;
    int input1;
    int input2; // Only used for AND and OR gates
} Gate;

typedef struct {
    Gate gates[MAX_GATES];
    int gate_count;
} Circuit;

void initialize_circuit(Circuit *circuit) {
    circuit->gate_count = 0;
}

void add_gate(Circuit *circuit, GateType type, int input1, int input2) {
    if (circuit->gate_count < MAX_GATES) {
        circuit->gates[circuit->gate_count].type = type;
        circuit->gates[circuit->gate_count].input1 = input1;
        circuit->gates[circuit->gate_count].input2 = input2;
        circuit->gate_count++;
    } else {
        printf("Maximum gate limit reached!\n");
    }
}

int compute_gate(const Gate *gate, const int *inputs) {
    switch (gate->type) {
        case AND:
            return inputs[gate->input1] && inputs[gate->input2];
        case OR:
            return inputs[gate->input1] || inputs[gate->input2];
        case NOT:
            return !inputs[gate->input1];
        default:
            return 0;
    }
}

void display_circuit(const Circuit *circuit) {
    printf("Current Circuit:\n");
    for (int i = 0; i < circuit->gate_count; i++) {
        const Gate *gate = &circuit->gates[i];
        switch (gate->type) {
            case AND:
                printf("Gate %d: AND(%d, %d)\n", i, gate->input1, gate->input2);
                break;
            case OR:
                printf("Gate %d: OR(%d, %d)\n", i, gate->input1, gate->input2);
                break;
            case NOT:
                printf("Gate %d: NOT(%d)\n", i, gate->input1);
                break;
        }
    }
}

int main() {
    Circuit circuit;
    initialize_circuit(&circuit);

    int players[MAX_PLAYERS];
    int inputs[10];

    printf("Welcome to the Multiplayer Circuit Simulator!\n");

    // Get player inputs
    for (int p = 0; p < MAX_PLAYERS; p++) {
        printf("Player %d, enter your binary inputs (0 or 1) for 3 signals:\n", p + 1);
        for (int i = 0; i < 3; i++) {
            printf("Input %d: ", i + 1);
            scanf("%d", &inputs[i]);
        }
        players[p] = inputs[0] + inputs[1] * 2 + inputs[2] * 4; // Combine inputs
    }

    // Allow players to add gates
    for (int p = 0; p < MAX_PLAYERS; p++) {
        int choice, input1, input2;
        printf("\nPlayer %d, choose a gate to add (1: AND, 2: OR, 3: NOT): ", p + 1);
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Choose two inputs (0-2) for AND gate: ");
                scanf("%d %d", &input1, &input2);
                add_gate(&circuit, AND, input1, input2);
                break;
            case 2:
                printf("Choose two inputs (0-2) for OR gate: ");
                scanf("%d %d", &input1, &input2);
                add_gate(&circuit, OR, input1, input2);
                break;
            case 3:
                printf("Choose one input (0-2) for NOT gate: ");
                scanf("%d", &input1);
                add_gate(&circuit, NOT, input1, -1);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    display_circuit(&circuit);

    // Show circuit outputs
    printf("Circuit Outputs:\n");
    for (int i = 0; i < circuit.gate_count; i++) {
        int output = compute_gate(&circuit.gates[i], inputs);
        printf("Output of Gate %d: %d\n", i, output);
    }

    return 0;
}