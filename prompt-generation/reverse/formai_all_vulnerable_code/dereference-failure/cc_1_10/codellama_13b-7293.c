//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: single-threaded
/*
 * Unit Converter
 *
 * This program converts a given value from one unit to another.
 *
 * Usage:
 *  ./unit_converter <unit1> <unit2> <value>
 *
 * where <unit1> and <unit2> are the units to be converted,
 * and <value> is the value to be converted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the units and their conversion factors
#define METER_TO_INCH 39.37
#define INCH_TO_METER 0.0254
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.55555555555556

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <unit1> <unit2> <value>\n", argv[0]);
        return 1;
    }

    // Get the input values
    char *unit1 = argv[1];
    char *unit2 = argv[2];
    double value = atof(argv[3]);

    // Convert the value based on the units
    if (strcmp(unit1, "meter") == 0 && strcmp(unit2, "inch") == 0) {
        value = value * METER_TO_INCH;
    } else if (strcmp(unit1, "inch") == 0 && strcmp(unit2, "meter") == 0) {
        value = value * INCH_TO_METER;
    } else if (strcmp(unit1, "celsius") == 0 && strcmp(unit2, "fahrenheit") == 0) {
        value = value * CELSIUS_TO_FAHRENHEIT;
    } else if (strcmp(unit1, "fahrenheit") == 0 && strcmp(unit2, "celsius") == 0) {
        value = value * FAHRENHEIT_TO_CELSIUS;
    } else {
        fprintf(stderr, "Invalid unit specified\n");
        return 1;
    }

    // Print the result
    printf("%g %s = %g %s\n", value, unit1, value, unit2);

    return 0;
}