//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct Component {
    char type; // 'R' for resistor, 'C' for capacitor
    double value; // ohms for resistor, farads for capacitor
    struct Component *next;
} Component;

Component *create_component(char type, double value) {
    Component *new_component = (Component *)malloc(sizeof(Component));
    new_component->type = type;
    new_component->value = value;
    new_component->next = NULL;
    return new_component;
}

void free_components(Component *head) {
    Component *current = head;
    Component *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

double calculate_total_resistance(Component *head) {
    double total_resistance = 0.0;
    Component *current = head;
    while (current != NULL) {
        if (current->type == 'R') {
            total_resistance += 1.0 / current->value; // 1 / Rt = 1 / R1 + 1 / R2 + ...
        }
        current = current->next;
    }
    return (total_resistance == 0) ? 0 : 1.0 / total_resistance; // Rt
}

double calculate_total_capacitance(Component *head) {
    double total_capacitance = 0.0;
    Component *current = head;
    while (current != NULL) {
        if (current->type == 'C') {
            total_capacitance += current->value; // Ct = C1 + C2 + ...
        }
        current = current->next;
    }
    return total_capacitance;
}

void display_components(Component *head) {
    Component *current = head;
    while (current != NULL) {
        if (current->type == 'R') {
            printf("Resistor: %.2f Ohms\n", current->value);
        } else if (current->type == 'C') {
            printf("Capacitor: %.2f Farads\n", current->value);
        }
        current = current->next;
    }
}

int main() {
    Component *head = NULL, *tail = NULL;
    char type;
    double value;

    printf("Welcome to the Circuit Simulator!\n");
    
    while (1) {
        printf("Enter component type (R for Resistor, C for Capacitor, Q to Quit): ");
        scanf(" %c", &type);
        
        if (type == 'Q') break;

        printf("Enter component value: ");
        scanf("%lf", &value);

        Component *new_component = create_component(type, value);
        if (head == NULL) {
            head = new_component;
            tail = new_component;
        } else {
            tail->next = new_component;
            tail = new_component;
        }
    }

    printf("\nComponents in the circuit:\n");
    display_components(head);

    double total_resistance = calculate_total_resistance(head);
    double total_capacitance = calculate_total_capacitance(head);

    printf("\nTotal Resistance: %.2f Ohms\n", total_resistance);
    printf("Total Capacitance: %.2f Farads\n", total_capacitance);

    free_components(head);
    
    return 0;
}