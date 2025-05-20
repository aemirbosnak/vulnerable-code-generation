//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_COMPONENTS 100
#define MAX_NODES 1000
#define PI 3.14159265358979323846

typedef struct component {
    char name[20];
    int num_nodes;
    int nodes[MAX_NODES];
    double values[MAX_NODES];
} Component;

typedef struct circuit {
    int num_components;
    Component components[MAX_COMPONENTS];
} Circuit;

void add_component(Circuit *circuit) {
    printf("Enter component name: ");
    scanf("%s", circuit->components[circuit->num_components].name);
    printf("Enter number of nodes: ");
    scanf("%d", &circuit->components[circuit->num_components].num_nodes);
    for (int i = 0; i < circuit->components[circuit->num_components].num_nodes; i++) {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &circuit->components[circuit->num_components].nodes[i]);
        printf("Enter value for node %d: ", circuit->components[circuit->num_components].nodes[i]);
        scanf("%lf", &circuit->components[circuit->num_components].values[i]);
    }
    circuit->num_components++;
}

void simulate_circuit(Circuit *circuit) {
    for (int i = 0; i < circuit->num_components; i++) {
        Component *component = &circuit->components[i];
        double sum = 0.0;
        for (int j = 0; j < component->num_nodes; j++) {
            int node = component->nodes[j];
            sum += component->values[j] * circuit->components[node].values[0];
        }
        circuit->components[i].values[0] = sum;
    }
}

int main() {
    Circuit circuit;
    circuit.num_components = 0;
    while (1) {
        printf("\n1. Add component\n2. Simulate circuit\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_component(&circuit);
            break;
        case 2:
            simulate_circuit(&circuit);
            printf("\nSimulation complete.\n");
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}