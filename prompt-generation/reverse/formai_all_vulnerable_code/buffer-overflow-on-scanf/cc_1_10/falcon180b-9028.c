//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char name[20];
    double factor;
    int index;
} Unit;

void addUnit(Unit units[], int numUnits, char name[], double factor) {
    if (numUnits >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    strcpy(units[numUnits].name, name);
    units[numUnits].factor = factor;
    units[numUnits].index = numUnits;

    numUnits++;
}

void printUnits(Unit units[], int numUnits) {
    printf("Available units:\n");
    for (int i = 0; i < numUnits; i++) {
        printf("%d. %s (%c)\n", i+1, units[i].name, units[i].index+'A');
    }
}

int main() {
    Unit units[MAX_UNITS];
    int numUnits = 0;

    addUnit(units, numUnits, "Meters", 1.0);
    addUnit(units, numUnits, "Kilometers", 1000.0);
    addUnit(units, numUnits, "Inches", 0.0254);
    addUnit(units, numUnits, "Feet", 0.3048);
    addUnit(units, numUnits, "Yards", 0.9144);
    addUnit(units, numUnits, "Miles", 160934.4);

    printUnits(units, numUnits);

    char fromUnit, toUnit;
    double value;

    printf("Enter the unit to convert from (e.g. M for meters): ");
    scanf("%c", &fromUnit);

    printf("Enter the unit to convert to (e.g. K for kilometers): ");
    scanf("%c", &toUnit);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    int fromIndex = -1, toIndex = -1;

    for (int i = 0; i < numUnits; i++) {
        if (units[i].index == fromUnit) {
            fromIndex = i;
        } else if (units[i].index == toUnit) {
            toIndex = i;
        }
    }

    if (fromIndex == -1 || toIndex == -1) {
        printf("Error: Invalid unit(s).\n");
        return 1;
    }

    double result = value * units[fromIndex].factor / units[toIndex].factor;

    printf("%.2lf %c = %.2lf %c\n", value, fromUnit, result, toUnit);

    return 0;
}