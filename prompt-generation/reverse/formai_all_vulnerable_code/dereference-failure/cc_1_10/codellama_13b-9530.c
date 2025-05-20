//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: grateful
/*
 * Unit Converter
 *
 * This program takes a measurement value and unit of measurement as input,
 * and converts it to the desired unit of measurement.
 *
 * Usage:
 *  - ./unit_converter <value> <unit> <desired_unit>
 *
 * Example:
 *  - ./unit_converter 100 cm m
 *  - ./unit_converter 100 m cm
 *  - ./unit_converter 100 kg m
 *  - ./unit_converter 100 m kg
 *
 * Author: [Your Name]
 */

#include <stdio.h>

// Define a structure to store the conversion factors
struct conversion_factor {
    char unit[10];
    double factor;
};

// Define an array of conversion factors
struct conversion_factor conversion_factors[] = {
    {"m", 1.0},
    {"cm", 0.01},
    {"mm", 0.001},
    {"kg", 1.0},
    {"g", 0.001},
    {"lb", 2.20462},
    {"oz", 0.0625},
    {"in", 0.0254},
    {"ft", 0.3048},
    {"yd", 0.9144},
    {"mi", 1609.34},
};

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        printf("Usage: ./unit_converter <value> <unit> <desired_unit>\n");
        return 1;
    }

    // Get the value, unit, and desired unit from the command line arguments
    double value = atof(argv[1]);
    char *unit = argv[2];
    char *desired_unit = argv[3];

    // Find the conversion factor for the given unit and desired unit
    double conversion_factor = 1.0;
    for (int i = 0; i < sizeof(conversion_factors) / sizeof(conversion_factors[0]); i++) {
        if (strcmp(conversion_factors[i].unit, unit) == 0 &&
            strcmp(conversion_factors[i].unit, desired_unit) == 0) {
            conversion_factor = conversion_factors[i].factor;
            break;
        }
    }

    // Convert the value to the desired unit
    double result = value * conversion_factor;

    // Print the result
    printf("%f %s = %f %s\n", value, unit, result, desired_unit);

    return 0;
}