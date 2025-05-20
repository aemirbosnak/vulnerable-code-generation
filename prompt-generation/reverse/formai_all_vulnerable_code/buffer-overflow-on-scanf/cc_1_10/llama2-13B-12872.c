//LLAMA2-13B DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_UNITS 10
#define MAX_CONVERTIONS 5

typedef struct unit {
    char name[20];
    double factor;
} unit_t;

typedef struct conversion {
    char from_unit[20];
    char to_unit[20];
    double factor;
} conversion_t;

unit_t units[MAX_UNITS] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"km", 1000},
    {"mi", 1609.344},
    {"yd", 0.9144},
    {"ft", 1.0},
    {"in", 0.0254},
    {"pt", 0.00001}
};

conversion_t conversions[MAX_CONVERTIONS] = {
    {"m", "cm", 0.01},
    {"m", "mm", 0.001},
    {"cm", "mm", 0.01},
    {"km", "mi", 1.609344},
    {"yd", "ft", 0.9144},
    {"yd", "in", 3.28084},
    {"ft", "in", 12},
    {"in", "pt", 0.00001}
};

int main() {
    int unit_index, conversion_index;
    double value, factor;
    char input_unit[20], output_unit[20];

    // prompt user for input value
    printf("Enter a value: ");
    scanf("%lf", &value);

    // prompt user for input unit
    printf("Enter a unit (m/cm/mm/km/mi/yd/ft/in/pt): ");
    fgets(input_unit, 20, stdin);

    // find the index of the input unit in the units array
    for (unit_index = 0; unit_index < MAX_UNITS; unit_index++) {
        if (strcmp(units[unit_index].name, input_unit) == 0) {
            break;
        }
    }

    // if the input unit is not found, print an error message and exit
    if (unit_index == MAX_UNITS) {
        printf("Invalid unit. Please enter a valid unit (m/cm/mm/km/mi/yd/ft/in/pt).\n");
        return 1;
    }

    // find the conversion factor for the input unit
    factor = units[unit_index].factor;

    // prompt user for output unit
    printf("Enter a unit (m/cm/mm/km/mi/yd/ft/in/pt): ");
    fgets(output_unit, 20, stdin);

    // find the index of the output unit in the units array
    for (conversion_index = 0; conversion_index < MAX_CONVERTIONS; conversion_index++) {
        if (strcmp(conversions[conversion_index].from_unit, output_unit) == 0) {
            break;
        }
    }

    // if the output unit is not found, print an error message and exit
    if (conversion_index == MAX_CONVERTIONS) {
        printf("Invalid output unit. Please enter a valid unit (m/cm/mm/km/mi/yd/ft/in/pt).\n");
        return 1;
    }

    // compute the conversion factor for the output unit
    factor = conversions[conversion_index].factor;

    // print the result
    printf("%.2f %s = %.2f %s\n", value * factor, input_unit, value * factor / units[conversion_index].factor, output_unit);

    return 0;
}