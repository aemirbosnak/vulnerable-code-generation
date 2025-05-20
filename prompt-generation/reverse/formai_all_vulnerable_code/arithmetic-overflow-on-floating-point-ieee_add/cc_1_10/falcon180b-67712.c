//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_COMPONENTS 100
#define MAX_CONNECTIONS 1000
#define PI 3.14159265358979323846

typedef struct {
    double value;
    int index;
} Node;

typedef struct {
    char name[20];
    double value;
    int index;
} Component;

typedef struct {
    int node1;
    int node2;
    double value;
} Connection;

Node *nodes;
Component *components;
Connection *connections;

int num_nodes, num_components, num_connections;

void create_node(double value) {
    nodes = realloc(nodes, sizeof(Node) * ++num_nodes);
    nodes[num_nodes - 1].value = value;
    nodes[num_nodes - 1].index = num_nodes - 1;
}

void create_component(char *name, double value) {
    components = realloc(components, sizeof(Component) * ++num_components);
    strcpy(components[num_components - 1].name, name);
    components[num_components - 1].value = value;
    components[num_components - 1].index = num_components - 1;
}

void create_connection(int node1, int node2, double value) {
    connections = realloc(connections, sizeof(Connection) * ++num_connections);
    connections[num_connections - 1].node1 = node1;
    connections[num_connections - 1].node2 = node2;
    connections[num_connections - 1].value = value;
}

void simulate() {
    for (int i = 0; i < num_nodes; i++) {
        double sum = 0;
        for (int j = 0; j < num_connections; j++) {
            if (connections[j].node1 == i || connections[j].node2 == i) {
                sum += connections[j].value;
            }
        }
        nodes[i].value = sum;
    }
}

int main() {
    create_node(5);
    create_node(10);
    create_component("resistor", 100);
    create_connection(0, 1, 100);
    simulate();
    printf("Node 1 value: %lf\n", nodes[0].value);
    printf("Node 2 value: %lf\n", nodes[1].value);
    return 0;
}