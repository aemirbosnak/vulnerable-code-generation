//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>

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

// Define the conversion function
double convert(double value, unit_type from_unit, unit_type to_unit) {
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
        case CELSIUS:
            switch (to_unit) {
                case CELSIUS:
                    return value;
                case FAHRENHEIT:
                    return value * CELSIUS_TO_FAHRENHEIT;
                default:
                    return -1;
            }
        case FAHRENHEIT:
            switch (to_unit) {
                case CELSIUS:
                    return value * FAHRENHEIT_TO_CELSIUS;
                case FAHRENHEIT:
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
    // Get the input from the user
    printf("Enter the value to be converted: ");
    double value;
    scanf("%lf", &value);

    printf("Enter the unit of the value (meters, feet, pounds, kilograms, celsius, fahrenheit): ");
    char unit_string[20];
    scanf("%s", unit_string);

    // Convert the unit string to the corresponding unit type
    unit_type from_unit;
    if (strcmp(unit_string, "meters") == 0) {
        from_unit = METERS;
    } else if (strcmp(unit_string, "feet") == 0) {
        from_unit = FEET;
    } else if (strcmp(unit_string, "pounds") == 0) {
        from_unit = POUNDS;
    } else if (strcmp(unit_string, "kilograms") == 0) {
        from_unit = KILOGRAMS;
    } else if (strcmp(unit_string, "celsius") == 0) {
        from_unit = CELSIUS;
    } else if (strcmp(unit_string, "fahrenheit") == 0) {
        from_unit = FAHRENHEIT;
    } else {
        printf("Invalid unit entered.\n");
        return 1;
    }

    printf("Enter the unit to convert to (meters, feet, pounds, kilograms, celsius, fahrenheit): ");
    scanf("%s", unit_string);

    // Convert the unit string to the corresponding unit type
    unit_type to_unit;
    if (strcmp(unit_string, "meters") == 0) {
        to_unit = METERS;
    } else if (strcmp(unit_string, "feet") == 0) {
        to_unit = FEET;
    } else if (strcmp(unit_string, "pounds") == 0) {
        to_unit = POUNDS;
    } else if (strcmp(unit_string, "kilograms") == 0) {
        to_unit = KILOGRAMS;
    } else if (strcmp(unit_string, "celsius") == 0) {
        to_unit = CELSIUS;
    } else if (strcmp(unit_string, "fahrenheit") == 0) {
        to_unit = FAHRENHEIT;
    } else {
        printf("Invalid unit entered.\n");
        return 1;
    }

    // Convert the value
    double converted_value = convert(value, from_unit, to_unit);

    // Print the converted value
    printf("The converted value is: %lf\n", converted_value);

    return 0;
}