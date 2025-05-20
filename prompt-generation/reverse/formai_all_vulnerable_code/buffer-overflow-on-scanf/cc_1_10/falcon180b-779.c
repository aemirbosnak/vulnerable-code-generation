//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_UNITS 10

typedef struct {
    char *name;
    char *symbol;
    int decimal_places;
} Unit;

Unit units[NUM_UNITS] = {
    {"Meters", "m", 2},
    {"Kilometers", "km", 2},
    {"Inches", "in", 2},
    {"Feet", "ft", 2},
    {"Yards", "yd", 2},
    {"Miles", "mi", 2},
    {"Millimeters", "mm", 2},
    {"Centimeters", "cm", 2},
    {"Nanometers", "nm", 2},
    {"Pixels", "px", 0}
};

double convert(double value, int from_unit, int to_unit) {
    if (from_unit == to_unit) {
        return value;
    }

    for (int i = 0; i < NUM_UNITS; i++) {
        if (i == from_unit) {
            continue;
        }
        if (i == to_unit) {
            return value * units[from_unit].decimal_places / units[i].decimal_places;
        }
    }

    printf("Invalid conversion\n");
    exit(1);
}

int main() {
    int from_unit, to_unit;
    double value;

    printf("Enter a value: ");
    scanf("%lf", &value);

    printf("Enter the unit of the value (e.g. m, in): ");
    char unit_name[10];
    scanf("%s", unit_name);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            from_unit = i;
            break;
        }
    }

    printf("Enter the unit to convert to (e.g. ft, mm): ");
    scanf("%s", unit_name);

    for (int i = 0; i < NUM_UNITS; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            to_unit = i;
            break;
        }
    }

    double result = convert(value, from_unit, to_unit);

    printf("%.*lf %s = %.*lf %s\n", units[from_unit].decimal_places, value, units[from_unit].name, units[to_unit].decimal_places, result, units[to_unit].name);

    return 0;
}