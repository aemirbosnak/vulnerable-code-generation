//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 20

typedef struct {
    char *unit;
    double factor;
} Unit;

void add_unit(Unit *units, char *unit, double factor) {
    int i = 0;
    while (i < MAX_UNITS && units[i].unit!= NULL) {
        i++;
    }
    if (i == MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }
    strcpy(units[i].unit, unit);
    units[i].factor = factor;
}

int main() {
    Unit units[MAX_UNITS] = {{"m", 1}, {"km", 1000}, {"cm", 0.01}, {"mm", 0.001}, {"in", 0.0254}, {"ft", 0.3048}, {"yd", 0.9144}, {"mi", 160934.4}, {"l", 1}, {"ml", 0.001}, {"cl", 0.01}, {"dl", 0.1}, {"fl oz", 0.0295735}, {"gal", 3.78541}, {"kg", 1}, {"g", 0.001}, {"oz", 0.0283495}, {"lb", 0.453592}, {"F", 1}, {"C", 0.555555}};
    int num_units = 0;

    while (num_units < MAX_UNITS) {
        char input[50];
        printf("Enter a unit to add (e.g. m, km, cm, in, ft, yd, mi, l, ml, cl, dl, fl oz, gal, kg, g, oz, lb, F, C): ");
        scanf("%s", input);
        if (strlen(input) == 0) {
            continue;
        }
        add_unit(units, input, 1);
        num_units++;
    }

    while (1) {
        printf("Enter a value to convert: ");
        double value;
        scanf("%lf", &value);
        char unit[50];
        printf("Enter the unit of the value: ");
        scanf("%s", unit);

        int i = 0;
        while (units[i].unit!= NULL && strcmp(unit, units[i].unit)!= 0) {
            i++;
        }

        if (units[i].unit == NULL) {
            printf("Error: Unknown unit.\n");
            continue;
        }

        double result = value * units[i].factor;
        printf("%.2lf %s = %.2lf %s\n", value, unit, result, units[i].unit);
    }

    return 0;
}