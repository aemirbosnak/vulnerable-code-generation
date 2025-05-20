//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100
#define MAX_CONNECTIONS 10

typedef struct {
    char name[20];
    float value; // Ohms for resistors, Farads for capacitors, Volts for voltage sources
    int type; // 0 = resistor, 1 = capacitor, 2 = voltage source
} Component;

typedef struct {
    int component1;
    int component2;
} Connection;

Component components[MAX_COMPONENTS];
Connection connections[MAX_CONNECTIONS];
int component_count = 0;
int connection_count = 0;

void add_component(char *name, float value, int type) {
    if (component_count < MAX_COMPONENTS) {
        strcpy(components[component_count].name, name);
        components[component_count].value = value;
        components[component_count].type = type;
        component_count++;
    } else {
        printf("Max component limit reached!\n");
    }
}

void add_connection(int comp1, int comp2) {
    if (connection_count < MAX_CONNECTIONS) {
        connections[connection_count].component1 = comp1;
        connections[connection_count].component2 = comp2;
        connection_count++;
    } else {
        printf("Max connections limit reached!\n");
    }
}

void calculate_equivalent_resistance() {
    float total_resistance = 0.0;
    for (int i = 0; i < connection_count; i++) {
        int comp1 = connections[i].component1;
        int comp2 = connections[i].component2;
        
        if (components[comp1].type == 0 && components[comp2].type == 0) {
            // Resistors in series
            total_resistance += (components[comp1].value + components[comp2].value);
        } else if (components[comp1].type == 0 || components[comp2].type == 0) {
            // Resistor in parallel
            float r1 = components[comp1].type == 0 ? components[comp1].value : components[comp2].value;
            float r2 = components[comp1].type == 0 ? components[comp2].value : components[comp1].value;
            total_resistance += (1 / ((1 / r1) + (1 / r2)));
        }
    }
    printf("Total Equivalent Resistance: %.2f Ohms\n", total_resistance);
}

void calculate_equivalent_capacitance() {
    float total_capacitance = 0.0;
    for (int i = 0; i < connection_count; i++) {
        int comp1 = connections[i].component1;
        int comp2 = connections[i].component2;

        if (components[comp1].type == 1 && components[comp2].type == 1) {
            // Capacitors in series
            total_capacitance += (1 / ((1 / components[comp1].value) + (1 / components[comp2].value)));
        } else if (components[comp1].type == 1 || components[comp2].type == 1) {
            // Capacitor in parallel
            float c1 = components[comp1].type == 1 ? components[comp1].value : components[comp2].value;
            float c2 = components[comp1].type == 1 ? components[comp2].value : components[comp1].value;
            total_capacitance += (c1 + c2);
        }
    }
    printf("Total Equivalent Capacitance: %.2f Farads\n", total_capacitance);
}

void display_components() {
    printf("Components:\n");
    for (int i = 0; i < component_count; i++) {
        char *type;
        if (components[i].type == 0) {
            type = "Resistor";
        } else if (components[i].type == 1) {
            type = "Capacitor";
        } else {
            type = "Voltage Source";
        }
        printf("%d: %s (%.2f) - %s\n", i, components[i].name, components[i].value, type);
    }
}

int main() {
    int choice;
    char name[20];
    float value;
    int type;

    while (1) {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Component\n");
        printf("2. Add Connection\n");
        printf("3. Calculate Equivalent Resistance\n");
        printf("4. Calculate Equivalent Capacitance\n");
        printf("5. Display Components\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter component name: ");
                scanf("%s", name);
                printf("Enter component value: ");
                scanf("%f", &value);
                printf("Enter component type (0 for Resistor, 1 for Capacitor, 2 for Voltage Source): ");
                scanf("%d", &type);
                add_component(name, value, type);
                break;
            case 2:
                printf("Enter two component indices to connect (0 to %d): ", component_count - 1);
                int comp1, comp2;
                scanf("%d %d", &comp1, &comp2);
                if (comp1 < component_count && comp2 < component_count) {
                    add_connection(comp1, comp2);
                } else {
                    printf("Invalid component indices!\n");
                }
                break;
            case 3:
                calculate_equivalent_resistance();
                break;
            case 4:
                calculate_equivalent_capacitance();
                break;
            case 5:
                display_components();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}