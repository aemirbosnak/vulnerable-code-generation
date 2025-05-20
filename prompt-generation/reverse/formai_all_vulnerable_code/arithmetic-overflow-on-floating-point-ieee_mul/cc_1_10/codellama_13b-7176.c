//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: protected
/*
 * C Unit Converter
 *
 * Prompts the user to enter a value and a unit of measurement,
 * and then converts the value to the equivalent unit in another system.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256
#define MAX_UNITS 5

// Define the units of measurement
typedef enum {
    UNIT_NONE,
    UNIT_METERS,
    UNIT_FEET,
    UNIT_CENTIMETERS,
    UNIT_INCHES
} unit_t;

// Define the conversion factors between units
const double conversion_factors[MAX_UNITS][MAX_UNITS] = {
    {1.0, 3.28084, 30.48, 12.0, 0.393701},
    {0.3048, 1.0, 0.0833333, 0.0254, 0.00328084},
    {0.01, 0.00328084, 1.0, 0.000625, 0.00000833333},
    {0.000625, 0.00000833333, 0.00328084, 1.0, 0.0000254},
    {0.0000254, 0.00000833333, 0.000625, 0.00328084, 1.0}
};

// Define the unit names
const char* unit_names[MAX_UNITS] = {
    "None", "Meters", "Feet", "Centimeters", "Inches"
};

// Prompt the user to enter a value and a unit of measurement
void prompt_user(double* value, unit_t* unit) {
    printf("Enter a value: ");
    scanf("%lf", value);

    printf("Enter a unit (%s): ", unit_names[UNIT_NONE]);
    scanf("%s", unit);
}

// Convert the value from one unit to another
void convert_value(double value, unit_t from_unit, unit_t to_unit, double* result) {
    if (from_unit == to_unit) {
        *result = value;
    } else {
        *result = value * conversion_factors[from_unit][to_unit];
    }
}

int main() {
    double value;
    unit_t from_unit, to_unit;

    // Prompt the user to enter a value and a unit of measurement
    prompt_user(&value, &from_unit);

    // Print the original value and unit
    printf("Value: %g %s\n", value, unit_names[from_unit]);

    // Convert the value to another unit
    to_unit = UNIT_METERS;
    double converted_value;
    convert_value(value, from_unit, to_unit, &converted_value);

    // Print the converted value and unit
    printf("Converted value: %g %s\n", converted_value, unit_names[to_unit]);

    return 0;
}