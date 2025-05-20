//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Unit conversion macros
#define CM_TO_INCH(x) ((x) * 0.393701)
#define INCH_TO_CM(x) ((x) * 2.54)
#define KG_TO_POUND(x) ((x) * 2.20462)
#define POUND_TO_KG(x) ((x) * 0.453592)
#define CELSIUS_TO_FAHRENHEIT(x) ((x) * 1.8 + 32)
#define FAHRENHEIT_TO_CELSIUS(x) ((x) - 32) / 1.8

// Unit types
enum unit_type {
    CM,
    INCH,
    KG,
    POUND,
    CELSIUS,
    FAHRENHEIT
};

// Unit conversion function
double convert_unit(double value, enum unit_type from_unit, enum unit_type to_unit) {
    switch (from_unit) {
        case CM:
            switch (to_unit) {
                case INCH:
                    return CM_TO_INCH(value);
                default:
                    return value;
            }
        case INCH:
            switch (to_unit) {
                case CM:
                    return INCH_TO_CM(value);
                default:
                    return value;
            }
        case KG:
            switch (to_unit) {
                case POUND:
                    return KG_TO_POUND(value);
                default:
                    return value;
            }
        case POUND:
            switch (to_unit) {
                case KG:
                    return POUND_TO_KG(value);
                default:
                    return value;
            }
        case CELSIUS:
            switch (to_unit) {
                case FAHRENHEIT:
                    return CELSIUS_TO_FAHRENHEIT(value);
                default:
                    return value;
            }
        case FAHRENHEIT:
            switch (to_unit) {
                case CELSIUS:
                    return FAHRENHEIT_TO_CELSIUS(value);
                default:
                    return value;
            }
        default:
            return value;
    }
}

// Main function
int main() {
    // Declare variables
    double value;
    enum unit_type from_unit, to_unit;
    char unit_symbol_from[3], unit_symbol_to[3];

    // Get the input
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);
    printf("Enter the unit of the value (cm, inch, kg, pound, celsius, fahrenheit): ");
    scanf("%s", unit_symbol_from);
    printf("Enter the unit to convert to (cm, inch, kg, pound, celsius, fahrenheit): ");
    scanf("%s", unit_symbol_to);

    // Convert the unit symbols to enum values
    from_unit = CM;
    if (strcmp(unit_symbol_from, "inch") == 0) {
        from_unit = INCH;
    } else if (strcmp(unit_symbol_from, "kg") == 0) {
        from_unit = KG;
    } else if (strcmp(unit_symbol_from, "pound") == 0) {
        from_unit = POUND;
    } else if (strcmp(unit_symbol_from, "celsius") == 0) {
        from_unit = CELSIUS;
    } else if (strcmp(unit_symbol_from, "fahrenheit") == 0) {
        from_unit = FAHRENHEIT;
    }

    to_unit = CM;
    if (strcmp(unit_symbol_to, "inch") == 0) {
        to_unit = INCH;
    } else if (strcmp(unit_symbol_to, "kg") == 0) {
        to_unit = KG;
    } else if (strcmp(unit_symbol_to, "pound") == 0) {
        to_unit = POUND;
    } else if (strcmp(unit_symbol_to, "celsius") == 0) {
        to_unit = CELSIUS;
    } else if (strcmp(unit_symbol_to, "fahrenheit") == 0) {
        to_unit = FAHRENHEIT;
    }

    // Convert the value
    double converted_value = convert_unit(value, from_unit, to_unit);

    // Print the result
    printf("The converted value is: %.2f %s\n", converted_value, unit_symbol_to);

    return 0;
}