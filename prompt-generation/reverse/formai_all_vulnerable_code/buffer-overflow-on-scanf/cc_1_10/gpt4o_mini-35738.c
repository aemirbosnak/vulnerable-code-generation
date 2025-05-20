//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100

typedef enum {
    RESISTOR,
    CAPACITOR,
    POWER_SOURCE,
    NONE
} ComponentType;

typedef struct {
    ComponentType type;
    char name[20];
    float value; // Ohm or Farad or Volt
} Component;

Component circuit[MAX_COMPONENTS];
int component_count = 0;

void add_component(ComponentType type, const char *name, float value) {
    if (component_count < MAX_COMPONENTS) {
        circuit[component_count].type = type;
        strncpy(circuit[component_count].name, name, sizeof(circuit[component_count].name) - 1);
        circuit[component_count].value = value;
        component_count++;
        printf("Added %s: %s with value %.2f\n", (type == RESISTOR) ? "Resistor" : 
                                                  (type == CAPACITOR) ? "Capacitor" : "Power Source", 
                                                  name, value);
    } else {
        printf("Unable to add component: Circuit full!\n");
    }
}

void display_circuit() {
    printf("\nCurrent Circuit Components:\n");
    for (int i = 0; i < component_count; i++) {
        const char *type_str = (circuit[i].type == RESISTOR) ? "Resistor" :
                               (circuit[i].type == CAPACITOR) ? "Capacitor" :
                               (circuit[i].type == POWER_SOURCE) ? "Power Source" : "Unknown";
        printf("%s: %s with value %.2f\n", type_str, circuit[i].name, circuit[i].value);
    }
}

float calculate_total_resistance() {
    float total_resistance = 0.0;
    for (int i = 0; i < component_count; i++) {
        if (circuit[i].type == RESISTOR) {
            total_resistance += circuit[i].value; // Simple series assumption
        }
    }
    return total_resistance;
}

void interactive_menu() {
    int choice;
    char name[20];
    float value;

    do {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Add Power Source\n");
        printf("4. Display Circuit\n");
        printf("5. Calculate Total Resistance\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Resistor Name: ");
                scanf("%s", name);
                printf("Enter Resistor Value (Ohm): ");
                scanf("%f", &value);
                add_component(RESISTOR, name, value);
                break;
            case 2:
                printf("Enter Capacitor Name: ");
                scanf("%s", name);
                printf("Enter Capacitor Value (Farad): ");
                scanf("%f", &value);
                add_component(CAPACITOR, name, value);
                break;
            case 3:
                printf("Enter Power Source Name: ");
                scanf("%s", name);
                printf("Enter Power Source Value (Volt): ");
                scanf("%f", &value);
                add_component(POWER_SOURCE, name, value);
                break;
            case 4:
                display_circuit();
                break;
            case 5:
                printf("Total Resistance: %.2f Ohms\n", calculate_total_resistance());
                break;
            case 0:
                printf("Exiting the simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 0);
}

int main() {
    printf("Welcome to the Circuit Simulator!\n");
    interactive_menu();
    return 0;
}