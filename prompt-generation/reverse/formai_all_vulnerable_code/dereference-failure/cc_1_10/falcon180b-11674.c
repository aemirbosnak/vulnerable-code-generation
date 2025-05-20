//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 200

typedef struct component {
    int pins[2];
    double value;
} component;

typedef struct node {
    int num_components;
    component *components;
} node;

void add_component(node *n, int pin1, int pin2, double value) {
    n->num_components++;
    n->components = realloc(n->components, sizeof(component) * n->num_components);
    n->components[n->num_components - 1].pins[0] = pin1;
    n->components[n->num_components - 1].pins[1] = pin2;
    n->components[n->num_components - 1].value = value;
}

void simulate(node *n, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < n[i].num_components; j++) {
            int pin1 = n[i].components[j].pins[0];
            int pin2 = n[i].components[j].pins[1];
            double value = n[i].components[j].value;

            if (pin1 == -1) {
                n[i].components[j].value = 5.0;
            } else if (pin2 == -1) {
                n[i].components[j].value = 0.0;
            } else {
                n[i].components[j].value = ((n[pin1].components[0].value * value) + (n[pin2].components[0].value * (1.0 - value))) / (1.0 + value);
            }
        }
    }
}

void print_nodes(node *n, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < n[i].num_components; j++) {
            printf("%.2f ", n[i].components[j].value);
        }
        printf("\n");
    }
}

int main() {
    node n[MAX_NODES];
    int num_nodes = 0;

    add_component(&n[num_nodes], -1, 0, 5.0); // voltage source
    num_nodes++;

    add_component(&n[num_nodes], 0, 1, 1000.0); // resistor
    num_nodes++;

    add_component(&n[num_nodes], 1, -1, 0.0); // ground
    num_nodes++;

    simulate(n, num_nodes);
    print_nodes(n, num_nodes);

    return 0;
}