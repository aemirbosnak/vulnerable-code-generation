//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 100

typedef enum {
    RESISTOR,
    CAPACITOR
} ComponentType;

typedef struct {
    ComponentType type;
    char name[20];
    double value; // Ohms for resistor, Farads for capacitor
} Component;

Component components[MAX_COMPONENTS];
int componentCount = 0;

// Function to add a component
void addComponent(ComponentType type, const char *name, double value) {
    if (componentCount >= MAX_COMPONENTS) {
        printf("Maximum component limit reached!\n");
        return;
    }
    components[componentCount].type = type;
    strcpy(components[componentCount].name, name);
    components[componentCount].value = value;
    componentCount++;
    printf("Added %s: %s with value: %.2f\n", 
           (type == RESISTOR) ? "Resistor" : "Capacitor", name, value);
}

// Function to calculate the equivalent resistance of resistors in series
double calculateSeriesResistance() {
    double totalResistance = 0.0;
    for (int i = 0; i < componentCount; i++) {
        if (components[i].type == RESISTOR) {
            totalResistance += components[i].value;
        }
    }
    return totalResistance;
}

// Function to calculate the equivalent capacitance of capacitors in series
double calculateSeriesCapacitance() {
    double totalCapacitance = 0.0;
    for (int i = 0; i < componentCount; i++) {
        if (components[i].type == CAPACITOR) {
            totalCapacitance += 1.0 / components[i].value;
        }
    }
    return (totalCapacitance > 0) ? (1.0 / totalCapacitance) : 0;
}

// Function to display all components
void displayComponents() {
    printf("Current Components:\n");
    for (int i = 0; i < componentCount; i++) {
        printf("%d: %s - %s: %.2f\n", i + 1,
               components[i].name,
               (components[i].type == RESISTOR) ? "Resistor" : "Capacitor",
               components[i].value);
    }
}

// Main function
int main() {
    int choice;
    char name[20];
    double value;
    
    while (1) {
        printf("\nElectronic Circuit Simulator:\n");
        printf("1. Add Resistor\n");
        printf("2. Add Capacitor\n");
        printf("3. Calculate Total Resistance (Series)\n");
        printf("4. Calculate Total Capacitance (Series)\n");
        printf("5. Display Components\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Resistor Name: ");
                scanf("%s", name);
                printf("Enter Resistor Value (Ohms): ");
                scanf("%lf", &value);
                addComponent(RESISTOR, name, value);
                break;
            case 2:
                printf("Enter Capacitor Name: ");
                scanf("%s", name);
                printf("Enter Capacitor Value (Farads): ");
                scanf("%lf", &value);
                addComponent(CAPACITOR, name, value);
                break;
            case 3:
                printf("Total Resistance (Series): %.2f Ohms\n", calculateSeriesResistance());
                break;
            case 4:
                printf("Total Capacitance (Series): %.2f Farads\n", calculateSeriesCapacitance());
                break;
            case 5:
                displayComponents();
                break;
            case 6:
                printf("Exiting Simulator.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}