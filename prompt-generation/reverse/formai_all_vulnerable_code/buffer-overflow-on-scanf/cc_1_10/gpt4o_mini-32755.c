//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Component {
    char name[20];
    float value; // For resistors, it's resistance; for capacitors, it's capacitance.
    struct Component* next; // For chaining components
} Component;

typedef struct Circuit {
    Component* head; // Head of the component linked list
    float total_resistance; // For calculating total resistance in series
    float total_capacitance; // For calculating total capacitance in parallel
} Circuit;

// Function prototypes
Circuit* create_circuit();
Component* create_component(const char* name, float value);
void add_component(Circuit* circuit, Component* component);
void calculate_totals(Circuit* circuit);
void display_circuit(Circuit* circuit);
void free_circuit(Circuit* circuit);

int main() {
    Circuit* circuit = create_circuit();
    char command[20];
    
    while (1) {
        printf("Enter command (add, calculate, display, exit): ");
        scanf("%s", command);
        
        if (strcmp(command, "add") == 0) {
            char name[20];
            float value;
            printf("Enter component name: ");
            scanf("%s", name);
            printf("Enter component value: ");
            scanf("%f", &value);
            Component* component = create_component(name, value);
            add_component(circuit, component);
        } else if (strcmp(command, "calculate") == 0) {
            calculate_totals(circuit);
        } else if (strcmp(command, "display") == 0) {
            display_circuit(circuit);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    free_circuit(circuit);
    return 0;
}

Circuit* create_circuit() {
    Circuit* circuit = (Circuit*)malloc(sizeof(Circuit));
    circuit->head = NULL;
    circuit->total_resistance = 0.0;
    circuit->total_capacitance = 0.0;
    return circuit;
}

Component* create_component(const char* name, float value) {
    Component* component = (Component*)malloc(sizeof(Component));
    strncpy(component->name, name, 20);
    component->value = value;
    component->next = NULL;
    return component;
}

void add_component(Circuit* circuit, Component* component) {
    component->next = circuit->head;
    circuit->head = component;
    printf("Added component: %s with value: %.2f\n", component->name, component->value);
}

void calculate_totals(Circuit* circuit) {
    circuit->total_resistance = 0.0;
    circuit->total_capacitance = 0.0;

    Component* current = circuit->head;
    while (current != NULL) {
        if (strstr(current->name, "R") != NULL) {
            circuit->total_resistance += current->value; // Simple series resistance
        } else if (strstr(current->name, "C") != NULL) {
            circuit->total_capacitance += current->value; // Simple parallel capacitance
        }
        current = current->next;
    }

    printf("Total Resistance (series): %.2f Ohms\n", circuit->total_resistance);
    printf("Total Capacitance (parallel): %.2f Farads\n", circuit->total_capacitance);
}

void display_circuit(Circuit* circuit) {
    printf("Circuit Components:\n");
    Component* current = circuit->head;
    while (current != NULL) {
        printf(" - %s: %.2f\n", current->name, current->value);
        current = current->next;
    }
}

void free_circuit(Circuit* circuit) {
    Component* current = circuit->head;
    while (current != NULL) {
        Component* temp = current;
        current = current->next;
        free(temp);
    }
    free(circuit);
}