//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define the conversion factors
#define INCHES_PER_CM 2.54
#define CM_PER_INCH 0.393701
#define METERS_PER_FEET 0.3048
#define FEET_PER_METER 3.28084
#define POUNDS_PER_KG 2.20462
#define KG_PER_POUND 0.453592
#define CELSIUS_TO_FAHRENHEIT 1.8
#define FAHRENHEIT_TO_CELSIUS 0.555556

// Define the unit types
enum unit_type {
    INCHES,
    CM,
    FEET,
    METERS,
    POUNDS,
    KG,
    CELSIUS,
    FAHRENHEIT
};

// Define the conversion function
double convert(double value, enum unit_type from, enum unit_type to) {
    switch (from) {
        case INCHES:
            if (to == CM) {
                return value * INCHES_PER_CM;
            } else if (to == FEET) {
                return value / 12;
            } else if (to == METERS) {
                return value * METERS_PER_FEET;
            }
            break;
        case CM:
            if (to == INCHES) {
                return value * CM_PER_INCH;
            } else if (to == FEET) {
                return value * CM_PER_INCH / 12;
            } else if (to == METERS) {
                return value * METERS_PER_FEET;
            }
            break;
        case FEET:
            if (to == INCHES) {
                return value * 12;
            } else if (to == CM) {
                return value * 12 * CM_PER_INCH;
            } else if (to == METERS) {
                return value * METERS_PER_FEET;
            }
            break;
        case METERS:
            if (to == INCHES) {
                return value * FEET_PER_METER * 12;
            } else if (to == CM) {
                return value * FEET_PER_METER * 12 * CM_PER_INCH;
            } else if (to == FEET) {
                return value * FEET_PER_METER;
            }
            break;
        case POUNDS:
            if (to == KG) {
                return value * POUNDS_PER_KG;
            }
            break;
        case KG:
            if (to == POUNDS) {
                return value * KG_PER_POUND;
            }
            break;
        case CELSIUS:
            if (to == FAHRENHEIT) {
                return value * CELSIUS_TO_FAHRENHEIT + 32;
            }
            break;
        case FAHRENHEIT:
            if (to == CELSIUS) {
                return (value - 32) * FAHRENHEIT_TO_CELSIUS;
            }
            break;
    }

    // If the conversion is not supported, return the original value
    return value;
}

int main() {
    // Get the input from the user
    double value;
    char from_unit[100];
    char to_unit[100];
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    printf("Enter the unit to convert from: ");
    scanf("%s", from_unit);
    printf("Enter the unit to convert to: ");
    scanf("%s", to_unit);

    // Convert the unit types to enum values
    enum unit_type from;
    enum unit_type to;
    if (strcmp(from_unit, "inches") == 0) {
        from = INCHES;
    } else if (strcmp(from_unit, "cm") == 0) {
        from = CM;
    } else if (strcmp(from_unit, "feet") == 0) {
        from = FEET;
    } else if (strcmp(from_unit, "meters") == 0) {
        from = METERS;
    } else if (strcmp(from_unit, "pounds") == 0) {
        from = POUNDS;
    } else if (strcmp(from_unit, "kg") == 0) {
        from = KG;
    } else if (strcmp(from_unit, "celsius") == 0) {
        from = CELSIUS;
    } else if (strcmp(from_unit, "fahrenheit") == 0) {
        from = FAHRENHEIT;
    } else {
        printf("Invalid unit type: %s\n", from_unit);
        return 1;
    }

    if (strcmp(to_unit, "inches") == 0) {
        to = INCHES;
    } else if (strcmp(to_unit, "cm") == 0) {
        to = CM;
    } else if (strcmp(to_unit, "feet") == 0) {
        to = FEET;
    } else if (strcmp(to_unit, "meters") == 0) {
        to = METERS;
    } else if (strcmp(to_unit, "pounds") == 0) {
        to = POUNDS;
    } else if (strcmp(to_unit, "kg") == 0) {
        to = KG;
    } else if (strcmp(to_unit, "celsius") == 0) {
        to = CELSIUS;
    } else if (strcmp(to_unit, "fahrenheit") == 0) {
        to = FAHRENHEIT;
    } else {
        printf("Invalid unit type: %s\n", to_unit);
        return 1;
    }

    // Convert the value
    double converted_value = convert(value, from, to);

    // Print the result
    printf("The converted value is: %lf %s\n", converted_value, to_unit);

    return 0;
}