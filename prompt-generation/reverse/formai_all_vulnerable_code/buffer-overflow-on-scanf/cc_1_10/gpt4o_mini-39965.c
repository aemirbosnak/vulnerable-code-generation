//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_COMPONENTS 10

typedef struct {
    char name[20];
    float resistance; // in ohms
} Resistor;

void addResistor(Resistor resistors[], int *count) {
    if (*count >= MAX_COMPONENTS) {
        printf("Max number of resistors reached.\n");
        return;
    }

    Resistor r;
    printf("Enter the name of the resistor: ");
    scanf("%s", r.name);
    printf("Enter the resistance of the resistor (in ohms): ");
    scanf("%f", &r.resistance);

    resistors[*count] = r;
    (*count)++;
}

float totalResistanceSeries(Resistor resistors[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += resistors[i].resistance;
    }
    return total;
}

float totalResistanceParallel(Resistor resistors[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        if (resistors[i].resistance == 0) {
            printf("Warning: Resistance of %s is zero, infinite current.\n", resistors[i].name);
            return 0; // Infinite current if resistance is zero
        }
        total += 1.0 / resistors[i].resistance;
    }
    return total > 0 ? 1.0 / total : 0; // Prevent division by zero
}

void displayResistors(Resistor resistors[], int count) {
    printf("\nResistors in the circuit:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f ohms\n", resistors[i].name, resistors[i].resistance);
    }
}

int main() {
    Resistor resistors[MAX_COMPONENTS];
    int count = 0;
    int choice;
    float totalRes;

    while (1) {
        printf("\nCircuit Simulator Menu:\n");
        printf("1. Add Resistor\n");
        printf("2. Calculate Total Resistance (Series)\n");
        printf("3. Calculate Total Resistance (Parallel)\n");
        printf("4. Display Resistors\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addResistor(resistors, &count);
                break;
            case 2:
                totalRes = totalResistanceSeries(resistors, count);
                printf("Total Resistance in Series: %.2f ohms\n", totalRes);
                break;
            case 3:
                totalRes = totalResistanceParallel(resistors, count);
                printf("Total Resistance in Parallel: %.2f ohms\n", totalRes);
                break;
            case 4:
                displayResistors(resistors, count);
                break;
            case 5:
                printf("Exiting the simulator.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}