//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS];
int numUnits;

void addUnit(char *name, double factor) {
    if (numUnits >= MAX_UNITS) {
        printf("Error: Too many units defined.\n");
        return;
    }
    units[numUnits].name = name;
    units[numUnits].factor = factor;
    numUnits++;
}

void convert(double value, char *fromUnit, char *toUnit) {
    int i;
    for (i = 0; i < numUnits; i++) {
        if (strcmp(units[i].name, fromUnit) == 0) {
            break;
        }
    }
    if (i == numUnits) {
        printf("Error: Unknown unit '%s'.\n", fromUnit);
        return;
    }
    for (i = 0; i < numUnits; i++) {
        if (strcmp(units[i].name, toUnit) == 0) {
            break;
        }
    }
    if (i == numUnits) {
        printf("Error: Unknown unit '%s'.\n", toUnit);
        return;
    }
    printf("%s = %.2f %s\n", toUnit, value * units[i].factor, fromUnit);
}

int main() {
    addUnit("meter", 1.0);
    addUnit("kilometer", 1000.0);
    addUnit("gram", 1.0);
    addUnit("kilogram", 1000.0);
    addUnit("liter", 1.0);
    addUnit("milliliter", 0.001);
    addUnit("second", 1.0);
    addUnit("minute", 60.0);
    addUnit("hour", 3600.0);
    addUnit("day", 86400.0);

    double value;
    char fromUnit[20], toUnit[20];

    while (true) {
        printf("\nEnter value: ");
        scanf("%lf", &value);
        printf("Enter from unit: ");
        scanf("%s", fromUnit);
        printf("Enter to unit: ");
        scanf("%s", toUnit);
        convert(value, fromUnit, toUnit);
    }

    return 0;
}