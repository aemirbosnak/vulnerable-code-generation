//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 8
#define UNIT_NAME_LENGTH 20
#define CONVERSION_FACTOR_LENGTH 20

typedef struct {
    char name[UNIT_NAME_LENGTH];
    char conversionFactor[CONVERSION_FACTOR_LENGTH];
} Unit;

Unit units[MAX_UNITS] = {
    {"meters", "1"},
    {"kilometers", "1000"},
    {"grams", "1"},
    {"kilograms", "1000"},
    {"liters", "1"},
    {"milliliters", "1"},
    {"seconds", "1"},
    {"minutes", "60"}
};

void printUnits() {
    printf("Available units:\n");
    for (int i = 0; i < MAX_UNITS; i++) {
        printf("%s\n", units[i].name);
    }
}

int main() {
    int choice;
    double value, result;
    char fromUnit[UNIT_NAME_LENGTH], toUnit[UNIT_NAME_LENGTH];

    printf("Welcome to the Unit Converter!\n");
    printUnits();

    printf("\nEnter the unit you want to convert from: ");
    scanf("%s", fromUnit);

    printf("\nEnter the unit you want to convert to: ");
    scanf("%s", toUnit);

    printf("\nEnter the value you want to convert: ");
    scanf("%lf", &value);

    for (int i = 0; i < MAX_UNITS; i++) {
        if (strcmp(fromUnit, units[i].name) == 0) {
            for (int j = 0; j < MAX_UNITS; j++) {
                if (strcmp(toUnit, units[j].name) == 0) {
                    result = value * atof(units[i].conversionFactor);
                    printf("\n%lf %s = %lf %s\n", value, fromUnit, result, toUnit);
                    break;
                }
            }
            break;
        }
    }

    return 0;
}