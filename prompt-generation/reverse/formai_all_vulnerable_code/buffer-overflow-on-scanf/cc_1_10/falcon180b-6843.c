//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    Unit units[MAX_UNITS] = {{"meters", 1.0}, {"kilometers", 1000.0}, {"centimeters", 0.01}, {"millimeters", 0.001}, {"inches", 0.0254}, {"feet", 0.3048}, {"yards", 0.9144}, {"miles", 160934.4}, {"pounds", 0.453592}, {"kilograms", 2.205}};
    int num_units = sizeof(units) / sizeof(Unit);
    char from_unit[20];
    char to_unit[20];
    double value;
    int from_unit_index, to_unit_index;

    printf("Welcome to the Unit Converter!\n");
    printf("Please enter the unit you want to convert from: ");
    scanf("%s", from_unit);
    printf("Please enter the unit you want to convert to: ");
    scanf("%s", to_unit);

    from_unit_index = -1;
    to_unit_index = -1;

    for (int i = 0; i < num_units; i++) {
        if (strcmp(from_unit, units[i].name) == 0) {
            from_unit_index = i;
        }
        if (strcmp(to_unit, units[i].name) == 0) {
            to_unit_index = i;
        }
    }

    if (from_unit_index == -1 || to_unit_index == -1) {
        printf("Invalid units selected. Please try again.\n");
        return 1;
    }

    printf("Please enter the value you want to convert: ");
    scanf("%lf", &value);

    value *= units[from_unit_index].factor;
    value /= units[to_unit_index].factor;

    printf("%.2lf %s = %.2lf %s\n", value, from_unit, value, to_unit);

    return 0;
}