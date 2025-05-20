//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char *name;
    double factor;
} Unit;

Unit *unit_new(char *name, double factor) {
    Unit *unit = malloc(sizeof(Unit));
    unit->name = strdup(name);
    unit->factor = factor;
    return unit;
}

int unit_cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void unit_free(void *ptr) {
    free(ptr);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s input_unit output_unit value\n", argv[0]);
        return 1;
    }

    char *input_unit_name = argv[1];
    char *output_unit_name = argv[2];
    double value = atof(argv[3]);

    Unit *input_unit = NULL;
    Unit *output_unit = NULL;

    int num_units = 0;
    Unit *units[10];

    units[num_units++] = unit_new("m", 1.0);
    units[num_units++] = unit_new("cm", 0.01);
    units[num_units++] = unit_new("mm", 0.001);
    units[num_units++] = unit_new("km", 1000.0);

    units[num_units++] = unit_new("kg", 1.0);
    units[num_units++] = unit_new("g", 0.001);

    units[num_units++] = unit_new("s", 1.0);
    units[num_units++] = unit_new("ms", 0.001);

    for (int i = 0; i < num_units; i++) {
        if (strcmp(units[i]->name, input_unit_name) == 0) {
            input_unit = units[i];
        } else if (strcmp(units[i]->name, output_unit_name) == 0) {
            output_unit = units[i];
        }
    }

    if (input_unit == NULL || output_unit == NULL) {
        printf("Invalid unit(s)\n");
        return 1;
    }

    double result = value * input_unit->factor / output_unit->factor;

    printf("%.2f %s = %.2f %s\n", value, input_unit_name, result, output_unit_name);

    for (int i = 0; i < num_units; i++) {
        unit_free(units[i]);
    }

    return 0;
}