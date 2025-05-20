//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ELEMENTS 100

typedef struct {
    double resistance;
    double capacitance;
    double inductance;
    double voltage;
    double current;
} Element;

Element elements[MAX_ELEMENTS];
int num_elements;

void add_element(double resistance, double capacitance, double inductance) {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Cannot add more elements.\n");
        return;
    }

    elements[num_elements].resistance = resistance;
    elements[num_elements].capacitance = capacitance;
    elements[num_elements].inductance = inductance;
    elements[num_elements].voltage = 0;
    elements[num_elements].current = 0;

    num_elements++;
}

void connect_elements(int element1, int element2) {
    if (element1 < 0 || element1 >= num_elements || element2 < 0 || element2 >= num_elements) {
        printf("Error: Invalid element number.\n");
        return;
    }

    if (elements[element1].voltage == elements[element2].voltage) {
        printf("Error: Cannot connect elements with the same voltage.\n");
        return;
    }

    elements[element1].voltage = elements[element2].voltage;
}

void simulate() {
    for (int i = 0; i < num_elements; i++) {
        double current_element = elements[i].current;
        double voltage_diff = elements[i].voltage - elements[i - 1].voltage;

        if (voltage_diff > 0) {
            current_element += voltage_diff / elements[i].resistance;
        } else {
            current_element -= voltage_diff / elements[i].resistance;
        }

        elements[i].current = current_element;
    }
}

int main() {
    add_element(100, 1e-6, 0);
    add_element(200, 1e-6, 0);
    add_element(300, 1e-6, 0);
    add_element(400, 1e-6, 0);
    add_element(500, 1e-6, 0);

    connect_elements(0, 1);
    connect_elements(1, 2);
    connect_elements(2, 3);
    connect_elements(3, 4);

    simulate();

    for (int i = 0; i < num_elements; i++) {
        printf("Element %d: Voltage = %.4f, Current = %.4f\n", i + 1, elements[i].voltage, elements[i].current);
    }

    return 0;
}