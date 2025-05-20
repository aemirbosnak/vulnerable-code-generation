//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char name[10];
    int value;
    int num_connections;
    struct connection *connections;
} component;

typedef struct {
    int from;
    int to;
    int resistance;
} connection;

int main() {
    int num_components, num_connections;
    component *components;
    connection *connections;

    // Parse input file
    FILE *file = fopen("circuit.txt", "r");
    fscanf(file, "%d\n", &num_components);
    components = malloc(num_components * sizeof(component));
    for (int i = 0; i < num_components; i++) {
        fscanf(file, "%s %d %d\n", components[i].name, &components[i].value, &components[i].num_connections);
        components[i].connections = malloc(components[i].num_connections * sizeof(connection));
    }
    fscanf(file, "%d\n", &num_connections);
    connections = malloc(num_connections * sizeof(connection));
    for (int i = 0; i < num_connections; i++) {
        fscanf(file, "%d %d %d\n", &connections[i].from, &connections[i].to, &connections[i].resistance);
    }
    fclose(file);

    // Calculate circuit properties
    double total_resistance = 0;
    for (int i = 0; i < num_connections; i++) {
        total_resistance += connections[i].resistance;
    }
    double total_voltage = 0;
    double total_current = 0;
    for (int i = 0; i < num_components; i++) {
        total_voltage += components[i].value;
        total_current += components[i].value / total_resistance;
    }

    // Print circuit properties
    printf("Total resistance: %.2f\n", total_resistance);
    printf("Total voltage: %.2f\n", total_voltage);
    printf("Total current: %.2f\n", total_current);

    return 0;
}