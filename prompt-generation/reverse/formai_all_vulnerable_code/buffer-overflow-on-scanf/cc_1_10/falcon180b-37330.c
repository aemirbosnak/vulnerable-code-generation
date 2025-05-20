//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 20

typedef struct {
    char *name;
    double factor;
} Unit;

void add_unit(Unit *units, int *num_units, char *name, double factor) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    strcpy(units[*num_units].name, name);
    units[*num_units].factor = factor;
    (*num_units)++;
}

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;

    add_unit(units, &num_units, "meter", 1.0);
    add_unit(units, &num_units, "kilometer", 1000.0);
    add_unit(units, &num_units, "centimeter", 0.01);
    add_unit(units, &num_units, "millimeter", 0.001);

    char unit1[20], unit2[20];
    double value;

    printf("Enter the unit to convert from: ");
    scanf("%s", unit1);

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    printf("Enter the unit to convert to: ");
    scanf("%s", unit2);

    int i;
    for (i = 0; i < num_units; i++) {
        if (strcmp(unit1, units[i].name) == 0) {
            break;
        }
    }

    if (i == num_units) {
        printf("Error: Invalid unit.\n");
        return 1;
    }

    for (i = 0; i < num_units; i++) {
        if (strcmp(unit2, units[i].name) == 0) {
            value *= units[i].factor;
            break;
        }
    }

    printf("%.2lf %s = %.2lf %s\n", value, unit1, value, unit2);

    return 0;
}