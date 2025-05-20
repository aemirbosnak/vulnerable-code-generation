//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Constants */
#define MAX_COMPONENTS 100

typedef struct {
    char type; // 'R' for Resistor, 'C' for Capacitor, 'L' for Inductor
    double value; // Value of the component in ohms for R, farads for C, henrys for L
} Component;

Component components[MAX_COMPONENTS];
int component_count = 0;

// Function prototypes
void add_component();
void calculate_impedance();
void display_components();
void clear_components();

int main() {
    int choice;

    printf("Welcome to the C Classical Circuit Simulator!\n");
    printf("Let's make some circuits!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Component\n");
        printf("2. Calculate Total Impedance\n");
        printf("3. Display Components\n");
        printf("4. Clear Components\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_component();
                break;
            case 2:
                calculate_impedance();
                break;
            case 3:
                display_components();
                break;
            case 4:
                clear_components();
                break;
            case 0:
                printf("Exiting the simulator. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

void add_component() {
    if (component_count >= MAX_COMPONENTS) {
        printf("Cannot add more components! Maximum limit reached.\n");
        return;
    }

    char type;
    double value;

    printf("Enter component type (R for Resistor, C for Capacitor, L for Inductor): ");
    scanf(" %c", &type);
    printf("Enter the value of the component: ");
    scanf("%lf", &value);

    components[component_count].type = type;
    components[component_count].value = value;
    component_count++;

    printf("Component added successfully!\n");
}

void calculate_impedance() {
    double total_impedance = 0.0;
    double total_reactance = 0.0;

    for (int i = 0; i < component_count; i++) {
        if (components[i].type == 'R') {
            total_impedance += components[i].value; // Resistor - resistive load
        } else if (components[i].type == 'C') {
            total_reactance -= (1 / (2 * M_PI * components[i].value)); // Capacitor - negative reactance
        } else if (components[i].type == 'L') {
            total_reactance += (2 * M_PI * components[i].value); // Inductor - positive reactance
        } else {
            printf("Unknown component type!\n");
        }
    }

    double impedance = sqrt(total_impedance * total_impedance + total_reactance * total_reactance);
    double phase_angle = atan2(total_reactance, total_impedance) * (180 / M_PI);

    printf("Total Impedance: %.2f Ohms\n", impedance);
    printf("Phase Angle: %.2f degrees\n", phase_angle);
}

void display_components() {
    printf("Current Components in the Circuit:\n");
    for (int i = 0; i < component_count; i++) {
        printf("Component %d: Type: %c, Value: %.2f\n", i + 1, components[i].type, components[i].value);
    }
}

void clear_components() {
    component_count = 0;
    printf("All components cleared!\n");
}