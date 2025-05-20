//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

// Struct to hold unit conversion factors
typedef struct {
    char symbol[3];
    double factor;
} Unit;

// Function to initialize unit conversion factors
void initUnits(Unit units[]) {
    strcpy(units[0].symbol, "m");
    units[0].factor = 1.0;

    strcpy(units[1].symbol, "cm");
    units[1].factor = 0.01;

    strcpy(units[2].symbol, "mm");
    units[2].factor = 0.001;

    strcpy(units[3].symbol, "in");
    units[3].factor = 0.0254;

    strcpy(units[4].symbol, "ft");
    units[4].factor = 0.3048;

    strcpy(units[5].symbol, "yd");
    units[5].factor = 0.9144;

    strcpy(units[6].symbol, "mi");
    units[6].factor = 160934.4;

    strcpy(units[7].symbol, "kg");
    units[7].factor = 1.0;

    strcpy(units[8].symbol, "g");
    units[8].factor = 0.001;

    strcpy(units[9].symbol, "lb");
    units[9].factor = 0.453592;
}

// Function to convert a value from one unit to another
double convertValue(double value, char fromUnit[], char toUnit[]) {
    Unit units[MAX_UNITS];
    initUnits(units);

    // Find the conversion factor for the input unit
    int fromIndex = -1;
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].symbol, fromUnit) == 0) {
            fromIndex = i;
            break;
        }
    }

    if (fromIndex == -1) {
        printf("Invalid input unit: %s\n", fromUnit);
        return -1;
    }

    // Find the conversion factor for the output unit
    int toIndex = -1;
    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(units[i].symbol, toUnit) == 0) {
            toIndex = i;
            break;
        }
    }

    if (toIndex == -1) {
        printf("Invalid output unit: %s\n", toUnit);
        return -1;
    }

    // Convert the value
    double result = value * units[fromIndex].factor / units[toIndex].factor;
    return result;
}

int main() {
    double value;
    char fromUnit[3], toUnit[3];

    // Get input value and units
    printf("Enter value: ");
    scanf("%lf", &value);
    printf("Enter input unit (e.g. m, cm, in): ");
    scanf("%s", fromUnit);

    // Get output unit
    printf("Enter output unit (e.g. m, cm, in): ");
    scanf("%s", toUnit);

    // Convert the value
    double result = convertValue(value, fromUnit, toUnit);

    if (result == -1) {
        return 1;
    }

    // Print the result
    printf("%.2f %s = %.2f %s\n", value, fromUnit, result, toUnit);

    return 0;
}