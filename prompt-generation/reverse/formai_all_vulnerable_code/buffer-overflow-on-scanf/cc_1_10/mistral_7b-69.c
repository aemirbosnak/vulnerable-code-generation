//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    double factor;
} Unit;

Unit units[] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {"millimeter", 0.001},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.34}
};

int main() {
    char inputUnit[10], convertedUnit[10];
    double value, conversionFactor, result;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the value and the unit (case sensitive): ");
    scanf("%lf %s", &value, inputUnit);

    // Find the index of the input unit in the units array
    int inputIndex = -1;
    for (int i = 0; i < 8; i++) {
        if (strcmp(inputUnit, units[i].name) == 0) {
            inputIndex = i;
            break;
        }
    }

    // If the input unit is not found, print an error message and exit
    if (inputIndex == -1) {
        printf("Error: Invalid unit '%s'\n", inputUnit);
        return 1;
    }

    // Convert the value to all other units and print the results
    printf("\nValue in other units:\n");
    for (int i = 0; i < 8; i++) {
        if (i != inputIndex) { // Skip the input unit
            conversionFactor = units[i].factor / units[inputIndex].factor;
            result = value * conversionFactor;
            strcpy(convertedUnit, units[i].name);
            printf("%15s: %.2f\n", convertedUnit, result);
        }
    }

    return 0;
}