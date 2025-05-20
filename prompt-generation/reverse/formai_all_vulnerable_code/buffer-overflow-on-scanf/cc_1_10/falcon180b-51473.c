//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_UNITS 4

typedef struct {
    char *name;
    double factor;
} Unit;

void print_units(Unit *units, int num_units) {
    printf("Available units:\n");
    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i+1, units[i].name);
    }
}

int get_unit_index(Unit *units, int num_units, char *unit_name) {
    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, unit_name) == 0) {
            return i;
        }
    }
    return -1;
}

double convert(double value, int from_unit_index, int to_unit_index, Unit *units) {
    return value * units[to_unit_index].factor / units[from_unit_index].factor;
}

int main() {
    Unit units[NUM_UNITS] = {{"meters", 1.0}, {"feet", 3.28084}, {"kilograms", 1.0}, {"pounds", 2.20462}};

    int num_conversions;
    printf("Enter the number of conversions you want to perform: ");
    scanf("%d", &num_conversions);

    for (int i = 0; i < num_conversions; i++) {
        printf("Enter the value you want to convert: ");
        double value;
        scanf("%lf", &value);

        printf("Enter the unit of the value: ");
        char unit_name[20];
        scanf("%s", unit_name);

        int from_unit_index = get_unit_index(units, NUM_UNITS, unit_name);
        if (from_unit_index == -1) {
            printf("Invalid unit.\n");
            continue;
        }

        printf("Enter the unit you want to convert to: ");
        scanf("%s", unit_name);

        int to_unit_index = get_unit_index(units, NUM_UNITS, unit_name);
        if (to_unit_index == -1) {
            printf("Invalid unit.\n");
            continue;
        }

        double result = convert(value, from_unit_index, to_unit_index, units);
        printf("%.2lf %s = %.2lf %s\n", value, unit_name, result, units[to_unit_index].name);
    }

    return 0;
}