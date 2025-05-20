//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNITS 10

typedef struct {
    char *name;
    double factor;
} Unit;

int main() {
    int num_units;
    char *input_unit, *output_unit;
    double value, result;
    Unit units[MAX_UNITS];
    int i;

    // Initialize units
    units[0].name = "meters";
    units[0].factor = 1.0;

    units[1].name = "kilometers";
    units[1].factor = 1000.0;

    units[2].name = "centimeters";
    units[2].factor = 0.01;

    units[3].name = "millimeters";
    units[3].factor = 0.001;

    units[4].name = "inches";
    units[4].factor = 0.0254;

    units[5].name = "feet";
    units[5].factor = 0.3048;

    units[6].name = "yards";
    units[6].factor = 0.9144;

    units[7].name = "miles";
    units[7].factor = 160934.4;

    units[8].name = "pounds";
    units[8].factor = 0.453592;

    units[9].name = "kilograms";
    units[9].factor = 2.20462;

    // Get number of units from user
    printf("Enter the number of units to be converted (maximum 10): ");
    scanf("%d", &num_units);

    // Get input and output units from user
    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    // Get value to be converted from user
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);

    // Find the index of the input unit
    for (i = 0; i < num_units; i++) {
        if (strcmp(input_unit, units[i].name) == 0) {
            break;
        }
    }

    // Find the index of the output unit
    for (i = 0; i < num_units; i++) {
        if (strcmp(output_unit, units[i].name) == 0) {
            break;
        }
    }

    // Convert the value
    result = value * units[i].factor;

    // Print the result
    printf("%.2lf %s = %.2lf %s\n", value, input_unit, result, output_unit);

    return 0;
}