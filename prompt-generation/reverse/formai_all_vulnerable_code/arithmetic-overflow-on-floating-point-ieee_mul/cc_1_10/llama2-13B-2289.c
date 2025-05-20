//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

// Define a struct to store unit information
typedef struct {
    const char *name; // unit name (e.g. "cm", "m", "km")
    double factor;   // conversion factor to/from base unit (e.g. 100 for cm to m)
} Unit;

// Define an array to store all available units
Unit units[MAX_UNITS] = {
    {"cm", 100.0},
    {"m", 1.0},
    {"km", 100000.0},
    {"mm", 0.1},
    {"dm", 10.0},
    {"sm", 0.01},
    {"in", 2.54},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 1609.344}
};

// Define a function to convert between units
double convert(Unit *unit, double value) {
    double factor = unit->factor;
    return value * factor / unit->name[0] - 1;
}

int main() {
    int i, j;
    double value, converted;
    char input[50];

    // Print the available units
    for (i = 0; i < MAX_UNITS; i++) {
        printf("%d: %s (%g)\n", i, units[i].name, units[i].factor);
    }

    // Get the input unit and value
    printf("Enter a value and unit (e.g. 5 cm): ");
    fgets(input, 50, stdin);
    sscanf(input, "%lf %s", &value, units[i].name);

    // Convert the value to the desired unit
    for (j = 0; j < MAX_CONVERTIONS; j++) {
        converted = convert(&units[i], value);
        printf("Value in %s is %g\n", units[j].name, converted);
        value = converted;
    }

    return 0;
}