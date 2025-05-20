//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPONENTS 10
#define NAME_LENGTH 20

typedef struct Component {
    char name[NAME_LENGTH];
    char type; // 'R' for Resistor, 'C' for Capacitor, 'L' for Inductor
    float value; // Ohms for Resistor, Farads for Capacitor, Henrys for Inductor
} Component;

void displayMenu() {
    printf("Welcome to the Magical Circuit Simulator!\n");
    printf("1. Add a Component\n");
    printf("2. View Circuit\n");
    printf("3. Calculate Total Impedance\n");
    printf("4. Exit\n");
}

float calculateImpedance(Component components[], int count) {
    float totalImpedance = 0.0;
    for (int i = 0; i < count; i++) {
        if (components[i].type == 'R') {
            totalImpedance += components[i].value; // Resistors add linearly
        } else if (components[i].type == 'C') {
            totalImpedance -= 1 / components[i].value; // Capacitors decrease impedance
        } else if (components[i].type == 'L') {
            totalImpedance += components[i].value; // Inductors add linearly
        }
    }
    return totalImpedance;
}

void addComponent(Component components[], int *count) {
    if (*count >= MAX_COMPONENTS) {
        printf("Maximum components reached! Can't add more.\n");
        return;
    }
    
    Component newComponent;
    printf("Enter component name: ");
    scanf("%s", newComponent.name);
    
    printf("Enter component type (R for Resistor, C for Capacitor, L for Inductor): ");
    scanf(" %c", &newComponent.type);
    
    printf("Enter component value: ");
    scanf("%f", &newComponent.value);
    
    components[*count] = newComponent;
    (*count)++;
    
    printf("Component %s added successfully!\n", newComponent.name);
}

void viewCircuit(Component components[], int count) {
    printf("Current Circuit Components:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Type: %c, Value: %.2f\n", 
               components[i].name, components[i].type, components[i].value);
    }
}

int main() {
    Component components[MAX_COMPONENTS];
    int componentCount = 0;
    int choice;
    
    while (1) {
        displayMenu();
        printf("Choose an action: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addComponent(components, &componentCount);
                break;
            case 2:
                viewCircuit(components, componentCount);
                break;
            case 3: {
                float totalImpedance = calculateImpedance(components, componentCount);
                printf("Total Impedance of the Circuit: %.2f Ohms\n", totalImpedance);
                break;
            }
            case 4:
                printf("Thank you for using the Magical Circuit Simulator! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
    
    return 0;
}