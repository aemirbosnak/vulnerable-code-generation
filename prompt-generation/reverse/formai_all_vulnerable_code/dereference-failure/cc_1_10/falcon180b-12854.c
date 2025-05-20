//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
    int index;
} unit;

unit units[MAX_UNITS];
int num_units;

void add_unit(char *name, double factor) {
    if (num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units reached.\n");
        return;
    }

    units[num_units].name = strdup(name);
    units[num_units].factor = factor;
    units[num_units].index = num_units;

    num_units++;
}

void print_units() {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
}

double convert(double value, int from_unit, int to_unit) {
    if (from_unit == to_unit) {
        return value;
    }

    for (int i = 0; i < num_units; i++) {
        if (units[i].index == from_unit) {
            for (int j = 0; j < num_units; j++) {
                if (units[j].index == to_unit) {
                    return value * units[i].factor / units[j].factor;
                }
            }
        }
    }

    printf("Error: Invalid unit conversion.\n");
    return 0;
}

int main() {
    add_unit("meters", 1);
    add_unit("feet", 3.28084);
    add_unit("inches", 39.3701);
    add_unit("kilograms", 1);
    add_unit("pounds", 2.20462);
    add_unit("grams", 0.001);
    add_unit("ounces", 0.035274);

    print_units();

    double distance = 100;
    int from_unit = 0;
    int to_unit = 1;

    double result = convert(distance, from_unit, to_unit);

    printf("%.2f %s = %.2f %s\n", distance, units[from_unit].name, result, units[to_unit].name);

    return 0;
}