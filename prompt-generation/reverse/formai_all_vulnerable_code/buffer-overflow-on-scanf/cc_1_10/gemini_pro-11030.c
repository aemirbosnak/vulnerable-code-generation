//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.555556

// Define the unit types
typedef enum {
    METERS,
    FEET,
    POUNDS,
    KILOGRAMS,
    CELSIUS,
    FAHRENHEIT
} unit_type;

// Define the unit conversion function
double convert_units(double value, unit_type from_unit, unit_type to_unit) {
    switch (from_unit) {
        case METERS:
            switch (to_unit) {
                case METERS:
                    return value;
                case FEET:
                    return value * METERS_TO_FEET;
                default:
                    return -1; // Error: Invalid conversion
            }
        case FEET:
            switch (to_unit) {
                case METERS:
                    return value * FEET_TO_METERS;
                case FEET:
                    return value;
                default:
                    return -1; // Error: Invalid conversion
            }
        case POUNDS:
            switch (to_unit) {
                case POUNDS:
                    return value;
                case KILOGRAMS:
                    return value * POUNDS_TO_KILOGRAMS;
                default:
                    return -1; // Error: Invalid conversion
            }
        case KILOGRAMS:
            switch (to_unit) {
                case POUNDS:
                    return value * KILOGRAMS_TO_POUNDS;
                case KILOGRAMS:
                    return value;
                default:
                    return -1; // Error: Invalid conversion
            }
        case CELSIUS:
            switch (to_unit) {
                case CELSIUS:
                    return value;
                case FAHRENHEIT:
                    return value * CELSIUS_TO_FAHRENHEIT;
                default:
                    return -1; // Error: Invalid conversion
            }
        case FAHRENHEIT:
            switch (to_unit) {
                case CELSIUS:
                    return value * FAHRENHEIT_TO_CELSIUS;
                case FAHRENHEIT:
                    return value;
                default:
                    return -1; // Error: Invalid conversion
            }
        default:
            return -1; // Error: Invalid unit type
    }
}

// Define the main function
int main() {
    // Get the input value, from unit, and to unit from the user
    double value;
    unit_type from_unit, to_unit;
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the from unit (meters, feet, pounds, kilograms, celsius, fahrenheit): ");
    scanf(" %s", &from_unit);
    printf("Enter the to unit (meters, feet, pounds, kilograms, celsius, fahrenheit): ");
    scanf(" %s", &to_unit);

    // Convert the value using the convert_units function
    double converted_value = convert_units(value, from_unit, to_unit);

    // Print the converted value
    printf("The converted value is: %lf\n", converted_value);

    return 0;
}