//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int num_units;
    Unit units[MAX_UNITS];
    char input[100];
    double value;
    int from_unit, to_unit;

    printf("Enter the number of units: ");
    scanf("%d", &num_units);

    for (int i = 0; i < num_units; i++) {
        printf("Enter the name of unit %d: ", i + 1);
        scanf("%s", units[i].name);
        printf("Enter the factor of unit %s: ", units[i].name);
        scanf("%lf", &units[i].factor);
    }

    printf("Enter the value to convert: ");
    scanf("%s", input);
    value = atof(input);

    printf("Enter the unit to convert from: ");
    scanf("%s", input);
    from_unit = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, input) == 0) {
            from_unit = i;
            break;
        }
    }

    if (from_unit == -1) {
        printf("Invalid unit '%s'.\n", input);
        return 1;
    }

    printf("Enter the unit to convert to: ");
    scanf("%s", input);
    to_unit = -1;
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, input) == 0) {
            to_unit = i;
            break;
        }
    }

    if (to_unit == -1) {
        printf("Invalid unit '%s'.\n", input);
        return 1;
    }

    for (int i = 0; i < num_units; i++) {
        if (i == from_unit || i == to_unit)
            continue;

        value = (value * units[from_unit].factor) / units[i].factor;
    }

    printf("%.2lf %s = %.2lf %s\n", value, units[from_unit].name, value, units[to_unit].name);

    return 0;
}