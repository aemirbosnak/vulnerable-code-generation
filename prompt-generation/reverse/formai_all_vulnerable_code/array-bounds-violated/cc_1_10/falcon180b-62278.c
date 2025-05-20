//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_ELEMENTS 1000

typedef struct {
    double resistance;
    double capacitance;
    double voltage;
} CircuitElement;

CircuitElement circuit[MAX_ELEMENTS];
int num_elements;

void add_resistor(double resistance) {
    circuit[num_elements].resistance = resistance;
    circuit[num_elements].capacitance = 0.0;
    circuit[num_elements].voltage = 0.0;
    num_elements++;
}

void add_capacitor(double capacitance) {
    circuit[num_elements].resistance = 0.0;
    circuit[num_elements].capacitance = capacitance;
    circuit[num_elements].voltage = 0.0;
    num_elements++;
}

void add_voltage_source(double voltage) {
    circuit[num_elements].resistance = 0.0;
    circuit[num_elements].capacitance = 0.0;
    circuit[num_elements].voltage = voltage;
    num_elements++;
}

void simulate(double delta_t) {
    for (int i = 0; i < num_elements; i++) {
        if (circuit[i].resistance > 0.0) {
            circuit[i].voltage += (circuit[i].voltage - circuit[i - 1].voltage) * delta_t / circuit[i].resistance;
        } else if (circuit[i].capacitance > 0.0) {
            circuit[i].voltage += (circuit[i + 1].voltage - circuit[i].voltage) * delta_t / circuit[i].capacitance;
        }
    }
}

int main() {
    srand(time(NULL));
    num_elements = 0;
    add_resistor(1000.0);
    add_resistor(1000.0);
    add_capacitor(0.1);
    add_voltage_source(5.0);
    for (int i = 0; i < 100; i++) {
        simulate(0.01);
        printf("Time: %f\tVoltage: %f\n", i * 0.01, circuit[num_elements - 1].voltage);
    }
    return 0;
}