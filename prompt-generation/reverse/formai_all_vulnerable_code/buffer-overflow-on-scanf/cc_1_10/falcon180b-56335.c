//Falcon-180B DATASET v1.0 Category: Classical Circuit Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_CHAR 100
#define MAX_STRING 1000

typedef struct {
    int resistance;
    int capacitance;
    int inductance;
} CircuitElement;

CircuitElement circuit[MAX_ELEMENTS];
int num_elements;

void add_element() {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }

    printf("Enter resistance in ohms: ");
    scanf("%d", &circuit[num_elements].resistance);
    printf("Enter capacitance in farads: ");
    scanf("%d", &circuit[num_elements].capacitance);
    printf("Enter inductance in henries: ");
    scanf("%d", &circuit[num_elements].inductance);

    num_elements++;
}

void simulate_circuit() {
    int i, j;
    double total_resistance = 0.0;
    double total_capacitance = 0.0;
    double total_inductance = 0.0;

    for (i = 0; i < num_elements; i++) {
        total_resistance += circuit[i].resistance;
        total_capacitance += circuit[i].capacitance;
        total_inductance += circuit[i].inductance;
    }

    printf("Total resistance: %.2f ohms\n", total_resistance);
    printf("Total capacitance: %.2f farads\n", total_capacitance);
    printf("Total inductance: %.2f henries\n", total_inductance);
}

int main() {
    int choice;

    do {
        printf("Circuit Simulator\n");
        printf("1. Add element\n");
        printf("2. Simulate circuit\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_element();
                break;
            case 2:
                simulate_circuit();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}