//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_TO_CENTIMETERS 2.54
#define CENTIMETERS_TO_INCHES 0.393701
#define POUNDS_TO_KILOGRAMS 0.453592
#define KILOGRAMS_TO_POUNDS 2.20462
#define MILES_TO_KILOMETERS 1.60934
#define KILOMETERS_TO_MILES 0.621371

// Define the unit types
typedef enum {
    INCHES,
    CENTIMETERS,
    POUNDS,
    KILOGRAMS,
    MILES,
    KILOMETERS
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
        case INCHES:
            intermediate_value = value * INCHES_TO_CENTIMETERS;
            break;
        case CENTIMETERS:
            intermediate_value = value * CENTIMETERS_TO_INCHES;
            break;
        case POUNDS:
            intermediate_value = value * POUNDS_TO_KILOGRAMS;
            break;
        case KILOGRAMS:
            intermediate_value = value * KILOGRAMS_TO_POUNDS;
            break;
        case MILES:
            intermediate_value = value * MILES_TO_KILOMETERS;
            break;
        case KILOMETERS:
            intermediate_value = value * KILOMETERS_TO_MILES;
            break;
    }

    // Convert the value to the final unit
    double final_value;
    switch (to_unit) {
        case INCHES:
            final_value = intermediate_value / INCHES_TO_CENTIMETERS;
            break;
        case CENTIMETERS:
            final_value = intermediate_value / CENTIMETERS_TO_INCHES;
            break;
        case POUNDS:
            final_value = intermediate_value / POUNDS_TO_KILOGRAMS;
            break;
        case KILOGRAMS:
            final_value = intermediate_value / KILOGRAMS_TO_POUNDS;
            break;
        case MILES:
            final_value = intermediate_value / MILES_TO_KILOMETERS;
            break;
        case KILOMETERS:
            final_value = intermediate_value / KILOMETERS_TO_MILES;
            break;
    }

    return final_value;
}

// Define the main function
int main() {
    // Get the input from the user
    printf("Enter the value to convert: ");
    double value;
    scanf("%lf", &value);

    printf("Enter the unit of the value: ");
    char unit_string[10];
    scanf("%s", unit_string);

    // Convert the unit string to the unit type
    unit_type from_unit;
    if (strcmp(unit_string, "inches") == 0) {
        from_unit = INCHES;
    } else if (strcmp(unit_string, "centimeters") == 0) {
        from_unit = CENTIMETERS;
    } else if (strcmp(unit_string, "pounds") == 0) {
        from_unit = POUNDS;
    } else if (strcmp(unit_string, "kilograms") == 0) {
        from_unit = KILOGRAMS;
    } else if (strcmp(unit_string, "miles") == 0) {
        from_unit = MILES;
    } else if (strcmp(unit_string, "kilometers") == 0) {
        from_unit = KILOMETERS;
    } else {
        printf("Invalid unit: %s\n", unit_string);
        return 1;
    }

    printf("Enter the unit to convert to: ");
    scanf("%s", unit_string);

    // Convert the unit string to the unit type
    unit_type to_unit;
    if (strcmp(unit_string, "inches") == 0) {
        to_unit = INCHES;
    } else if (strcmp(unit_string, "centimeters") == 0) {
        to_unit = CENTIMETERS;
    } else if (strcmp(unit_string, "pounds") == 0) {
        to_unit = POUNDS;
    } else if (strcmp(unit_string, "kilograms") == 0) {
        to_unit = KILOGRAMS;
    } else if (strcmp(unit_string, "miles") == 0) {
        to_unit = MILES;
    } else if (strcmp(unit_string, "kilometers") == 0) {
        to_unit = KILOMETERS;
    } else {
        printf("Invalid unit: %s\n", unit_string);
        return 1;
    }

    // Convert the value
    double final_value = convert_units(value, from_unit, to_unit);

    // Print the result
    printf("%lf %s is equal to %lf %s\n", value, unit_string, final_value, unit_string);

    return 0;
}