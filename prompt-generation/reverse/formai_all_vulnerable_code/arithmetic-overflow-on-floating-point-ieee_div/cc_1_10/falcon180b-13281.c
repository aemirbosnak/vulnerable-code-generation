//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

Unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }
    units[num_units] = (Unit) {name, factor};
    num_units++;
}

void print_units() {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s (%c)\n", units[i].name, toupper(units[i].name[0]));
    }
}

int get_unit_index(char *name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    add_unit("meter", 1.0);
    add_unit("kilometer", 1000.0);
    add_unit("centimeter", 0.01);
    add_unit("inch", 0.393701);
    add_unit("foot", 3.28084);
    add_unit("yard", 1.09361);
    add_unit("mile", 0.000621371);

    print_units();

    char from_unit[20], to_unit[20];
    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    int from_index = get_unit_index(from_unit);
    int to_index = get_unit_index(to_unit);

    if (from_index == -1 || to_index == -1) {
        printf("Error: Invalid unit.\n");
        return 1;
    }

    double value;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    double result = value * units[from_index].factor / units[to_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}