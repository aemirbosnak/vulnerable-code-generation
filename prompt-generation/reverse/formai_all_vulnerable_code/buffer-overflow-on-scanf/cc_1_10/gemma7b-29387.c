//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CIRcuits 10

typedef struct Circuit {
    char name[20];
    double resistance;
    double capacitance;
    double inductance;
    double voltage;
    double current;
} Circuit;

Circuit circuits[MAX_CIRcuits];

void simulate_circuit(Circuit *circuit) {
    double time = 0.0;
    double dt = 0.01;
    double v = circuit->voltage;
    double i = circuit->current;

    while (time < 10.0) {
        double voltage_across_capacitor = v * circuit->capacitance;
        double voltage_across_inductor = i * circuit->inductance;
        double total_voltage = voltage_across_capacitor + voltage_across_inductor;

        circuit->current = total_voltage / circuit->resistance;

        time += dt;
    }

    printf("Circuit name: %s\n", circuit->name);
    printf("Final current: %.2f A\n", circuit->current);
}

int main() {
    int num_circuits = 0;

    while (num_circuits < MAX_CIRcuits) {
        Circuit *circuit = &circuits[num_circuits];

        printf("Enter circuit name: ");
        scanf("%s", circuit->name);

        printf("Enter resistance (ohms): ");
        scanf("%lf", &circuit->resistance);

        printf("Enter capacitance (farads): ");
        scanf("%lf", &circuit->capacitance);

        printf("Enter inductance (henrys): ");
        scanf("%lf", &circuit->inductance);

        printf("Enter voltage (volts): ");
        scanf("%lf", &circuit->voltage);

        num_circuits++;
    }

    for (int i = 0; i < num_circuits; i++) {
        simulate_circuit(&circuits[i]);
    }

    return 0;
}