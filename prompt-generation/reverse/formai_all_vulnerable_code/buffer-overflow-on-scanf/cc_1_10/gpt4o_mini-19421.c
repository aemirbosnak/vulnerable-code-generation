//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the types of components
typedef struct Component {
    char type; // 'R' for resistor, 'C' for capacitor, 'V' for voltage source
    double value; // value of the component
    struct Component *next; // pointer to the next component
} Component;

// Function prototypes
Component* create_component(char type, double value);
void add_component(Component **head, char type, double value);
void list_components(Component *head);
double calculate_total_resistance(Component *head);
double calculate_total_capacitance(Component *head);
double calculate_total_voltage(Component *head);
void free_components(Component *head);

int main() {
    Component *circuit = NULL;
    int choice;
    char type;
    double value;

    printf("Welcome to the C Classical Circuit Simulator!\n");
    printf("We are grateful for your interest in learning about circuits.\n\n");

    while (1) {
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Add Voltage Source\n");
        printf("4. List Components\n");
        printf("5. Calculate Total Resistance\n");
        printf("6. Calculate Total Capacitance\n");
        printf("7. Calculate Total Voltage\n");
        printf("8. Exit\n");
        printf("Please enter your choice (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Thank you for adding a Resistor!\n");
                printf("Enter resistance (Ohms): ");
                scanf("%lf", &value);
                add_component(&circuit, 'R', value);
                break;
            case 2:
                printf("Wonderful choice to add a Capacitor!\n");
                printf("Enter capacitance (Farads): ");
                scanf("%lf", &value);
                add_component(&circuit, 'C', value);
                break;
            case 3:
                printf("Adding a Voltage Source is essential!\n");
                printf("Enter voltage (Volts): ");
                scanf("%lf", &value);
                add_component(&circuit, 'V', value);
                break;
            case 4:
                printf("Here are the components you've added:\n");
                list_components(circuit);
                break;
            case 5:
                printf("Calculating Total Resistance...\n");
                printf("Total Resistance: %.2f Ohms\n", calculate_total_resistance(circuit));
                break;
            case 6:
                printf("Calculating Total Capacitance...\n");
                printf("Total Capacitance: %.2f Farads\n", calculate_total_capacitance(circuit));
                break;
            case 7:
                printf("Calculating Total Voltage...\n");
                printf("Total Voltage: %.2f Volts\n", calculate_total_voltage(circuit));
                break;
            case 8:
                printf("Thank you for using the simulator! Goodbye!\n");
                free_components(circuit);
                return 0;
            default:
                printf("Invalid choice, please select again.\n");
        }
    }

    return 0;
}

Component* create_component(char type, double value) {
    Component *new_component = (Component *)malloc(sizeof(Component));
    if (new_component == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_component->type = type;
    new_component->value = value;
    new_component->next = NULL;
    return new_component;
}

void add_component(Component **head, char type, double value) {
    Component *new_component = create_component(type, value);
    if (*head == NULL) {
        *head = new_component;
    } else {
        Component *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_component;
    }
    printf("You've successfully added a component!\n");
}

void list_components(Component *head) {
    if (head == NULL) {
        printf("No components in the circuit yet!\n");
        return;
    }
    Component *current = head;
    while (current != NULL) {
        printf("Type: %c, Value: %.2f\n", current->type, current->value);
        current = current->next;
    }
}

double calculate_total_resistance(Component *head) {
    double total = 0.0;
    Component *current = head;
    while (current != NULL) {
        if (current->type == 'R') {
            total += current->value; // Sum resistances in series
        }
        current = current->next;
    }
    return total;
}

double calculate_total_capacitance(Component *head) {
    double total = 0.0;
    Component *current = head;
    while (current != NULL) {
        if (current->type == 'C') {
            total += current->value; // Sum capacitances in parallel
        }
        current = current->next;
    }
    return total;
}

double calculate_total_voltage(Component *head) {
    double total = 0.0;
    Component *current = head;
    while (current != NULL) {
        if (current->type == 'V') {
            total += current->value; // Sum voltages
        }
        current = current->next;
    }
    return total;
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