//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure for a Circuit Component
typedef struct {
    char type[20]; // Type of the component: Resistor, Capacitor, Inductor, etc.
    double value;  // Value of the component (Ohms for resistor, Farads for capacitor, etc.)
} Component;

// Function Prototypes
void simulateCircuit(Component* components, int count);
void displayCircuit(Component* components, int count);
double calculateTotalResistance(Component* components, int count);
void cleanupCircuit(Component* components);

int main() {
    int count = 0;
    int capacity = 5; // initial memory allocation
    Component* components = malloc(capacity * sizeof(Component));

    if (components == NULL) {
        perror("Failed to allocate memory for circuit components.");
        return EXIT_FAILURE;
    }

    printf("Welcome to the Classical Circuit Simulator!\n");
    printf("You can enter up to %d components. Type 'exit' to quit.\n", capacity);

    while (1) {
        if (count >= capacity) {
            capacity *= 2; // double the size
            components = realloc(components, capacity * sizeof(Component));
            if (components == NULL) {
                perror("Failed to reallocate memory for circuit components.");
                return EXIT_FAILURE;
            }
        }

        printf("Enter component type (Resistor, Capacitor, Inductor): ");
        char type[20];
        scanf("%s", type);
        if (strcmp(type, "exit") == 0)
            break;

        printf("Enter the value of %s: ", type);
        double value;
        scanf("%lf", &value);

        strcpy(components[count].type, type);
        components[count].value = value;
        count++;
    }

    displayCircuit(components, count);
    simulateCircuit(components, count);
    
    cleanupCircuit(components);
    return EXIT_SUCCESS;
}

void displayCircuit(Component* components, int count) {
    printf("\nCircuit Components:\n");
    for (int i = 0; i < count; i++) {
        printf("Component %d: Type = %s, Value = %.2f\n", i + 1, components[i].type, components[i].value);
    }
}

void simulateCircuit(Component* components, int count) {
    double totalResistance = calculateTotalResistance(components, count);
    printf("\nTotal Resistance of the Circuit: %.2f Ohms\n", totalResistance);
}

double calculateTotalResistance(Component* components, int count) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        if (strcmp(components[i].type, "Resistor") == 0) {
            total += components[i].value; // sum resistances
        } 
        // For now, we ignore Capacitors and Inductors in resistance calculation
    }
    return total;
}

void cleanupCircuit(Component* components) {
    free(components);
    printf("Cleaned up circuit components memory.\n");
}