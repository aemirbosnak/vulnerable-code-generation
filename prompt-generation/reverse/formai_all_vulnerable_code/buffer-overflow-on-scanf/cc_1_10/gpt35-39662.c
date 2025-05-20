//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: unmistakable
#include <stdio.h>

#define MAX_NODES 1000
#define MAX_NAME_LEN 100

typedef struct {
    int node1, node2;
    double value;
} Component;

typedef struct {
    char name[MAX_NAME_LEN];
    int node1, node2;
    double value;
} NamedComponent;

int num_nodes, num_components, num_named_components;
Component components[MAX_NODES];
NamedComponent named_components[MAX_NODES];

void read_circuit() {
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter number of components: ");
    scanf("%d", &num_components);

    for (int i = 0; i < num_components; ++i) {
        printf("Enter component %d (node1, node2, value): ", i + 1);
        scanf("%d%d%lf", &components[i].node1, &components[i].node2, &components[i].value);
    }

    printf("Enter number of named components: ");
    scanf("%d", &num_named_components);

    for (int i = 0; i < num_named_components; ++i) {
        printf("Enter named component %d (name, node1, node2, value): ", i + 1);
        scanf("%s%d%d%lf", named_components[i].name, &named_components[i].node1, &named_components[i].node2, &named_components[i].value);
    }
}

void print_circuit() {
    printf("Nodes: %d\n", num_nodes);
    printf("Components:\n");
    for (int i = 0; i < num_components; ++i) {
        printf(" %d %d %g\n", components[i].node1, components[i].node2, components[i].value);
    }
    printf("Named Components:\n");
    for (int i = 0; i < num_named_components; ++i) {
        printf(" %s %d %d %g\n", named_components[i].name, named_components[i].node1, named_components[i].node2, named_components[i].value);
    }
}

int main() {
    read_circuit();
    print_circuit();
    return 0;
}