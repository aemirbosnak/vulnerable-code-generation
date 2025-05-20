//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define a struct to hold the unit information
struct unit {
    char name[20]; // unit name (e.g. "meter", "foot", etc.)
    double conversion_factor; // conversion factor to/from base unit (e.g. 100 for cm to m)
};

// Define a function to convert between units
void convert(struct unit *from, struct unit *to, double value) {
    // Calculate the conversion factor
    double factor = from->conversion_factor / to->conversion_factor;

    // Convert the value
    double converted_value = value * factor;

    // Print the converted value and the new unit
    printf("Result: %f %s\n", converted_value, to->name);
}

// Define the units to be converted
struct unit units[] = {
    {"meter", 1.0},
    {"foot", 0.3048},
    {"centimeter", 0.01},
    {"kilometer", 1000},
    {"yard", 0.9144},
    {"inch", 0.0254}
};

int main() {
    int i, j;
    double value;

    // Print the list of units
    for (i = 0; i < sizeof(units) / sizeof(struct unit); i++) {
        printf("%d: %s\n", i, units[i].name);
    }

    // Ask the user for the input value and unit
    printf("Enter a value and a unit: ");
    scanf("%lf %s", &value, &units[0].name);

    // Convert the value to the specified unit
    for (j = 0; j < sizeof(units) / sizeof(struct unit); j++) {
        if (strcmp(units[j].name, units[0].name) == 0) {
            convert(&units[0], &units[j], value);
            break;
        }
    }

    return 0;
}