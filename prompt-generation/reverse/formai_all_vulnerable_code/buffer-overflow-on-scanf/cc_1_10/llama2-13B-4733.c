//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERSIONS 5

typedef struct {
    char name[20];
    double value;
} unit_t;

unit_t units[MAX_UNITS] = {
    {"meter", 1.0},
    {"kilometer", 1000.0},
    {"centimeter", 0.01},
    {"millimeter", 0.001},
    {"inch", 0.0254},
    {"foot", 0.3048},
    {"yard", 0.9144},
    {"mile", 1609.344},
    {"liter", 0.001},
    {"gallon", 0.003785},
    {"ounce", 0.0283168}
};

int main() {
    int i, j;
    double conversion_factor[MAX_CONVERSIONS];
    char input_unit[20];
    char output_unit[20];

    // Initialize conversion factors
    for (i = 0; i < MAX_CONVERSIONS; i++) {
        conversion_factor[i] = 1.0;
    }

    // Get input unit and value
    printf("Enter input unit: ");
    scanf("%19s", input_unit);
    double value = 0.0;
    printf("Enter input value: ");
    scanf("%lf", &value);

    // Find the unit in the list
    for (i = 0; i < MAX_UNITS; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            break;
        }
    }

    // Check if the unit is valid
    if (i == MAX_UNITS) {
        printf("Invalid unit\n");
        return 1;
    }

    // Convert the value to the output unit
    for (j = 0; j < MAX_CONVERSIONS; j++) {
        if (conversion_factor[j] != 1.0) {
            conversion_factor[j] = value / units[i].value * conversion_factor[j];
        }
    }

    // Print the converted value
    printf("Output value in %s: %lf\n", units[j].name, conversion_factor[j]);

    return 0;
}