//GEMINI-pro DATASET v1.0 Category: Classical Circuit Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int n;
    int *gates;
    int *values;
} circuit;

circuit *circuit_create(int n) {
    circuit *c = malloc(sizeof(circuit));
    c->n = n;
    c->gates = malloc(sizeof(int) * n);
    c->values = malloc(sizeof(int) * n);
    return c;
}

void circuit_destroy(circuit *c) {
    free(c->gates);
    free(c->values);
    free(c);
}

void circuit_set_gate(circuit *c, int i, int gate) {
    c->gates[i] = gate;
}

void circuit_set_value(circuit *c, int i, int value) {
    c->values[i] = value;
}

int circuit_evaluate(circuit *c) {
    int i;
    for (i = 0; i < c->n; i++) {
        switch (c->gates[i]) {
            case 0: // AND
                c->values[i] = c->values[i - 1] && c->values[i - 2];
                break;
            case 1: // OR
                c->values[i] = c->values[i - 1] || c->values[i - 2];
                break;
            case 2: // NOT
                c->values[i] = !c->values[i - 1];
                break;
            case 3: // XOR
                c->values[i] = c->values[i - 1] ^ c->values[i - 2];
                break;
            case 4: // NAND
                c->values[i] = !(c->values[i - 1] && c->values[i - 2]);
                break;
            case 5: // NOR
                c->values[i] = !(c->values[i - 1] || c->values[i - 2]);
                break;
            case 6: // XNOR
                c->values[i] = !(c->values[i - 1] ^ c->values[i - 2]);
                break;
        }
    }
    return c->values[c->n - 1];
}

int main() {
    int n, i;
    circuit *c;
    scanf("%d", &n);
    c = circuit_create(n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &c->gates[i], &c->values[i]);
    }
    printf("%d\n", circuit_evaluate(c));
    circuit_destroy(c);
    return 0;
}