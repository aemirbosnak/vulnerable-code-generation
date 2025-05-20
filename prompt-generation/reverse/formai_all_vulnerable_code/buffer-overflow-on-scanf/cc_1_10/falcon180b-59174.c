//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_UNITS 10 // Maximum number of units to be converted

typedef struct {
    char *name; // Name of the unit
    double factor; // Conversion factor to base unit
} Unit;

void add_unit(Unit *units, int *num_units, char *name, double factor) {
    if (*num_units >= MAX_UNITS) {
        printf("Error: Maximum number of units (%d) exceeded.\n", MAX_UNITS);
        exit(1);
    }
    units[*num_units].name = strdup(name);
    units[*num_units].factor = factor;
    (*num_units)++;
}

int main() {
    char input[100];
    char *delimiter = ",";
    char *token = NULL;
    char *saveptr = NULL;
    double value, result = 0;
    int num_units = 0;
    Unit units[MAX_UNITS];
    bool found_match = false;

    add_unit(units, &num_units, "m", 1.0);
    add_unit(units, &num_units, "cm", 0.01);
    add_unit(units, &num_units, "mm", 0.001);
    add_unit(units, &num_units, "in", 0.0254);
    add_unit(units, &num_units, "ft", 0.3048);
    add_unit(units, &num_units, "yd", 0.9144);

    printf("Enter a value followed by its unit (e.g. 5m): ");
    scanf("%s", input);

    token = strtok_r(input, delimiter, &saveptr);
    value = atof(token);

    while ((token = strtok_r(NULL, delimiter, &saveptr))) {
        for (int i = 0; i < num_units; i++) {
            if (strcmp(token, units[i].name) == 0) {
                result = value * units[i].factor;
                found_match = true;
                break;
            }
        }
    }

    if (!found_match) {
        printf("Error: Invalid unit.\n");
        exit(1);
    }

    printf("Result: %.2f\n", result);

    return 0;
}