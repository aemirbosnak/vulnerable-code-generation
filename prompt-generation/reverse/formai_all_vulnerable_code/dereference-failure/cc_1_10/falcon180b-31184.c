//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 100

typedef struct {
    char *name;
    double factor;
} Unit;

void add_unit(Unit *units, int *num_units, char *name, double factor) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Too many units.\n");
        exit(1);
    }
    strcpy(units[*num_units].name, name);
    units[*num_units].factor = factor;
    (*num_units)++;
}

int main() {
    char input[100];
    char from_unit[10], to_unit[10];
    double value, result;
    int num_units = 0;
    Unit units[MAX_UNITS];

    add_unit(units, &num_units, "m", 1.0);
    add_unit(units, &num_units, "cm", 0.01);
    add_unit(units, &num_units, "mm", 0.001);

    while (1) {
        printf("Enter a conversion (e.g. 10m to cm): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s %s %lf", from_unit, to_unit, &value);

        int from_index = -1;
        int to_index = -1;

        for (int i = 0; i < num_units; i++) {
            if (strcmp(from_unit, units[i].name) == 0) {
                from_index = i;
            }
            if (strcmp(to_unit, units[i].name) == 0) {
                to_index = i;
            }
        }

        if (from_index == -1 || to_index == -1) {
            printf("Invalid units.\n");
            continue;
        }

        result = value * units[from_index].factor / units[to_index].factor;
        printf("%g %s = %g %s\n", value, from_unit, result, to_unit);
    }

    return 0;
}