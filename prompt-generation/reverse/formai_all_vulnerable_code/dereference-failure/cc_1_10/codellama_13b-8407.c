//Code Llama-13B DATASET v1.0 Category: Classical Circuit Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BITS 10

typedef struct {
    int *values;
    int size;
} Circuit;

void init_circuit(Circuit *circuit) {
    circuit->values = (int *)malloc(NUM_BITS * sizeof(int));
    circuit->size = NUM_BITS;
    for (int i = 0; i < NUM_BITS; i++) {
        circuit->values[i] = 0;
    }
}

void set_bit(Circuit *circuit, int bit, int value) {
    if (bit >= 0 && bit < NUM_BITS) {
        circuit->values[bit] = value;
    }
}

int get_bit(Circuit *circuit, int bit) {
    if (bit >= 0 && bit < NUM_BITS) {
        return circuit->values[bit];
    } else {
        return -1;
    }
}

void and_gate(Circuit *circuit, int input1, int input2, int output) {
    set_bit(circuit, output, get_bit(circuit, input1) & get_bit(circuit, input2));
}

void or_gate(Circuit *circuit, int input1, int input2, int output) {
    set_bit(circuit, output, get_bit(circuit, input1) | get_bit(circuit, input2));
}

void not_gate(Circuit *circuit, int input, int output) {
    set_bit(circuit, output, !get_bit(circuit, input));
}

void print_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->size; i++) {
        printf("%d ", circuit->values[i]);
    }
    printf("\n");
}

int main() {
    Circuit circuit;
    init_circuit(&circuit);

    set_bit(&circuit, 0, 1);
    set_bit(&circuit, 1, 0);
    set_bit(&circuit, 2, 1);

    and_gate(&circuit, 0, 1, 3);
    or_gate(&circuit, 2, 3, 4);
    not_gate(&circuit, 4, 5);

    print_circuit(&circuit);

    return 0;
}