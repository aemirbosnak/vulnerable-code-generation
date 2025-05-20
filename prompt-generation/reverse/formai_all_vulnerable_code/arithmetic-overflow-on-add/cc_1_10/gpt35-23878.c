//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GATE_COUNT 10
#define BAGGAGE_COUNT_PER_GATE 5
#define MAX_BAGGAGE_WEIGHT 30

typedef struct Baggage {
    int weight; // in kg
    int gate_number;
    char* destination;
} Baggage;

typedef struct Gate {
    Baggage* baggage[BAGGAGE_COUNT_PER_GATE];
    int baggage_count;
} Gate;

void print_baggage(Baggage* baggage) {
    printf("Weight: %dkg, Gate Number: %d, Destination: %s\n", baggage->weight, baggage->gate_number, baggage->destination);
}

void print_gate(Gate* gate) {
    printf("Gate Number: %d\n", gate->baggage[0]->gate_number);
    printf("Baggage count: %d\n", gate->baggage_count);
    for (int i = 0; i < gate->baggage_count; i++) {
        print_baggage(gate->baggage[i]);
    }
}

void initialize_gate(Gate* gate, int gate_number) {
    gate->baggage_count = 0;
    for (int i = 0; i < BAGGAGE_COUNT_PER_GATE; i++) {
        Baggage* b = (Baggage*)malloc(sizeof(Baggage));
        b->weight = rand() % MAX_BAGGAGE_WEIGHT + 1;
        b->gate_number = gate_number;
        b->destination = "Cybercity";
        gate->baggage[i] = b;
        gate->baggage_count++;
    }
}

void print_all_gates(Gate** gates) {
    printf("**********BAGGAGE AT ALL GATES**********\n");
    for (int i = 0; i < GATE_COUNT; i++) {
        printf("Gate number: %d\n", i);
        print_gate(gates[i]);
    }
}

void load_baggage_to_plane(Gate** gates) {
    printf("**********LOADING BAGGAGE TO PLANES**********\n");
    for (int i = 0; i < GATE_COUNT; i++) {
        int baggage_loaded = 0;
        while (baggage_loaded < BAGGAGE_COUNT_PER_GATE) {
            if (gates[i]->baggage_count == 0) {
                break;
            }
            Baggage* b = gates[i]->baggage[gates[i]->baggage_count-1];
            printf("Loading baggage from Gate %d to Plane heading to %s. ", i, b->destination);
            print_baggage(b);
            gates[i]->baggage[gates[i]->baggage_count-1] = NULL;
            gates[i]->baggage_count--;
            free(b);
            baggage_loaded++;
        }
    }
}

int main() {
    srand(time(NULL));

    // Create all gates
    Gate** gates = (Gate**)malloc(sizeof(Gate*) * GATE_COUNT);
    for (int i = 0; i < GATE_COUNT; i++) {
        gates[i] = (Gate*)malloc(sizeof(Gate));
        initialize_gate(gates[i], i);
    }

    // Print all gates
    print_all_gates(gates);

    // Load baggage to plane
    load_baggage_to_plane(gates);

    // Print all gates after loading
    print_all_gates(gates);

    return 0;
}