//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

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
    switch (from_unit) {
        case METERS:
            switch (to_unit) {
                case FEET:
                    return value * METERS_TO_FEET;
                default:
                    return value;
            }
        case FEET:
            switch (to_unit) {
                case METERS:
                    return value * FEET_TO_METERS;
                default:
                    return value;
            }
        case KILOS:
            switch (to_unit) {
                case POUNDS:
                    return value * KILOS_TO_POUNDS;
                default:
                    return value;
            }
        case POUNDS:
            switch (to_unit) {
                case KILOS:
                    return value * POUNDS_TO_KILOS;
                default:
                    return value;
            }
        case CELSIUS:
            switch (to_unit) {
                case FAHRENHEIT:
                    return value * CELSIUS_TO_FAHRENHEIT;
                default:
                    return value;
            }
        case FAHRENHEIT:
            switch (to_unit) {
                case CELSIUS:
                    return value * FAHRENHEIT_TO_CELSIUS;
                default:
                    return value;
            }
    }
}

// Get the unit type from the user
unit_type get_unit_type(char *unit_string) {
    if (strcmp(unit_string, "meters") == 0) {
        return METERS;
    } else if (strcmp(unit_string, "feet") == 0) {
        return FEET;
    } else if (strcmp(unit_string, "kilos") == 0) {
        return KILOS;
    } else if (strcmp(unit_string, "pounds") == 0) {
        return POUNDS;
    } else if (strcmp(unit_string, "celsius") == 0) {
        return CELSIUS;
    } else if (strcmp(unit_string, "fahrenheit") == 0) {
        return FAHRENHEIT;
    } else {
        fprintf(stderr, "Invalid unit type: %s\n", unit_string);
        exit(1);
    }
}

// Get the value from the user
double get_value(void) {
    double value;
    printf("Enter the value: ");
    scanf("%lf", &value);
    return value;
}

// Print the converted value
void print_converted_value(double value, unit_type to_unit) {
    switch (to_unit) {
        case METERS:
            printf("%lf meters\n", value);
            break;
        case FEET:
            printf("%lf feet\n", value);
            break;
        case KILOS:
            printf("%lf kilos\n", value);
            break;
        case POUNDS:
            printf("%lf pounds\n", value);
            break;
        case CELSIUS:
            printf("%lf celsius\n", value);
            break;
        case FAHRENHEIT:
            printf("%lf fahrenheit\n", value);
            break;
    }
}

// Main function
int main(void) {
    // Get the from unit type
    char from_unit_string[20];
    printf("Enter the from unit: ");
    scanf("%s", from_unit_string);
    unit_type from_unit = get_unit_type(from_unit_string);

    // Get the to unit type
    char to_unit_string[20];
    printf("Enter the to unit: ");
    scanf("%s", to_unit_string);
    unit_type to_unit = get_unit_type(to_unit_string);

    // Get the value
    double value = get_value();

    // Convert the value
    double converted_value = convert_units(value, from_unit, to_unit);

    // Print the converted value
    print_converted_value(converted_value, to_unit);

    return 0;
}