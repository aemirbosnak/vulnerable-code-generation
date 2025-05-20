//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

struct unit {
    char *name;
    double factor;
};

void add_unit(struct unit *units, int *num_units, char *name, double factor) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Too many units.\n");
        exit(1);
    }

    struct unit *new_unit = malloc(sizeof(struct unit));
    strcpy(new_unit->name, name);
    new_unit->factor = factor;

    units[*num_units] = *new_unit;
    (*num_units)++;
}

int main() {
    struct unit units[MAX_UNITS];
    int num_units = 0;

    add_unit(units, &num_units, "meter", 1.0);
    add_unit(units, &num_units, "kilometer", 1000.0);
    add_unit(units, &num_units, "inch", 0.0254);
    add_unit(units, &num_units, "foot", 0.3048);
    add_unit(units, &num_units, "yard", 0.9144);
    add_unit(units, &num_units, "mile", 160934.4);

    char input[100];
    while (1) {
        printf("Enter a value to convert:\n");
        scanf("%s", input);

        double value = atof(input);

        char from_unit[20];
        printf("From unit: ");
        scanf("%s", from_unit);

        int from_unit_index = -1;
        for (int i = 0; i < num_units; i++) {
            if (strcmp(units[i].name, from_unit) == 0) {
                from_unit_index = i;
                break;
            }
        }

        if (from_unit_index == -1) {
            printf("Error: Invalid unit.\n");
            continue;
        }

        char to_unit[20];
        printf("To unit: ");
        scanf("%s", to_unit);

        int to_unit_index = -1;
        for (int i = 0; i < num_units; i++) {
            if (strcmp(units[i].name, to_unit) == 0) {
                to_unit_index = i;
                break;
            }
        }

        if (to_unit_index == -1) {
            printf("Error: Invalid unit.\n");
            continue;
        }

        double result = value * units[to_unit_index].factor / units[from_unit_index].factor;

        printf("%.2f %s = %.2f %s\n", value, from_unit, result, to_unit);
    }

    return 0;
}