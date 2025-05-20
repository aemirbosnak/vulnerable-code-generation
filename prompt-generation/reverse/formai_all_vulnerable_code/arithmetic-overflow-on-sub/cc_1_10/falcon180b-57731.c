//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 1000
#define MAX_NODES 10000
#define MAX_EDGES 20000

typedef struct component_s {
    int num_nodes;
    int *nodes;
    float *values;
} component_t;

typedef struct graph_s {
    int num_components;
    component_t *components;
} graph_t;

void add_component(graph_t *graph) {
    graph->num_components++;
    graph->components = realloc(graph->components, sizeof(component_t) * graph->num_components);
}

void add_node(component_t *component, int node) {
    component->nodes = realloc(component->nodes, sizeof(int) * ++component->num_nodes);
    component->nodes[component->num_nodes - 1] = node;
}

void add_edge(component_t *component, int from_node, int to_node, float value) {
    component->values = realloc(component->values, sizeof(float) * ++component->num_nodes);
    component->values[component->num_nodes - 1] = value;
}

int main() {
    graph_t graph;
    graph.num_components = 0;
    graph.components = malloc(sizeof(component_t));

    component_t *component1 = &graph.components[0];
    add_node(component1, 1);
    add_node(component1, 2);
    add_edge(component1, 1, 2, 1.0);

    component_t *component2 = &graph.components[1];
    add_node(component2, 3);
    add_node(component2, 4);
    add_edge(component2, 3, 4, 1.0);

    printf("Number of components: %d\n", graph.num_components);

    for (int i = 0; i < graph.num_components; i++) {
        printf("Component %d:\n", i);
        for (int j = 0; j < graph.components[i].num_nodes; j++) {
            printf("%d (%f)\n", graph.components[i].nodes[j], graph.components[i].values[j]);
        }
    }

    return 0;
}