//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 10

typedef struct {
    char name[20];
    float conversionFactor;
} Unit;

// Function prototypes
void displayMenu();
void initializeUnits(Unit units[]);
void convertUnits(Unit units[], int numUnits);
int getUnitIndex(Unit units[], int numUnits, char* name);

int main() {
    Unit units[MAX_UNITS];
    initializeUnits(units);
    
    while (1) {
        displayMenu();
        int choice;
        printf("Enter your choice (1-%d): ", MAX_UNITS + 2);
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                convertUnits(units, MAX_UNITS);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n=== Unit Converter ===\n");
    printf("1. Convert Units\n");
    printf("2. Exit\n");
    printf("======================\n");
}

void initializeUnits(Unit units[]) {
    // Initialize some example units and their conversion factors to meters
    snprintf(units[0].name, sizeof(units[0].name), "meters");
    units[0].conversionFactor = 1.0;

    snprintf(units[1].name, sizeof(units[1].name), "kilometers");
    units[1].conversionFactor = 1000.0;

    snprintf(units[2].name, sizeof(units[2].name), "centimeters");
    units[2].conversionFactor = 0.01;

    snprintf(units[3].name, sizeof(units[3].name), "millimeters");
    units[3].conversionFactor = 0.001;

    snprintf(units[4].name, sizeof(units[4].name), "inches");
    units[4].conversionFactor = 0.0254;

    snprintf(units[5].name, sizeof(units[5].name), "feet");
    units[5].conversionFactor = 0.3048;

    snprintf(units[6].name, sizeof(units[6].name), "yards");
    units[6].conversionFactor = 0.9144;

    snprintf(units[7].name, sizeof(units[7].name), "miles");
    units[7].conversionFactor = 1609.34;

    snprintf(units[8].name, sizeof(units[8].name), "nautical miles");
    units[8].conversionFactor = 1852.0;

    snprintf(units[9].name, sizeof(units[9].name), "light years");
    units[9].conversionFactor = 9.461e15; // meters
}

void convertUnits(Unit units[], int numUnits) {
    char fromUnit[20], toUnit[20];
    float value;

    printf("Enter value to convert: ");
    scanf("%f", &value);
    
    printf("Enter unit of value (%s): ", 
        units[0].name);
    for (int i = 1; i < numUnits; i++) {
        printf(", %s", units[i].name);
    }
    printf(": ");
    scanf("%s", fromUnit);
    
    printf("Enter unit to convert to (%s): ", 
        units[0].name);
    for (int i = 1; i < numUnits; i++) {
        printf(", %s", units[i].name);
    }
    printf(": ");
    scanf("%s", toUnit);

    int fromIndex = getUnitIndex(units, numUnits, fromUnit);
    int toIndex = getUnitIndex(units, numUnits, toUnit);

    if (fromIndex == -1 || toIndex == -1) {
        printf("Error: One of the units is invalid.\n");
        return;
    }

    float convertedValue = value * (units[fromIndex].conversionFactor / units[toIndex].conversionFactor);
    printf("%.2f %s is equal to %.2f %s\n", value, fromUnit, convertedValue, toUnit);
}

int getUnitIndex(Unit units[], int numUnits, char* name) {
    for (int i = 0; i < numUnits; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Unit not found
}