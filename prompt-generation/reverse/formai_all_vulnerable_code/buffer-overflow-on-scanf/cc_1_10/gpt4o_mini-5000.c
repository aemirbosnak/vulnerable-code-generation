//GPT-4o-mini DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_RESISTORS 10

// Function prototypes
void displayMenu();
void addResistor(float *resistors, int *count);
void calculateSeries(float *resistors, int count);
void calculateParallel(float *resistors, int count);
void displayResistors(float *resistors, int count);

int main() {
    int option;
    float resistors[MAX_RESISTORS];
    int count = 0;

    printf("Welcome to the Retro Circuit Simulator!\n");
    printf("========================================\n");
    
    while(1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                if (count < MAX_RESISTORS) {
                    addResistor(resistors, &count);
                } else {
                    printf("Maximum resistor limit reached!\n");
                }
                break;
            case 2:
                calculateSeries(resistors, count);
                break;
            case 3:
                calculateParallel(resistors, count);
                break;
            case 4:
                displayResistors(resistors, count);
                break;
            case 5:
                printf("Exiting the simulator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Circuit Simulator Menu ---\n");
    printf("1. Add Resistor\n");
    printf("2. Calculate Total Resistance (Series)\n");
    printf("3. Calculate Total Resistance (Parallel)\n");
    printf("4. Display Resistors\n");
    printf("5. Exit\n");
}

void addResistor(float *resistors, int *count) {
    float resistorValue;
    printf("Enter the value of resistor (Ohms): ");
    scanf("%f", &resistorValue);
    resistors[(*count)++] = resistorValue;
    printf("Resistor of %.2f Ohms added successfully!\n", resistorValue);
}

void calculateSeries(float *resistors, int count) {
    float totalResistance = 0.0;
    
    for (int i = 0; i < count; i++) {
        totalResistance += resistors[i];
    }
    
    printf("Total Resistance in Series: %.2f Ohms\n", totalResistance);
}

void calculateParallel(float *resistors, int count) {
    if (count == 0) {
        printf("No resistors to calculate!\n");
        return;
    }
    
    float totalInverse = 0.0;

    for (int i = 0; i < count; i++) {
        totalInverse += 1.0 / resistors[i];
    }

    float totalResistance = totalInverse > 0 ? 1.0 / totalInverse : 0.0;
    printf("Total Resistance in Parallel: %.2f Ohms\n", totalResistance);
}

void displayResistors(float *resistors, int count) {
    printf("Resistors in the circuit:\n");
    for (int i = 0; i < count; i++) {
        printf("Resistor %d: %.2f Ohms\n", i + 1, resistors[i]);
    }
    if (count == 0) {
        printf("No resistors have been added yet!\n");
    }
}