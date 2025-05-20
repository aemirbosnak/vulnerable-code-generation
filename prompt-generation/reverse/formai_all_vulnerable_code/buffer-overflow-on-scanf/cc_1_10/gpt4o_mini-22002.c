//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct Resistor {
    int id;
    float resistance; // Resistance in ohms
} Resistor;

Resistor* create_resistor(int id, float resistance) {
    Resistor* r = malloc(sizeof(Resistor));
    r->id = id;
    r->resistance = resistance;
    return r;
}

float calculate_total_resistance(Resistor** resistors, int count) {
    float total_resistance = 0.0;
    for (int i = 0; i < count; i++) {
        total_resistance += resistors[i]->resistance;
    }
    return total_resistance;
}

void free_resistors(Resistor** resistors, int count) {
    for (int i = 0; i < count; i++) {
        free(resistors[i]);
    }
}

void display_resistors(Resistor** resistors, int count) {
    printf("\nResistor List:\n");
    for (int i = 0; i < count; i++) {
        printf("Resistor %d: %.2f Ohms\n", resistors[i]->id, resistors[i]->resistance);
    }
    printf("\n");
}

int main() {
    int num_resistors;
    
    printf("Welcome to the Simple Circuit Simulator!\n");
    printf("How many resistors do you want in your series circuit? ");
    scanf("%d", &num_resistors);

    if (num_resistors <= 0) {
        printf("Please enter a positive number of resistors.\n");
        return 1;
    }

    Resistor** resistors = malloc(num_resistors * sizeof(Resistor*));

    for (int i = 0; i < num_resistors; i++) {
        float resistance_value;
        printf("Enter resistance value for Resistor %d (in Ohms): ", i + 1);
        scanf("%f", &resistance_value);
        resistors[i] = create_resistor(i + 1, resistance_value);
    }

    display_resistors(resistors, num_resistors);

    float total_resistance = calculate_total_resistance(resistors, num_resistors);
    printf("Total Resistance of the circuit: %.2f Ohms\n", total_resistance);

    free_resistors(resistors, num_resistors);
    free(resistors);

    printf("Thanks for using the Circuit Simulator! Have a great day!\n");
    return 0;
}