//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} unit_t;

void add_unit(unit_t *units, int *num_units, char *name, double factor) {
    if (*num_units >= MAX_UNITS) {
        fprintf(stderr, "Error: Maximum number of units reached.\n");
        exit(1);
    }

    units[*num_units].name = strdup(name);
    units[*num_units].factor = factor;

    (*num_units)++;
}

int main() {
    int num_units = 0;
    unit_t *units = malloc(MAX_UNITS * sizeof(unit_t));

    add_unit(units, &num_units, "meter", 1.0);
    add_unit(units, &num_units, "kilometer", 1000.0);
    add_unit(units, &num_units, "inch", 0.0254);
    add_unit(units, &num_units, "foot", 0.3048);
    add_unit(units, &num_units, "yard", 0.9144);
    add_unit(units, &num_units, "mile", 160934.4);

    char input[100];
    while (fgets(input, sizeof(input), stdin)) {
        char *value_str = strtok(input, " ");
        char *from_unit_str = strtok(NULL, " ");
        char *to_unit_str = strtok(NULL, " ");

        if (value_str == NULL || from_unit_str == NULL || to_unit_str == NULL) {
            fprintf(stderr, "Error: Invalid input format.\n");
            continue;
        }

        double value = strtod(value_str, NULL);
        unit_t *from_unit = NULL;
        unit_t *to_unit = NULL;

        for (int i = 0; i < num_units; i++) {
            if (strcmp(from_unit_str, units[i].name) == 0) {
                from_unit = &units[i];
            } else if (strcmp(to_unit_str, units[i].name) == 0) {
                to_unit = &units[i];
            }
        }

        if (from_unit == NULL || to_unit == NULL) {
            fprintf(stderr, "Error: Invalid unit(s) specified.\n");
            continue;
        }

        double result = value * from_unit->factor / to_unit->factor;
        printf("%.2f %s = %.2f %s\n", value, from_unit->name, result, to_unit->name);
    }

    free(units);
    return 0;
}