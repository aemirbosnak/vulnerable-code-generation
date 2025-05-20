//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the conversion factors
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define KILOS_TO_POUNDS 2.20462
#define POUNDS_TO_KILOS 0.453592
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.555556

// Define the unit types
typedef enum {
    METERS,
    FEET,
    KILOS,
    POUNDS,
    CELSIUS,
    FAHRENHEIT
} unit_type;

// Define the unit conversion function
double convert_units(double value, unit_type from_unit, unit_type to_unit) {
    // Check if the units are the same
    if (from_unit == to_unit) {
        return value;
    }

    // Convert the value to the intermediate unit
    double intermediate_value;
    switch (from_unit) {
        case METERS:
            intermediate_value = value * METERS_TO_FEET;
            break;
        case FEET:
            intermediate_value = value * FEET_TO_METERS;
            break;
        case KILOS:
            intermediate_value = value * KILOS_TO_POUNDS;
            break;
        case POUNDS:
            intermediate_value = value * POUNDS_TO_KILOS;
            break;
        case CELSIUS:
            intermediate_value = value * CELSIUS_TO_FAHRENHEIT;
            break;
        case FAHRENHEIT:
            intermediate_value = value * FAHRENHEIT_TO_CELSIUS;
            break;
    }

    // Convert the intermediate value to the desired unit
    double converted_value;
    switch (to_unit) {
        case METERS:
            converted_value = intermediate_value * FEET_TO_METERS;
            break;
        case FEET:
            converted_value = intermediate_value * METERS_TO_FEET;
            break;
        case KILOS:
            converted_value = intermediate_value * POUNDS_TO_KILOS;
            break;
        case POUNDS:
            converted_value = intermediate_value * KILOS_TO_POUNDS;
            break;
        case CELSIUS:
            converted_value = intermediate_value * FAHRENHEIT_TO_CELSIUS;
            break;
        case FAHRENHEIT:
            converted_value = intermediate_value * CELSIUS_TO_FAHRENHEIT;
            break;
    }

    return converted_value;
}

// Define the main function
int main() {
    // Get the input value and unit type
    double value;
    unit_type from_unit;
    unit_type to_unit;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit type to convert from (meters, feet, kilos, pounds, celsius, fahrenheit): ");
    scanf("%d", &from_unit);
    printf("Enter the unit type to convert to (meters, feet, kilos, pounds, celsius, fahrenheit): ");
    scanf("%d", &to_unit);

    // Convert the value and print the result
    double converted_value = convert_units(value, from_unit, to_unit);
    printf("The converted value is: %.2f\n", converted_value);

    return 0;
}