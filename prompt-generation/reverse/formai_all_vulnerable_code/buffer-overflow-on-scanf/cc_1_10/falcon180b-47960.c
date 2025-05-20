//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double value;
    double voltage;
    double current;
} component;

void node_analysis(int n, component* nodes) {
    component* node = nodes;
    int i;
    double sum = 0;

    for (i = 0; i < n; i++) {
        sum += node->current;
        node++;
    }

    if (sum!= 0) {
        printf("error: current not conserved\n");
        exit(1);
    }
}

void solve_circuit(int n, component* nodes) {
    int i;
    double sum = 0;
    component* node = nodes;

    for (i = 0; i < n; i++) {
        sum += node->current;
        node++;
    }

    if (sum == 0) {
        printf("error: no current in circuit\n");
        exit(1);
    }

    node = nodes;

    for (i = 0; i < n; i++) {
        double voltage_drop = node->voltage - node->value;

        node->current = (node->value - node->voltage) / node->value;

        node->voltage -= voltage_drop;

        node++;
    }
}

int main() {
    int n;
    component* nodes;

    printf("enter number of nodes: ");
    scanf("%d", &n);

    nodes = (component*) malloc(n * sizeof(component));

    int i;
    for (i = 0; i < n; i++) {
        printf("enter node %d:\n", i + 1);
        printf("value: ");
        scanf("%lf", &nodes[i].value);
        printf("voltage: ");
        scanf("%lf", &nodes[i].voltage);
        printf("current: ");
        scanf("%lf", &nodes[i].current);
    }

    solve_circuit(n, nodes);

    printf("node analysis:\n");
    node_analysis(n, nodes);

    free(nodes);

    return 0;
}