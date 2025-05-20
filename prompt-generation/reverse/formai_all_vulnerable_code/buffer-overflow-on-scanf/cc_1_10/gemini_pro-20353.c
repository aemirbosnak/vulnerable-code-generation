//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
const double FEET_TO_METERS = 0.3048;
const double METERS_TO_FEET = 3.28084;
const double POUNDS_TO_KILOGRAMS = 0.453592;
const double KILOGRAMS_TO_POUNDS = 2.20462;

// Define the unit types
typedef enum {
    FEET,
    METERS,
    POUNDS,
    KILOGRAMS
} unit_type;

// Define the unit conversion function
double convert_unit(double value, unit_type from_unit, unit_type to_unit) {
    switch (from_unit) {
        case FEET:
            switch (to_unit) {
                case FEET:
                    return value;
                case METERS:
                    return value * FEET_TO_METERS;
                default:
                    return -1;
            }
        case METERS:
            switch (to_unit) {
                case FEET:
                    return value * METERS_TO_FEET;
                case METERS:
                    return value;
                default:
                    return -1;
            }
        case POUNDS:
            switch (to_unit) {
                case POUNDS:
                    return value;
                case KILOGRAMS:
                    return value * POUNDS_TO_KILOGRAMS;
                default:
                    return -1;
            }
        case KILOGRAMS:
            switch (to_unit) {
                case POUNDS:
                    return value * KILOGRAMS_TO_POUNDS;
                case KILOGRAMS:
                    return value;
                default:
                    return -1;
            }
        default:
            return -1;
    }
}

// Define the main function
int main() {
    // Get the input value and unit type from the user
    double value;
    unit_type from_unit, to_unit;
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);
    printf("Enter the unit type of the value (feet, meters, pounds, kilograms): ");
    scanf("%s", &from_unit);
    printf("Enter the unit type to convert to (feet, meters, pounds, kilograms): ");
    scanf("%s", &to_unit);

    // Convert the value to the desired unit
    double converted_value = convert_unit(value, from_unit, to_unit);

    // Print the converted value
    printf("The converted value is: %lf %s\n", converted_value, to_unit);

    return 0;
}