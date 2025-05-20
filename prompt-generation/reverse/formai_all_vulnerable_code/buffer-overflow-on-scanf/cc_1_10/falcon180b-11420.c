//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char name[20];
    char symbol[5];
    double factor;
} unit;

void add_unit(unit *units, int *num_units, char *name, char *symbol, double factor) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    strcpy(units[*num_units].name, name);
    strcpy(units[*num_units].symbol, symbol);
    units[*num_units].factor = factor;

    (*num_units)++;
}

void convert(double value, int from_unit, int to_unit, unit *units) {
    double result = value * units[from_unit].factor / units[to_unit].factor;

    printf("%.2f %s = %.2f %s\n", value, units[from_unit].symbol, result, units[to_unit].symbol);
}

int main() {
    unit units[MAX_UNITS];
    int num_units = 0;

    add_unit(units, &num_units, "meter", "m", 1.0);
    add_unit(units, &num_units, "centimeter", "cm", 0.01);
    add_unit(units, &num_units, "millimeter", "mm", 0.001);
    add_unit(units, &num_units, "kilogram", "kg", 1.0);
    add_unit(units, &num_units, "gram", "g", 0.001);
    add_unit(units, &num_units, "liter", "L", 1.0);
    add_unit(units, &num_units, "milliliter", "mL", 0.001);

    int from_unit, to_unit;

    printf("Enter the unit you want to convert from (1-7): ");
    scanf("%d", &from_unit);

    printf("Enter the unit you want to convert to (1-7): ");
    scanf("%d", &to_unit);

    printf("Enter the value you want to convert: ");
    double value;
    scanf("%lf", &value);

    convert(value, from_unit - 1, to_unit - 1, units);

    return 0;
}