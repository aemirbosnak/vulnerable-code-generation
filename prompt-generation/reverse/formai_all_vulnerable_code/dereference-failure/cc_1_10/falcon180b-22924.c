//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    double factor;
} Unit;

int num_units = 0;
Unit units[MAX_UNITS];

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    units[num_units].name = strdup(name);
    units[num_units].factor = factor;

    num_units++;
}

int main() {
    // Add some units
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("gram", 1.0);
    add_unit("kilogram", 1000.0);

    // Convert some values
    double value = 5.0;
    char from_unit[20], to_unit[20];

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);

    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    int from_index = -1, to_index = -1;

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, from_unit) == 0) {
            from_index = i;
        }

        if (strcmp(units[i].name, to_unit) == 0) {
            to_index = i;
        }
    }

    if (from_index == -1 || to_index == -1) {
        printf("Error: Invalid unit.\n");
        return 1;
    }

    double result = value * units[from_index].factor / units[to_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}