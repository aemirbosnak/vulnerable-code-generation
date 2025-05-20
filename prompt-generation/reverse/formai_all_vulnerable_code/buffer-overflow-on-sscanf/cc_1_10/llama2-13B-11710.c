//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define UNIT_CONVERTER_MAX_UNITS 10
#define UNIT_CONVERTER_MAX_CONVERTIONS 5

typedef struct {
    char *name;
    double factor;
} Unit;

typedef struct {
    char *name;
    Unit *units;
    int num_units;
} Conversion;

Unit units[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.34},
    {"ft", 3.28084},
    {"in", 0.0328084},
    {"yd", 0.0109728},
    {"mile", 1.609344}
};

Conversion conversions[] = {
    {"m", {"ft", "in", "yd", "mile"}},
    {"cm", {"in", "ft", "yd", "mile"}},
    {"mm", {"in", "ft", "yd", "mile"}},
    {"km", {"m", "ft", "in", "yd", "mile"}},
    {"mi", {"m", "ft", "in", "yd", "mile"}}
};

int main() {
    int i, j, k;
    char input[100];
    char output[100];
    double value;

    // Get the input unit and value
    printf("Enter a value and a unit (e.g. 5 feet): ");
    fgets(input, 100, stdin);
    sscanf(input, "%lf %s", &value, input + strcspn(input, " ") + 1);

    // Find the input unit in the list
    for (i = 0; i < UNIT_CONVERTER_MAX_UNITS; i++) {
        if (strcmp(units[i].name, input + strcspn(input, " ")) == 0) {
            break;
        }
    }

    // If the input unit is not found, print an error message
    if (i == UNIT_CONVERTER_MAX_UNITS) {
        printf("Invalid unit. Please enter a valid unit (e.g. m, cm, mm, km, mi, ft, in, yd, mile).\n");
        return 1;
    }

    // Find the conversion for the input unit
    for (j = 0; j < UNIT_CONVERTER_MAX_CONVERTIONS; j++) {
        if (conversions[j].name == units[i].name) {
            break;
        }
    }

    // If the conversion for the input unit is not found, print an error message
    if (j == UNIT_CONVERTER_MAX_CONVERTIONS) {
        printf("Invalid unit. Please enter a valid unit (e.g. m, cm, mm, km, mi, ft, in, yd, mile).\n");
        return 1;
    }

    // Calculate the output value
    for (k = 0; k < conversions[j].num_units; k++) {
        if (conversions[j].units[k].name == units[i].name) {
            break;
        }
    }
    value *= conversions[j].units[k].factor;

    // Print the output value and unit
    printf("%.2f %s\n", value, conversions[j].units[k].name);

    return 0;
}