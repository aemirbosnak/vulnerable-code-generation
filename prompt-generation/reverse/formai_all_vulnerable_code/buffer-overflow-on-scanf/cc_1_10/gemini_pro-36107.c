//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_TO_CENTIMETERS 2.54
#define FEET_TO_METERS 0.3048
#define POUNDS_TO_KILOGRAMS 0.453592
#define GALLONS_TO_LITERS 3.78541

// Define the unit types
typedef enum unit_type {
    INCHES,
    CENTIMETERS,
    FEET,
    METERS,
    POUNDS,
    KILOGRAMS,
    GALLONS,
    LITERS
} unit_type;

// Define the unit conversion function
double convert_units(double value, unit_type from_unit, unit_type to_unit) {
    // Check if the units are the same
    if (from_unit == to_unit) {
        return value;
    }

    // Convert the value to the base unit (inches)
    double base_value;
    switch (from_unit) {
        case INCHES:
            base_value = value;
            break;
        case CENTIMETERS:
            base_value = value / INCHES_TO_CENTIMETERS;
            break;
        case FEET:
            base_value = value / FEET_TO_METERS;
            break;
        case METERS:
            base_value = value / METERS;
            break;
        case POUNDS:
            base_value = value / POUNDS_TO_KILOGRAMS;
            break;
        case KILOGRAMS:
            base_value = value / KILOGRAMS;
            break;
        case GALLONS:
            base_value = value / GALLONS_TO_LITERS;
            break;
        case LITERS:
            base_value = value / LITERS;
            break;
    }

    // Convert the value from the base unit to the desired unit
    double converted_value;
    switch (to_unit) {
        case INCHES:
            converted_value = base_value * INCHES_TO_CENTIMETERS;
            break;
        case CENTIMETERS:
            converted_value = base_value;
            break;
        case FEET:
            converted_value = base_value * FEET_TO_METERS;
            break;
        case METERS:
            converted_value = base_value;
            break;
        case POUNDS:
            converted_value = base_value * POUNDS_TO_KILOGRAMS;
            break;
        case KILOGRAMS:
            converted_value = base_value;
            break;
        case GALLONS:
            converted_value = base_value * GALLONS_TO_LITERS;
            break;
        case LITERS:
            converted_value = base_value;
            break;
    }

    return converted_value;
}

// Get the unit type from the user
unit_type get_unit_type(char *unit) {
    if (strcmp(unit, "in") == 0 || strcmp(unit, "inches") == 0) {
        return INCHES;
    } else if (strcmp(unit, "cm") == 0 || strcmp(unit, "centimeters") == 0) {
        return CENTIMETERS;
    } else if (strcmp(unit, "ft") == 0 || strcmp(unit, "feet") == 0) {
        return FEET;
    } else if (strcmp(unit, "m") == 0 || strcmp(unit, "meters") == 0) {
        return METERS;
    } else if (strcmp(unit, "lb") == 0 || strcmp(unit, "pounds") == 0) {
        return POUNDS;
    } else if (strcmp(unit, "kg") == 0 || strcmp(unit, "kilograms") == 0) {
        return KILOGRAMS;
    } else if (strcmp(unit, "gal") == 0 || strcmp(unit, "gallons") == 0) {
        return GALLONS;
    } else if (strcmp(unit, "l") == 0 || strcmp(unit, "liters") == 0) {
        return LITERS;
    } else {
        printf("Invalid unit: %s\n", unit);
        exit(1);
    }
}

// Get the value from the user
double get_value() {
    double value;
    printf("Enter the value: ");
    scanf("%lf", &value);
    return value;
}

// Print the converted value
void print_converted_value(double value, unit_type to_unit) {
    char *unit_string;
    switch (to_unit) {
        case INCHES:
            unit_string = "inches";
            break;
        case CENTIMETERS:
            unit_string = "centimeters";
            break;
        case FEET:
            unit_string = "feet";
            break;
        case METERS:
            unit_string = "meters";
            break;
        case POUNDS:
            unit_string = "pounds";
            break;
        case KILOGRAMS:
            unit_string = "kilograms";
            break;
        case GALLONS:
            unit_string = "gallons";
            break;
        case LITERS:
            unit_string = "liters";
            break;
    }
    printf("The converted value is: %.2f %s\n", value, unit_string);
}

// Main function
int main() {
    // Get the value and unit from the user
    double value = get_value();
    char unit[10];
    printf("Enter the unit: ");
    scanf("%s", unit);
    unit_type from_unit = get_unit_type(unit);

    // Get the desired unit from the user
    char to_unit_string[10];
    printf("Enter the desired unit: ");
    scanf("%s", to_unit_string);
    unit_type to_unit = get_unit_type(to_unit_string);

    // Convert the value
    double converted_value = convert_units(value, from_unit, to_unit);

    // Print the converted value
    print_converted_value(converted_value, to_unit);

    return 0;
}