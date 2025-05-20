//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COMPONENTS 1000

typedef struct {
    double resistance;
    double capacitance;
    double inductance;
    double voltage;
    double current;
} Component;

typedef struct {
    int num_components;
    Component components[MAX_COMPONENTS];
} Circuit;

void read_circuit(Circuit *circuit) {
    FILE *fp;
    char filename[100];
    int i;

    printf("Enter circuit filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_COMPONENTS; i++) {
        if (fscanf(fp, "%lf %lf %lf %lf %lf\n", &circuit->components[i].resistance, &circuit->components[i].capacitance, &circuit->components[i].inductance, &circuit->components[i].voltage, &circuit->components[i].current)!= 5) {
            printf("Error reading circuit file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

void simulate_circuit(Circuit *circuit) {
    int i;
    double dt = 0.001;

    for (i = 0; i < circuit->num_components; i++) {
        double resistance = circuit->components[i].resistance;
        double capacitance = circuit->components[i].capacitance;
        double inductance = circuit->components[i].inductance;
        double voltage = circuit->components[i].voltage;
        double current = circuit->components[i].current;

        double delta_voltage = (resistance * current + capacitance * current * dt - voltage) / dt;
        double delta_current = (voltage - resistance * current - inductance * current * dt) / dt;

        circuit->components[i].voltage += delta_voltage;
        circuit->components[i].current += delta_current;
    }
}

void print_circuit(Circuit *circuit) {
    int i;

    for (i = 0; i < circuit->num_components; i++) {
        printf("Component %d:\n", i);
        printf("Resistance: %lf\n", circuit->components[i].resistance);
        printf("Capacitance: %lf\n", circuit->components[i].capacitance);
        printf("Inductance: %lf\n", circuit->components[i].inductance);
        printf("Voltage: %lf\n", circuit->components[i].voltage);
        printf("Current: %lf\n\n", circuit->components[i].current);
    }
}

int main() {
    Circuit circuit;

    read_circuit(&circuit);

    int num_steps;

    printf("Enter number of simulation steps: ");
    scanf("%d", &num_steps);

    for (int i = 0; i < num_steps; i++) {
        simulate_circuit(&circuit);
    }

    print_circuit(&circuit);

    return 0;
}