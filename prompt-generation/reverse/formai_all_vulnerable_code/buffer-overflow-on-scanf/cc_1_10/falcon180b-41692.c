//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: ephemeral
/* This is a unique C Unit converter example program */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct unit {
    char *name;
    double factor;
} Unit;

int main() {
    char input[100];
    char output_unit[10];
    double value, result;
    int i, num_units;

    /* Initialize units */
    Unit units[MAX_UNITS] = {{"m", 1}, {"cm", 0.01}, {"mm", 0.001}, {"in", 0.0254}, {"ft", 0.3048}, {"yd", 0.9144}, {"mi", 160934.4}, {"kg", 1}, {"g", 0.001}, {"lb", 0.453592}};
    num_units = sizeof(units) / sizeof(Unit);

    /* Get user input */
    printf("Enter a value and its unit (e.g. 5kg): ");
    scanf("%s", input);

    /* Parse input */
    value = atof(input);
    for (i = 0; i < num_units; i++) {
        if (strcmp(units[i].name, input + strlen(input) - 2) == 0) {
            break;
        }
    }

    /* Convert to base unit */
    result = value * units[i].factor;

    /* Get output unit */
    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    /* Convert to output unit */
    for (i = 0; i < num_units; i++) {
        if (strcmp(output_unit, units[i].name) == 0) {
            result /= units[i].factor;
            break;
        }
    }

    /* Print result */
    printf("%.2f %s = %.2f %s\n", value, input + strlen(input) - 2, result, output_unit);

    return 0;
}
/* This is the end of the unique C Unit converter example program */