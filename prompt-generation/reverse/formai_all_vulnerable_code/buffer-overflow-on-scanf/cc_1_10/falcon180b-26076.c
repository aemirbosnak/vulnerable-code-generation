//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    double factor;
} Unit;

void add_unit(Unit *units, int *num_units, char *name, double factor) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Too many units defined.\n");
        exit(1);
    }
    units[*num_units].name = name;
    units[*num_units].factor = factor;
    (*num_units)++;
}

int find_unit(Unit *units, int num_units, char *name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(double value, int from_unit, int to_unit, Unit *units) {
    double factor_from = units[from_unit].factor;
    double factor_to = units[to_unit].factor;
    return (value * factor_to) / factor_from;
}

int main() {
    Unit units[MAX_UNITS];
    int num_units = 0;

    add_unit(units, &num_units, "meter", 1.0);
    add_unit(units, &num_units, "centimeter", 0.01);
    add_unit(units, &num_units, "kilometer", 1000.0);
    add_unit(units, &num_units, "inch", 0.0254);
    add_unit(units, &num_units, "foot", 0.3048);
    add_unit(units, &num_units, "yard", 0.9144);
    add_unit(units, &num_units, "mile", 160934.4);

    int from_unit, to_unit;
    printf("Enter the unit you want to convert from: ");
    char input[20];
    scanf("%s", input);
    from_unit = find_unit(units, num_units, input);

    printf("Enter the unit you want to convert to: ");
    scanf("%s", input);
    to_unit = find_unit(units, num_units, input);

    printf("Enter the value to convert: ");
    double value;
    scanf("%lf", &value);

    double result = convert(value, from_unit, to_unit, units);

    printf("%.2lf %s = %.2lf %s\n", value, units[from_unit].name, result, units[to_unit].name);

    return 0;
}