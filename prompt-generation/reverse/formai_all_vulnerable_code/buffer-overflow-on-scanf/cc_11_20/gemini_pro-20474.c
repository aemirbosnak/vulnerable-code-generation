//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define METERS_TO_FEET 3.28084
#define FEET_TO_METERS 0.3048
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462

// Define the unit types
typedef enum {
    METERS,
    FEET,
    POUNDS,
    KILOGRAMS
} unit_type;

// Define the unit converter function
double convert_units(double value, unit_type from_unit, unit_type to_unit) {
    switch (from_unit) {
        case METERS:
            switch (to_unit) {
                case METERS:
                    return value;
                case FEET:
                    return value * METERS_TO_FEET;
                default:
                    return -1;
            }
        case FEET:
            switch (to_unit) {
                case METERS:
                    return value * FEET_TO_METERS;
                case FEET:
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
    // Get the user's input
    double value;
    unit_type from_unit;
    unit_type to_unit;
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);
    printf("Enter the unit of the value (meters, feet, pounds, kilograms): ");
    char unit_string[10];
    scanf("%s", unit_string);
    if (strcmp(unit_string, "meters") == 0) {
        from_unit = METERS;
    } else if (strcmp(unit_string, "feet") == 0) {
        from_unit = FEET;
    } else if (strcmp(unit_string, "pounds") == 0) {
        from_unit = POUNDS;
    } else if (strcmp(unit_string, "kilograms") == 0) {
        from_unit = KILOGRAMS;
    } else {
        printf("Invalid unit. Please enter one of the following: meters, feet, pounds, kilograms\n");
        return EXIT_FAILURE;
    }
    printf("Enter the unit to convert to (meters, feet, pounds, kilograms): ");
    scanf("%s", unit_string);
    if (strcmp(unit_string, "meters") == 0) {
        to_unit = METERS;
    } else if (strcmp(unit_string, "feet") == 0) {
        to_unit = FEET;
    } else if (strcmp(unit_string, "pounds") == 0) {
        to_unit = POUNDS;
    } else if (strcmp(unit_string, "kilograms") == 0) {
        to_unit = KILOGRAMS;
    } else {
        printf("Invalid unit. Please enter one of the following: meters, feet, pounds, kilograms\n");
        return EXIT_FAILURE;
    }

    // Convert the value
    double converted_value = convert_units(value, from_unit, to_unit);

    // Print the converted value
    printf("The converted value is: %lf %s\n", converted_value, unit_string);

    return EXIT_SUCCESS;
}