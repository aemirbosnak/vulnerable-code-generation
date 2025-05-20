//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float resistance;
} Resistor;

typedef struct {
    Resistor* resistors;
    int count;
} Circuit;

Circuit create_circuit(int count) {
    Circuit circuit;
    circuit.resistors = (Resistor*)malloc(sizeof(Resistor) * count);
    circuit.count = count;
    
    for (int i = 0; i < count; i++) {
        printf("Enter resistance of resistor %d (in Ohms): ", i + 1);
        scanf("%f", &(circuit.resistors[i].resistance));
    }
    
    return circuit;
}

float calculate_series_resistance(Circuit circuit) {
    float total_resistance = 0.0;
    for (int i = 0; i < circuit.count; i++) {
        total_resistance += circuit.resistors[i].resistance;
    }
    return total_resistance;
}

float calculate_parallel_resistance(Circuit circuit) {
    float total_reciprocal = 0.0;
    for (int i = 0; i < circuit.count; i++) {
        total_reciprocal += 1.0 / circuit.resistors[i].resistance;
    }
    return 1.0 / total_reciprocal;
}

void free_circuit(Circuit circuit) {
    free(circuit.resistors);
}

int main() {
    int count, choice;
    
    printf("Welcome to the Circuit Simulator!\n");
    printf("How many resistors do you want to include in your circuit? ");
    scanf("%d", &count);
    
    Circuit circuit = create_circuit(count);

    printf("Select your circuit type:\n");
    printf("1. Series Circuit\n");
    printf("2. Parallel Circuit\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    float total_resistance;
    
    if (choice == 1) {
        total_resistance = calculate_series_resistance(circuit);
        printf("Total Resistance in Series: %.2f Ohms\n", total_resistance);
    } else if (choice == 2) {
        total_resistance = calculate_parallel_resistance(circuit);
        printf("Total Resistance in Parallel: %.2f Ohms\n", total_resistance);
    } else {
        printf("Invalid choice! Please restart the program and choose 1 or 2.\n");
    }

    free_circuit(circuit);

    printf("Thank you for using the Circuit Simulator!\n");
    return 0;
}