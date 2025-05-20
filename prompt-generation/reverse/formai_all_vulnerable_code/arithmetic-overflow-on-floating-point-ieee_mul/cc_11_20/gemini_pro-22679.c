//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// A hearty welcome to our wondrous unit conversion extravaganza!

// Declare our conversion constants. Each constant is a multiplier that transforms a value from one unit to another.
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.555556

// Define our unit types. Each unit type is an enum that represents a different unit of measurement.
enum unit_type {
    METERS,
    FEET,
    POUNDS,
    KILOGRAMS,
    CELSIUS,
    FAHRENHEIT
};

// Declare our unit conversion function. This function takes a value, an input unit type, and an output unit type, and converts the value from the input unit to the output unit.
double convert_units(double value, enum unit_type input_unit, enum unit_type output_unit) {
    // Check if the input and output unit types are the same. If they are, simply return the original value.
    if (input_unit == output_unit) {
        return value;
    }

    // Convert the value to the appropriate unit.
    switch (input_unit) {
        case METERS:
            if (output_unit == FEET) {
                return value * METERS_TO_FEET;
            } else if (output_unit == POUNDS) {
                return value * 2.20462;
            } else if (output_unit == KILOGRAMS) {
                return value * 0.453592;
            } else if (output_unit == CELSIUS) {
                return value * 1.8 + 32;
            } else if (output_unit == FAHRENHEIT) {
                return value * 0.555556;
            }
            break;
        case FEET:
            if (output_unit == METERS) {
                return value * FEET_TO_METERS;
            } else if (output_unit == POUNDS) {
                return value * 0.453592;
            } else if (output_unit == KILOGRAMS) {
                return value * 0.3048;
            } else if (output_unit == CELSIUS) {
                return (value - 32) * 1.8;
            } else if (output_unit == FAHRENHEIT) {
                return value;
            }
            break;
        case POUNDS:
            if (output_unit == METERS) {
                return value * 0.453592;
            } else if (output_unit == FEET) {
                return value * 2.20462;
            } else if (output_unit == KILOGRAMS) {
                return value * 0.3048;
            } else if (output_unit == CELSIUS) {
                return (value - 32) * 1.8;
            } else if (output_unit == FAHRENHEIT) {
                return value;
            }
            break;
        case KILOGRAMS:
            if (output_unit == METERS) {
                return value * 2.20462;
            } else if (output_unit == FEET) {
                return value * 3.28084;
            } else if (output_unit == POUNDS) {
                return value * 0.453592;
            } else if (output_unit == CELSIUS) {
                return (value - 32) * 1.8;
            } else if (output_unit == FAHRENHEIT) {
                return value;
            }
            break;
        case CELSIUS:
            if (output_unit == METERS) {
                return (value - 32) * 1.8;
            } else if (output_unit == FEET) {
                return (value - 32) * 1.8;
            } else if (output_unit == POUNDS) {
                return (value - 32) * 1.8;
            } else if (output_unit == KILOGRAMS) {
                return (value - 32) * 1.8;
            } else if (output_unit == FAHRENHEIT) {
                return value;
            }
            break;
        case FAHRENHEIT:
            if (output_unit == METERS) {
                return (value - 32) * 1.8;
            } else if (output_unit == FEET) {
                return (value - 32) * 1.8;
            } else if (output_unit == POUNDS) {
                return (value - 32) * 1.8;
            } else if (output_unit == KILOGRAMS) {
                return (value - 32) * 1.8;
            } else if (output_unit == CELSIUS) {
                return value;
            }
            break;
    }

    // If the input and output unit types are not recognized, return an error message.
    fprintf(stderr, "Error: unrecognized unit type.\n");
    exit(1);
}

// Declare our main function. This function is the entry point of the program.
int main() {
    // Declare our input value, input unit type, and output unit type.
    double value;
    enum unit_type input_unit;
    enum unit_type output_unit;

    // Prompt the user to enter the value they want to convert.
    printf("Enter the value you want to convert: ");
    scanf("%lf", &value);

    // Prompt the user to enter the input unit type.
    printf("Enter the input unit type (meters, feet, pounds, kilograms, celsius, fahrenheit): ");
    scanf("%s", &input_unit);

    // Prompt the user to enter the output unit type.
    printf("Enter the output unit type (meters, feet, pounds, kilograms, celsius, fahrenheit): ");
    scanf("%s", &output_unit);

    // Convert the value from the input unit type to the output unit type.
    double converted_value = convert_units(value, input_unit, output_unit);

    // Print the converted value.
    printf("The converted value is: %lf\n", converted_value);

    return 0;
}