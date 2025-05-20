//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Component {
    char name[20];
    char type[10]; // resistor, capacitor, inductor, voltage_source, current_source
    float value; // resistance in Ohms, capacitance in Farads, etc.
    struct Component* next;
} Component;

typedef struct Circuit {
    Component* head;
} Circuit;

// Function to create a new component
Component* create_component(const char* name, const char* type, float value) {
    Component* new_component = (Component*)malloc(sizeof(Component));
    strcpy(new_component->name, name);
    strcpy(new_component->type, type);
    new_component->value = value;
    new_component->next = NULL;
    return new_component;
}

// Function to add a component to the circuit
void add_component(Circuit* circuit, Component* component) {
    component->next = circuit->head;
    circuit->head = component;
}

// Function to display the circuit components
void display_circuit(Circuit* circuit) {
    Component* current = circuit->head;
    printf("Circuit Components:\n");
    while (current != NULL) {
        printf("Name: %s, Type: %s, Value: %.2f\n", current->name, current->type, current->value);
        current = current->next;
    }
}

// Function to simulate the circuit (very basic simulation for demonstration)
void simulate_circuit(Circuit* circuit) {
    float total_resistance = 0.0;
    float total_capacitance = 0.0;

    Component* current = circuit->head;
    
    while (current != NULL) {
        if (strcmp(current->type, "resistor") == 0) {
            total_resistance += current->value; // adding resistances in series
        } else if (strcmp(current->type, "capacitor") == 0) {
            total_capacitance += current->value; // noting capacitance
        }
        current = current->next;
    }

    printf("Total Resistance: %.2f Ohms\n", total_resistance);
    printf("Total Capacitance: %.2f Farads\n", total_capacitance);
}

// Function to free the circuit memory
void free_circuit(Circuit* circuit) {
    Component* current = circuit->head;
    while (current != NULL) {
        Component* temp = current;
        current = current->next;
        free(temp);
    }
    free(circuit);
}

// Main function
int main() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->head = NULL;

    int choice;
    char name[20], type[10];
    float value;

    while (1) {
        printf("Circuit Simulator Menu:\n");
        printf("1. Add Component\n");
        printf("2. Display Circuit\n");
        printf("3. Simulate Circuit\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter component name: ");
                scanf("%s", name);
                printf("Enter component type (resistor/capacitor/inductor/voltage_source/current_source): ");
                scanf("%s", type);
                printf("Enter component value: ");
                scanf("%f", &value);
                add_component(circuit, create_component(name, type, value));
                break;
            case 2:
                display_circuit(circuit);
                break;
            case 3:
                simulate_circuit(circuit);
                break;
            case 4:
                free_circuit(circuit);
                printf("Exiting the circuit simulator...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}