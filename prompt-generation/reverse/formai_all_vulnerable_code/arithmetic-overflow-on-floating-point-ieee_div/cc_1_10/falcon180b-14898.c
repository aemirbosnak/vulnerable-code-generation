//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double factor;
} Unit;

void print_units(Unit *units, int num_units) {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%s\n", units[i].name);
    }
}

int get_unit_index(Unit *units, int num_units, char *unit_name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(unit_name, units[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(double value, int from_index, int to_index, Unit *units) {
    return value * units[to_index].factor / units[from_index].factor;
}

int main() {
    Unit units[] = {{"meters", 1.0}, {"feet", 3.28084}, {"inches", 39.3701}, {"kilometers", 0.001}, {"miles", 0.000621371}, {"yards", 1.09361}};
    int num_units = sizeof(units) / sizeof(units[0]);

    printf("Welcome to the Unit Converter!\n");
    print_units(units, num_units);

    char from_unit[50], to_unit[50];
    printf("Enter the unit you want to convert from: ");
    scanf("%s", from_unit);
    printf("Enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    int from_index = get_unit_index(units, num_units, from_unit);
    int to_index = get_unit_index(units, num_units, to_unit);

    if (from_index == -1 || to_index == -1) {
        printf("Invalid unit.\n");
        return 1;
    }

    double value;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    double result = convert(value, from_index, to_index, units);

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, result, to_unit);

    return 0;
}